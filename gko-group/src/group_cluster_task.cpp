/***************************************************************************
 *
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

#include "group_cluster_task.h"

#include <boost/system/error_code.hpp>
#include <libtorrent/torrent_info.hpp>

#include "bbts/BTInfo.hpp"
#include "bbts/host_info_util.h"
#include "bbts/Syms.h"
#include "bbts/log.h"

namespace bbts {
namespace group {

using boost::scoped_array;
using boost::shared_array;
using boost::system::error_code;
using libtorrent::cluster_config_entry;
using libtorrent::torrent_handle;
using libtorrent::torrent_info;

typedef boost::mutex::scoped_lock scoped_lock;

GroupClusterTask::GroupClusterTask(
    const cluster_config_entry &config,
    const torrent_handle &handle,
    int threads_num,
    bool ignore_error)
    : config_(config),
      torrent_(handle),
      threads_num_(threads_num),
      current_start_thread_num_(0),
      complete_threads_num_(0),
      fs_(NULL),
      last_p2p_total_downloaded_(0),
      should_stop_(false),
      retval_(0),
      cluster_total_download_(0),
      start_time_(0),
      ignore_error_(ignore_error),
      is_stoped_(false) {
  // do nothing
}

GroupClusterTask::~GroupClusterTask() {
  if (fs_) {
    if (Syms::drop_cluster_connect_object_(fs_) != 0) {
      WARNING_LOG("drop cluster connect object fail.");
    }
    DEBUG_LOG("drop cluster connect success");
  }
  
  // notify all threads belongs to this task to wake up and quit
  StopDownload();
  DEBUG_LOG("cluster task delete");
}

bool GroupClusterTask::StartDownload() {
  fs_ = Syms::get_cluster_connect_object_(config_.host, config_.port, config_.user, config_.passwd);
  if (fs_ == NULL) {
    FATAL_LOG("Can't connect: hdfs://%s@%s:%d", config_.user.c_str(),
               config_.host.c_str(), config_.port);
    return false;
  }

  NOTICE_LOG("connect cluster success!");
  {
    torrent_info ti(torrent_.info_hash());
    boost::intrusive_ptr<torrent_info const> old_ti = torrent_.torrent_file();
    shared_array<char> metadata_buf = old_ti->metadata();
    int metadata_size = old_ti->metadata_size();
    libtorrent::lazy_entry metadata;
    error_code ec;
    int ret = libtorrent::lazy_bdecode(metadata_buf.get(),
                                       metadata_buf.get() + metadata_size, metadata, ec);
    if (ret != 0 || !ti.parse_info_section(metadata, ec, 0)) {
      WARNING_LOG("parse info section failed.");
      return false;
    }
    btinfo_.reset(new BTInfo(ti, config_.prefix_path));
  }

  int num_pieces = btinfo_->num_pieces();
  pieces_have_.resize(num_pieces, false);
  std::vector<int> piece_priorities = torrent_.piece_priorities();
  for (int i = 0; i < num_pieces; ++i) {
    if (piece_priorities[i] == 0) {
      pieces_have_.set_bit(i);
    }
  }
  pieces_downloading_.resize(num_pieces, false);

  if (num_pieces < threads_num_) {
    threads_num_ = num_pieces;
    if (threads_num_ < 3) {
      threads_num_ = 3;
    }
  }
  start_time_ = time(NULL);

  return true;
}

bool GroupClusterTask::IsStoped() {
  return is_stoped_;
}

void GroupClusterTask::StopDownload() {
  should_stop_ = true;
  cond_.notify_all();
  is_stoped_ = true;
}

void GroupClusterTask::AddThreadToGroup(boost::thread *thread) {
  if (thread != NULL) {
    thread_group_.add_thread(thread);
  }
}

int GroupClusterTask::GetUndownloadedPiece() {
  int num_pieces = btinfo_->num_pieces();
  int start = get_random_num() % num_pieces;
  int piece_index = -1;
  int piece_downloading = -1;
  int i = start % num_pieces;
  do {
    if (pieces_have_[i]) {
      // skip
    } else if (torrent_.have_piece(i)) {
      pieces_have_.set_bit(i);
    } else if (pieces_downloading_[i]){
      piece_downloading = i;
    } else {
      piece_index = i;
    }
    i = (i + 1) % num_pieces;
  } while (piece_index < 0 && i != start);

  if (piece_index < 0 && piece_downloading >= 0) {
    piece_index = piece_downloading;
  }
  return piece_index;
}

int GroupClusterTask::GetPieceToDownload(int last_piece_downloaded, bool &get_from_hash_failed) {
  int piece_index = -1;
  // get a piece from libtorrent not download
  if (!get_from_hash_failed) {
    if (last_piece_downloaded >= 0) {
      pieces_downloading_.clear_bit(last_piece_downloaded);
    }
    piece_index = GetUndownloadedPiece();
    if (piece_index >= 0) {
      pieces_downloading_.set_bit(piece_index);
      DEBUG_LOG("will read piece %d", piece_index);
      return piece_index;
    }
    get_from_hash_failed = true;
  }

  // get a piece from that libtorrent said the piece hash failed
  if (!hash_failed_pieces_.empty()) {
    piece_index = hash_failed_pieces_.front();
    hash_failed_pieces_.pop();
  }
  return piece_index;
}

int GroupClusterTask::current_start_thread_num() {
  scoped_lock lock(mutex_);
  return current_start_thread_num_;
}

void GroupClusterTask::Download() {
  {
    scoped_lock lock(mutex_);
    ++current_start_thread_num_;
    DEBUG_LOG("current_start_thread_num : %d", current_start_thread_num_);
  }

  int retry = 0;
  int piece_index = -1;
  bool get_from_hash_failed = false;
  int download_limit = torrent_.download_limit();
  int64_t downloaded_since_last = 0;
  scoped_array<char> buffer(new char[btinfo_->piece_length()]);
  while (!should_stop_) {
    // check if torrent has paused
    libtorrent::torrent_status ts = torrent_.status(0);
    if (ts.paused) {
      DEBUG_LOG("torrent has paused, sleep and wait next retry");
      sleep(3);
      continue;
    }

    {
      scoped_lock lock(mutex_);
      while ((piece_index = GetPieceToDownload(piece_index, get_from_hash_failed)) < 0 && !should_stop_) {
        cond_.wait(lock);
      }
    }
    if (should_stop_) {
      break;
    }

    std::string errstr;
    int piece_size = btinfo_->piece_size(piece_index);
    if (Syms::read_pieces_from_cluster_(fs_, btinfo_.get(), piece_index, buffer.get(), piece_size, errstr) < 0) {
      WARNING_LOG("%s, retry: %d", errstr.c_str(), retry++);
      if (!ignore_error_) {
        should_stop_ = true;
        retval_ = -1;
        cond_.notify_all();  // failed exit, notify all other thread
        break;
      }
      sleep(15);
      continue;
    }

    {
      scoped_lock lock(mutex_);
      cluster_total_download_ += piece_size;
    }

    libtorrent::hasher piece_hash(buffer.get(), piece_size);
    if (piece_hash.final() != btinfo_->hash_for_piece(piece_index)) {  // hash失败
      WARNING_LOG("hash for piece %d failed, retry: %d.", piece_index, retry++);
      if (!ignore_error_) {
        should_stop_ = true;
        retval_ = -2;
        cond_.notify_all();
        break;
      }
      sleep(15);
      continue;
    }
    torrent_.add_piece(piece_index, buffer.get(), piece_size);
    if (should_stop_) {
      break;
    }

    // speed limit of this cluster task
    download_limit = torrent_.download_limit();
    libtorrent::stat hdfs_stat;
    hdfs_stat.received_bytes(piece_size, 0);
    torrent_.add_stats(hdfs_stat);
    {
      scoped_lock lock(mutex_);
      int64_t p2p_total_downloaded = torrent_.status(0).total_download;
      downloaded_since_last = p2p_total_downloaded - last_p2p_total_downloaded_;
      last_p2p_total_downloaded_ = p2p_total_downloaded;
    }
    download_limit_.BandwidthLimit(downloaded_since_last, download_limit);

    // global session limit
    GroupManager::GetInstance().SessionDownloadLimit();
  }

  {
    scoped_lock lock(mutex_);
    ++complete_threads_num_;
  }
  GroupManager::GetInstance().DeleteClusterThreadNum();
  DEBUG_LOG("cluster downloading thread exit...");
}

} // namespace tool
} // namespace bbts
