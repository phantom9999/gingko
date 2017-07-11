/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "tracker_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace bbts { namespace tracker {

int _kStatusValues[] = {
  Status::METADATA,
  Status::DOWNLOAD,
  Status::SEEDING,
  Status::STOPPED,
  Status::PAUSED
};
const char* _kStatusNames[] = {
  "METADATA",
  "DOWNLOAD",
  "SEEDING",
  "STOPPED",
  "PAUSED"
};
const std::map<int, const char*> _Status_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kStatusValues, _kStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


Peer::~Peer() throw() {
}


void Peer::__set_peerid(const std::string& val) {
  this->peerid = val;
__isset.peerid = true;
}

void Peer::__set_ip(const std::string& val) {
  this->ip = val;
__isset.ip = true;
}

void Peer::__set_port(const int32_t val) {
  this->port = val;
__isset.port = true;
}

void Peer::__set_idc(const std::string& val) {
  this->idc = val;
__isset.idc = true;
}

uint32_t Peer::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->peerid);
          this->__isset.peerid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->idc);
          this->__isset.idc = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Peer::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Peer");

  if (this->__isset.peerid) {
    xfer += oprot->writeFieldBegin("peerid", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->peerid);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.ip) {
    xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->ip);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.port) {
    xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->port);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.idc) {
    xfer += oprot->writeFieldBegin("idc", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->idc);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Peer &a, Peer &b) {
  using ::std::swap;
  swap(a.peerid, b.peerid);
  swap(a.ip, b.ip);
  swap(a.port, b.port);
  swap(a.idc, b.idc);
  swap(a.__isset, b.__isset);
}

Peer::Peer(const Peer& other0) {
  peerid = other0.peerid;
  ip = other0.ip;
  port = other0.port;
  idc = other0.idc;
  __isset = other0.__isset;
}
Peer& Peer::operator=(const Peer& other1) {
  peerid = other1.peerid;
  ip = other1.ip;
  port = other1.port;
  idc = other1.idc;
  __isset = other1.__isset;
  return *this;
}
void Peer::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Peer(";
  out << "peerid="; (__isset.peerid ? (out << to_string(peerid)) : (out << "<null>"));
  out << ", " << "ip="; (__isset.ip ? (out << to_string(ip)) : (out << "<null>"));
  out << ", " << "port="; (__isset.port ? (out << to_string(port)) : (out << "<null>"));
  out << ", " << "idc="; (__isset.idc ? (out << to_string(idc)) : (out << "<null>"));
  out << ")";
}


Stat::~Stat() throw() {
}


void Stat::__set_uploaded(const int64_t val) {
  this->uploaded = val;
__isset.uploaded = true;
}

void Stat::__set_downloaded(const int64_t val) {
  this->downloaded = val;
__isset.downloaded = true;
}

void Stat::__set_left(const int64_t val) {
  this->left = val;
__isset.left = true;
}

void Stat::__set_status(const Status::type val) {
  this->status = val;
__isset.status = true;
}

uint32_t Stat::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->uploaded);
          this->__isset.uploaded = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->downloaded);
          this->__isset.downloaded = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->left);
          this->__isset.left = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast2;
          xfer += iprot->readI32(ecast2);
          this->status = (Status::type)ecast2;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Stat::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Stat");

  if (this->__isset.uploaded) {
    xfer += oprot->writeFieldBegin("uploaded", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->uploaded);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.downloaded) {
    xfer += oprot->writeFieldBegin("downloaded", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->downloaded);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.left) {
    xfer += oprot->writeFieldBegin("left", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->left);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32((int32_t)this->status);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Stat &a, Stat &b) {
  using ::std::swap;
  swap(a.uploaded, b.uploaded);
  swap(a.downloaded, b.downloaded);
  swap(a.left, b.left);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

Stat::Stat(const Stat& other3) {
  uploaded = other3.uploaded;
  downloaded = other3.downloaded;
  left = other3.left;
  status = other3.status;
  __isset = other3.__isset;
}
Stat& Stat::operator=(const Stat& other4) {
  uploaded = other4.uploaded;
  downloaded = other4.downloaded;
  left = other4.left;
  status = other4.status;
  __isset = other4.__isset;
  return *this;
}
void Stat::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Stat(";
  out << "uploaded="; (__isset.uploaded ? (out << to_string(uploaded)) : (out << "<null>"));
  out << ", " << "downloaded="; (__isset.downloaded ? (out << to_string(downloaded)) : (out << "<null>"));
  out << ", " << "left="; (__isset.left ? (out << to_string(left)) : (out << "<null>"));
  out << ", " << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ")";
}


AnnounceRequest::~AnnounceRequest() throw() {
}


void AnnounceRequest::__set_infohash(const std::string& val) {
  this->infohash = val;
__isset.infohash = true;
}

void AnnounceRequest::__set_peer(const Peer& val) {
  this->peer = val;
__isset.peer = true;
}

void AnnounceRequest::__set_stat(const Stat& val) {
  this->stat = val;
__isset.stat = true;
}

void AnnounceRequest::__set_is_seed(const bool val) {
  this->is_seed = val;
__isset.is_seed = true;
}

void AnnounceRequest::__set_num_want(const int32_t val) {
  this->num_want = val;
__isset.num_want = true;
}

uint32_t AnnounceRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->infohash);
          this->__isset.infohash = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->peer.read(iprot);
          this->__isset.peer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->stat.read(iprot);
          this->__isset.stat = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->is_seed);
          this->__isset.is_seed = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->num_want);
          this->__isset.num_want = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnounceRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnounceRequest");

  if (this->__isset.infohash) {
    xfer += oprot->writeFieldBegin("infohash", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->infohash);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.peer) {
    xfer += oprot->writeFieldBegin("peer", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->peer.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.stat) {
    xfer += oprot->writeFieldBegin("stat", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->stat.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.is_seed) {
    xfer += oprot->writeFieldBegin("is_seed", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->is_seed);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.num_want) {
    xfer += oprot->writeFieldBegin("num_want", ::apache::thrift::protocol::T_I32, 5);
    xfer += oprot->writeI32(this->num_want);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnounceRequest &a, AnnounceRequest &b) {
  using ::std::swap;
  swap(a.infohash, b.infohash);
  swap(a.peer, b.peer);
  swap(a.stat, b.stat);
  swap(a.is_seed, b.is_seed);
  swap(a.num_want, b.num_want);
  swap(a.__isset, b.__isset);
}

AnnounceRequest::AnnounceRequest(const AnnounceRequest& other5) {
  infohash = other5.infohash;
  peer = other5.peer;
  stat = other5.stat;
  is_seed = other5.is_seed;
  num_want = other5.num_want;
  __isset = other5.__isset;
}
AnnounceRequest& AnnounceRequest::operator=(const AnnounceRequest& other6) {
  infohash = other6.infohash;
  peer = other6.peer;
  stat = other6.stat;
  is_seed = other6.is_seed;
  num_want = other6.num_want;
  __isset = other6.__isset;
  return *this;
}
void AnnounceRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnounceRequest(";
  out << "infohash="; (__isset.infohash ? (out << to_string(infohash)) : (out << "<null>"));
  out << ", " << "peer="; (__isset.peer ? (out << to_string(peer)) : (out << "<null>"));
  out << ", " << "stat="; (__isset.stat ? (out << to_string(stat)) : (out << "<null>"));
  out << ", " << "is_seed="; (__isset.is_seed ? (out << to_string(is_seed)) : (out << "<null>"));
  out << ", " << "num_want="; (__isset.num_want ? (out << to_string(num_want)) : (out << "<null>"));
  out << ")";
}


AnnounceResponse::~AnnounceResponse() throw() {
}


void AnnounceResponse::__set_ret(const int16_t val) {
  this->ret = val;
__isset.ret = true;
}

void AnnounceResponse::__set_failure_reason(const std::string& val) {
  this->failure_reason = val;
__isset.failure_reason = true;
}

void AnnounceResponse::__set_min_interval(const int32_t val) {
  this->min_interval = val;
__isset.min_interval = true;
}

void AnnounceResponse::__set_have_seed(const bool val) {
  this->have_seed = val;
__isset.have_seed = true;
}

void AnnounceResponse::__set_peers(const std::vector<Peer> & val) {
  this->peers = val;
}

uint32_t AnnounceResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->ret);
          this->__isset.ret = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->failure_reason);
          this->__isset.failure_reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->min_interval);
          this->__isset.min_interval = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->have_seed);
          this->__isset.have_seed = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->peers.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _etype10;
            xfer += iprot->readListBegin(_etype10, _size7);
            this->peers.resize(_size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11)
            {
              xfer += this->peers[_i11].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.peers = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnounceResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnounceResponse");

  if (this->__isset.ret) {
    xfer += oprot->writeFieldBegin("ret", ::apache::thrift::protocol::T_I16, 1);
    xfer += oprot->writeI16(this->ret);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.failure_reason) {
    xfer += oprot->writeFieldBegin("failure_reason", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->failure_reason);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.min_interval) {
    xfer += oprot->writeFieldBegin("min_interval", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->min_interval);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.have_seed) {
    xfer += oprot->writeFieldBegin("have_seed", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->have_seed);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("peers", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->peers.size()));
    std::vector<Peer> ::const_iterator _iter12;
    for (_iter12 = this->peers.begin(); _iter12 != this->peers.end(); ++_iter12)
    {
      xfer += (*_iter12).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnounceResponse &a, AnnounceResponse &b) {
  using ::std::swap;
  swap(a.ret, b.ret);
  swap(a.failure_reason, b.failure_reason);
  swap(a.min_interval, b.min_interval);
  swap(a.have_seed, b.have_seed);
  swap(a.peers, b.peers);
  swap(a.__isset, b.__isset);
}

AnnounceResponse::AnnounceResponse(const AnnounceResponse& other13) {
  ret = other13.ret;
  failure_reason = other13.failure_reason;
  min_interval = other13.min_interval;
  have_seed = other13.have_seed;
  peers = other13.peers;
  __isset = other13.__isset;
}
AnnounceResponse& AnnounceResponse::operator=(const AnnounceResponse& other14) {
  ret = other14.ret;
  failure_reason = other14.failure_reason;
  min_interval = other14.min_interval;
  have_seed = other14.have_seed;
  peers = other14.peers;
  __isset = other14.__isset;
  return *this;
}
void AnnounceResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnounceResponse(";
  out << "ret="; (__isset.ret ? (out << to_string(ret)) : (out << "<null>"));
  out << ", " << "failure_reason="; (__isset.failure_reason ? (out << to_string(failure_reason)) : (out << "<null>"));
  out << ", " << "min_interval="; (__isset.min_interval ? (out << to_string(min_interval)) : (out << "<null>"));
  out << ", " << "have_seed="; (__isset.have_seed ? (out << to_string(have_seed)) : (out << "<null>"));
  out << ", " << "peers=" << to_string(peers);
  out << ")";
}


ControlByInfohashRequest::~ControlByInfohashRequest() throw() {
}


void ControlByInfohashRequest::__set_ip(const std::string& val) {
  this->ip = val;
__isset.ip = true;
}

void ControlByInfohashRequest::__set_token(const std::string& val) {
  this->token = val;
__isset.token = true;
}

void ControlByInfohashRequest::__set_infohash(const std::string& val) {
  this->infohash = val;
__isset.infohash = true;
}

uint32_t ControlByInfohashRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->token);
          this->__isset.token = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->infohash);
          this->__isset.infohash = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ControlByInfohashRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ControlByInfohashRequest");

  if (this->__isset.ip) {
    xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->ip);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.token) {
    xfer += oprot->writeFieldBegin("token", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->token);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.infohash) {
    xfer += oprot->writeFieldBegin("infohash", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->infohash);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ControlByInfohashRequest &a, ControlByInfohashRequest &b) {
  using ::std::swap;
  swap(a.ip, b.ip);
  swap(a.token, b.token);
  swap(a.infohash, b.infohash);
  swap(a.__isset, b.__isset);
}

ControlByInfohashRequest::ControlByInfohashRequest(const ControlByInfohashRequest& other15) {
  ip = other15.ip;
  token = other15.token;
  infohash = other15.infohash;
  __isset = other15.__isset;
}
ControlByInfohashRequest& ControlByInfohashRequest::operator=(const ControlByInfohashRequest& other16) {
  ip = other16.ip;
  token = other16.token;
  infohash = other16.infohash;
  __isset = other16.__isset;
  return *this;
}
void ControlByInfohashRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ControlByInfohashRequest(";
  out << "ip="; (__isset.ip ? (out << to_string(ip)) : (out << "<null>"));
  out << ", " << "token="; (__isset.token ? (out << to_string(token)) : (out << "<null>"));
  out << ", " << "infohash="; (__isset.infohash ? (out << to_string(infohash)) : (out << "<null>"));
  out << ")";
}


BaseResponse::~BaseResponse() throw() {
}


void BaseResponse::__set_retval(const int16_t val) {
  this->retval = val;
__isset.retval = true;
}

void BaseResponse::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

uint32_t BaseResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->retval);
          this->__isset.retval = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BaseResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("BaseResponse");

  if (this->__isset.retval) {
    xfer += oprot->writeFieldBegin("retval", ::apache::thrift::protocol::T_I16, 1);
    xfer += oprot->writeI16(this->retval);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BaseResponse &a, BaseResponse &b) {
  using ::std::swap;
  swap(a.retval, b.retval);
  swap(a.message, b.message);
  swap(a.__isset, b.__isset);
}

BaseResponse::BaseResponse(const BaseResponse& other17) {
  retval = other17.retval;
  message = other17.message;
  __isset = other17.__isset;
}
BaseResponse& BaseResponse::operator=(const BaseResponse& other18) {
  retval = other18.retval;
  message = other18.message;
  __isset = other18.__isset;
  return *this;
}
void BaseResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "BaseResponse(";
  out << "retval="; (__isset.retval ? (out << to_string(retval)) : (out << "<null>"));
  out << ", " << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ")";
}

}} // namespace
