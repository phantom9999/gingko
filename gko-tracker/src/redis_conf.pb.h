// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: redis_conf.proto

#ifndef PROTOBUF_redis_5fconf_2eproto__INCLUDED
#define PROTOBUF_redis_5fconf_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace bbts {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_redis_5fconf_2eproto();
void protobuf_InitDefaults_redis_5fconf_2eproto();
void protobuf_AssignDesc_redis_5fconf_2eproto();
void protobuf_ShutdownFile_redis_5fconf_2eproto();

class HostPair;
class RedisConf;

// ===================================================================

class HostPair : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:bbts.HostPair) */ {
 public:
  HostPair();
  virtual ~HostPair();

  HostPair(const HostPair& from);

  inline HostPair& operator=(const HostPair& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HostPair& default_instance();

  static const HostPair* internal_default_instance();

  void Swap(HostPair* other);

  // implements Message ----------------------------------------------

  inline HostPair* New() const { return New(NULL); }

  HostPair* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HostPair& from);
  void MergeFrom(const HostPair& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HostPair* other);
  void UnsafeMergeFrom(const HostPair& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string master_hostname = 1;
  bool has_master_hostname() const;
  void clear_master_hostname();
  static const int kMasterHostnameFieldNumber = 1;
  const ::std::string& master_hostname() const;
  void set_master_hostname(const ::std::string& value);
  void set_master_hostname(const char* value);
  void set_master_hostname(const char* value, size_t size);
  ::std::string* mutable_master_hostname();
  ::std::string* release_master_hostname();
  void set_allocated_master_hostname(::std::string* master_hostname);

  // optional int32 master_port = 2;
  bool has_master_port() const;
  void clear_master_port();
  static const int kMasterPortFieldNumber = 2;
  ::google::protobuf::int32 master_port() const;
  void set_master_port(::google::protobuf::int32 value);

  // optional int32 master_weight = 3;
  bool has_master_weight() const;
  void clear_master_weight();
  static const int kMasterWeightFieldNumber = 3;
  ::google::protobuf::int32 master_weight() const;
  void set_master_weight(::google::protobuf::int32 value);

  // optional string slave_hostname = 4;
  bool has_slave_hostname() const;
  void clear_slave_hostname();
  static const int kSlaveHostnameFieldNumber = 4;
  const ::std::string& slave_hostname() const;
  void set_slave_hostname(const ::std::string& value);
  void set_slave_hostname(const char* value);
  void set_slave_hostname(const char* value, size_t size);
  ::std::string* mutable_slave_hostname();
  ::std::string* release_slave_hostname();
  void set_allocated_slave_hostname(::std::string* slave_hostname);

  // optional int32 slave_port = 5;
  bool has_slave_port() const;
  void clear_slave_port();
  static const int kSlavePortFieldNumber = 5;
  ::google::protobuf::int32 slave_port() const;
  void set_slave_port(::google::protobuf::int32 value);

  // optional int32 slave_weight = 6;
  bool has_slave_weight() const;
  void clear_slave_weight();
  static const int kSlaveWeightFieldNumber = 6;
  ::google::protobuf::int32 slave_weight() const;
  void set_slave_weight(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:bbts.HostPair)
 private:
  inline void set_has_master_hostname();
  inline void clear_has_master_hostname();
  inline void set_has_master_port();
  inline void clear_has_master_port();
  inline void set_has_master_weight();
  inline void clear_has_master_weight();
  inline void set_has_slave_hostname();
  inline void clear_has_slave_hostname();
  inline void set_has_slave_port();
  inline void clear_has_slave_port();
  inline void set_has_slave_weight();
  inline void clear_has_slave_weight();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr master_hostname_;
  ::google::protobuf::internal::ArenaStringPtr slave_hostname_;
  ::google::protobuf::int32 master_port_;
  ::google::protobuf::int32 master_weight_;
  ::google::protobuf::int32 slave_port_;
  ::google::protobuf::int32 slave_weight_;
  friend void  protobuf_InitDefaults_redis_5fconf_2eproto_impl();
  friend void  protobuf_AddDesc_redis_5fconf_2eproto_impl();
  friend void protobuf_AssignDesc_redis_5fconf_2eproto();
  friend void protobuf_ShutdownFile_redis_5fconf_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<HostPair> HostPair_default_instance_;

// -------------------------------------------------------------------

class RedisConf : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:bbts.RedisConf) */ {
 public:
  RedisConf();
  virtual ~RedisConf();

  RedisConf(const RedisConf& from);

  inline RedisConf& operator=(const RedisConf& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RedisConf& default_instance();

  static const RedisConf* internal_default_instance();

  void Swap(RedisConf* other);

  // implements Message ----------------------------------------------

  inline RedisConf* New() const { return New(NULL); }

  RedisConf* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RedisConf& from);
  void MergeFrom(const RedisConf& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(RedisConf* other);
  void UnsafeMergeFrom(const RedisConf& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 max_queue_length = 1;
  bool has_max_queue_length() const;
  void clear_max_queue_length();
  static const int kMaxQueueLengthFieldNumber = 1;
  ::google::protobuf::int32 max_queue_length() const;
  void set_max_queue_length(::google::protobuf::int32 value);

  // optional int32 timeout = 2;
  bool has_timeout() const;
  void clear_timeout();
  static const int kTimeoutFieldNumber = 2;
  ::google::protobuf::int32 timeout() const;
  void set_timeout(::google::protobuf::int32 value);

  // optional string passwd = 3;
  bool has_passwd() const;
  void clear_passwd();
  static const int kPasswdFieldNumber = 3;
  const ::std::string& passwd() const;
  void set_passwd(const ::std::string& value);
  void set_passwd(const char* value);
  void set_passwd(const char* value, size_t size);
  ::std::string* mutable_passwd();
  ::std::string* release_passwd();
  void set_allocated_passwd(::std::string* passwd);

  // optional string database = 4;
  bool has_database() const;
  void clear_database();
  static const int kDatabaseFieldNumber = 4;
  const ::std::string& database() const;
  void set_database(const ::std::string& value);
  void set_database(const char* value);
  void set_database(const char* value, size_t size);
  ::std::string* mutable_database();
  ::std::string* release_database();
  void set_allocated_database(::std::string* database);

  // repeated .bbts.HostPair host_pair = 5;
  int host_pair_size() const;
  void clear_host_pair();
  static const int kHostPairFieldNumber = 5;
  const ::bbts::HostPair& host_pair(int index) const;
  ::bbts::HostPair* mutable_host_pair(int index);
  ::bbts::HostPair* add_host_pair();
  ::google::protobuf::RepeatedPtrField< ::bbts::HostPair >*
      mutable_host_pair();
  const ::google::protobuf::RepeatedPtrField< ::bbts::HostPair >&
      host_pair() const;

  // @@protoc_insertion_point(class_scope:bbts.RedisConf)
 private:
  inline void set_has_max_queue_length();
  inline void clear_has_max_queue_length();
  inline void set_has_timeout();
  inline void clear_has_timeout();
  inline void set_has_passwd();
  inline void clear_has_passwd();
  inline void set_has_database();
  inline void clear_has_database();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::bbts::HostPair > host_pair_;
  ::google::protobuf::internal::ArenaStringPtr passwd_;
  ::google::protobuf::internal::ArenaStringPtr database_;
  ::google::protobuf::int32 max_queue_length_;
  ::google::protobuf::int32 timeout_;
  friend void  protobuf_InitDefaults_redis_5fconf_2eproto_impl();
  friend void  protobuf_AddDesc_redis_5fconf_2eproto_impl();
  friend void protobuf_AssignDesc_redis_5fconf_2eproto();
  friend void protobuf_ShutdownFile_redis_5fconf_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<RedisConf> RedisConf_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// HostPair

// optional string master_hostname = 1;
inline bool HostPair::has_master_hostname() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void HostPair::set_has_master_hostname() {
  _has_bits_[0] |= 0x00000001u;
}
inline void HostPair::clear_has_master_hostname() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void HostPair::clear_master_hostname() {
  master_hostname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_master_hostname();
}
inline const ::std::string& HostPair::master_hostname() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.master_hostname)
  return master_hostname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostPair::set_master_hostname(const ::std::string& value) {
  set_has_master_hostname();
  master_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:bbts.HostPair.master_hostname)
}
inline void HostPair::set_master_hostname(const char* value) {
  set_has_master_hostname();
  master_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bbts.HostPair.master_hostname)
}
inline void HostPair::set_master_hostname(const char* value, size_t size) {
  set_has_master_hostname();
  master_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bbts.HostPair.master_hostname)
}
inline ::std::string* HostPair::mutable_master_hostname() {
  set_has_master_hostname();
  // @@protoc_insertion_point(field_mutable:bbts.HostPair.master_hostname)
  return master_hostname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HostPair::release_master_hostname() {
  // @@protoc_insertion_point(field_release:bbts.HostPair.master_hostname)
  clear_has_master_hostname();
  return master_hostname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostPair::set_allocated_master_hostname(::std::string* master_hostname) {
  if (master_hostname != NULL) {
    set_has_master_hostname();
  } else {
    clear_has_master_hostname();
  }
  master_hostname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), master_hostname);
  // @@protoc_insertion_point(field_set_allocated:bbts.HostPair.master_hostname)
}

// optional int32 master_port = 2;
inline bool HostPair::has_master_port() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void HostPair::set_has_master_port() {
  _has_bits_[0] |= 0x00000002u;
}
inline void HostPair::clear_has_master_port() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void HostPair::clear_master_port() {
  master_port_ = 0;
  clear_has_master_port();
}
inline ::google::protobuf::int32 HostPair::master_port() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.master_port)
  return master_port_;
}
inline void HostPair::set_master_port(::google::protobuf::int32 value) {
  set_has_master_port();
  master_port_ = value;
  // @@protoc_insertion_point(field_set:bbts.HostPair.master_port)
}

// optional int32 master_weight = 3;
inline bool HostPair::has_master_weight() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void HostPair::set_has_master_weight() {
  _has_bits_[0] |= 0x00000004u;
}
inline void HostPair::clear_has_master_weight() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void HostPair::clear_master_weight() {
  master_weight_ = 0;
  clear_has_master_weight();
}
inline ::google::protobuf::int32 HostPair::master_weight() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.master_weight)
  return master_weight_;
}
inline void HostPair::set_master_weight(::google::protobuf::int32 value) {
  set_has_master_weight();
  master_weight_ = value;
  // @@protoc_insertion_point(field_set:bbts.HostPair.master_weight)
}

// optional string slave_hostname = 4;
inline bool HostPair::has_slave_hostname() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void HostPair::set_has_slave_hostname() {
  _has_bits_[0] |= 0x00000008u;
}
inline void HostPair::clear_has_slave_hostname() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void HostPair::clear_slave_hostname() {
  slave_hostname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_slave_hostname();
}
inline const ::std::string& HostPair::slave_hostname() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.slave_hostname)
  return slave_hostname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostPair::set_slave_hostname(const ::std::string& value) {
  set_has_slave_hostname();
  slave_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:bbts.HostPair.slave_hostname)
}
inline void HostPair::set_slave_hostname(const char* value) {
  set_has_slave_hostname();
  slave_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bbts.HostPair.slave_hostname)
}
inline void HostPair::set_slave_hostname(const char* value, size_t size) {
  set_has_slave_hostname();
  slave_hostname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bbts.HostPair.slave_hostname)
}
inline ::std::string* HostPair::mutable_slave_hostname() {
  set_has_slave_hostname();
  // @@protoc_insertion_point(field_mutable:bbts.HostPair.slave_hostname)
  return slave_hostname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HostPair::release_slave_hostname() {
  // @@protoc_insertion_point(field_release:bbts.HostPair.slave_hostname)
  clear_has_slave_hostname();
  return slave_hostname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HostPair::set_allocated_slave_hostname(::std::string* slave_hostname) {
  if (slave_hostname != NULL) {
    set_has_slave_hostname();
  } else {
    clear_has_slave_hostname();
  }
  slave_hostname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), slave_hostname);
  // @@protoc_insertion_point(field_set_allocated:bbts.HostPair.slave_hostname)
}

// optional int32 slave_port = 5;
inline bool HostPair::has_slave_port() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void HostPair::set_has_slave_port() {
  _has_bits_[0] |= 0x00000010u;
}
inline void HostPair::clear_has_slave_port() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void HostPair::clear_slave_port() {
  slave_port_ = 0;
  clear_has_slave_port();
}
inline ::google::protobuf::int32 HostPair::slave_port() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.slave_port)
  return slave_port_;
}
inline void HostPair::set_slave_port(::google::protobuf::int32 value) {
  set_has_slave_port();
  slave_port_ = value;
  // @@protoc_insertion_point(field_set:bbts.HostPair.slave_port)
}

// optional int32 slave_weight = 6;
inline bool HostPair::has_slave_weight() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void HostPair::set_has_slave_weight() {
  _has_bits_[0] |= 0x00000020u;
}
inline void HostPair::clear_has_slave_weight() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void HostPair::clear_slave_weight() {
  slave_weight_ = 0;
  clear_has_slave_weight();
}
inline ::google::protobuf::int32 HostPair::slave_weight() const {
  // @@protoc_insertion_point(field_get:bbts.HostPair.slave_weight)
  return slave_weight_;
}
inline void HostPair::set_slave_weight(::google::protobuf::int32 value) {
  set_has_slave_weight();
  slave_weight_ = value;
  // @@protoc_insertion_point(field_set:bbts.HostPair.slave_weight)
}

inline const HostPair* HostPair::internal_default_instance() {
  return &HostPair_default_instance_.get();
}
// -------------------------------------------------------------------

// RedisConf

// optional int32 max_queue_length = 1;
inline bool RedisConf::has_max_queue_length() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RedisConf::set_has_max_queue_length() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RedisConf::clear_has_max_queue_length() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RedisConf::clear_max_queue_length() {
  max_queue_length_ = 0;
  clear_has_max_queue_length();
}
inline ::google::protobuf::int32 RedisConf::max_queue_length() const {
  // @@protoc_insertion_point(field_get:bbts.RedisConf.max_queue_length)
  return max_queue_length_;
}
inline void RedisConf::set_max_queue_length(::google::protobuf::int32 value) {
  set_has_max_queue_length();
  max_queue_length_ = value;
  // @@protoc_insertion_point(field_set:bbts.RedisConf.max_queue_length)
}

// optional int32 timeout = 2;
inline bool RedisConf::has_timeout() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RedisConf::set_has_timeout() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RedisConf::clear_has_timeout() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RedisConf::clear_timeout() {
  timeout_ = 0;
  clear_has_timeout();
}
inline ::google::protobuf::int32 RedisConf::timeout() const {
  // @@protoc_insertion_point(field_get:bbts.RedisConf.timeout)
  return timeout_;
}
inline void RedisConf::set_timeout(::google::protobuf::int32 value) {
  set_has_timeout();
  timeout_ = value;
  // @@protoc_insertion_point(field_set:bbts.RedisConf.timeout)
}

// optional string passwd = 3;
inline bool RedisConf::has_passwd() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RedisConf::set_has_passwd() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RedisConf::clear_has_passwd() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RedisConf::clear_passwd() {
  passwd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_passwd();
}
inline const ::std::string& RedisConf::passwd() const {
  // @@protoc_insertion_point(field_get:bbts.RedisConf.passwd)
  return passwd_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RedisConf::set_passwd(const ::std::string& value) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:bbts.RedisConf.passwd)
}
inline void RedisConf::set_passwd(const char* value) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bbts.RedisConf.passwd)
}
inline void RedisConf::set_passwd(const char* value, size_t size) {
  set_has_passwd();
  passwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bbts.RedisConf.passwd)
}
inline ::std::string* RedisConf::mutable_passwd() {
  set_has_passwd();
  // @@protoc_insertion_point(field_mutable:bbts.RedisConf.passwd)
  return passwd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RedisConf::release_passwd() {
  // @@protoc_insertion_point(field_release:bbts.RedisConf.passwd)
  clear_has_passwd();
  return passwd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RedisConf::set_allocated_passwd(::std::string* passwd) {
  if (passwd != NULL) {
    set_has_passwd();
  } else {
    clear_has_passwd();
  }
  passwd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), passwd);
  // @@protoc_insertion_point(field_set_allocated:bbts.RedisConf.passwd)
}

// optional string database = 4;
inline bool RedisConf::has_database() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RedisConf::set_has_database() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RedisConf::clear_has_database() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RedisConf::clear_database() {
  database_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_database();
}
inline const ::std::string& RedisConf::database() const {
  // @@protoc_insertion_point(field_get:bbts.RedisConf.database)
  return database_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RedisConf::set_database(const ::std::string& value) {
  set_has_database();
  database_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:bbts.RedisConf.database)
}
inline void RedisConf::set_database(const char* value) {
  set_has_database();
  database_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:bbts.RedisConf.database)
}
inline void RedisConf::set_database(const char* value, size_t size) {
  set_has_database();
  database_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:bbts.RedisConf.database)
}
inline ::std::string* RedisConf::mutable_database() {
  set_has_database();
  // @@protoc_insertion_point(field_mutable:bbts.RedisConf.database)
  return database_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RedisConf::release_database() {
  // @@protoc_insertion_point(field_release:bbts.RedisConf.database)
  clear_has_database();
  return database_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RedisConf::set_allocated_database(::std::string* database) {
  if (database != NULL) {
    set_has_database();
  } else {
    clear_has_database();
  }
  database_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), database);
  // @@protoc_insertion_point(field_set_allocated:bbts.RedisConf.database)
}

// repeated .bbts.HostPair host_pair = 5;
inline int RedisConf::host_pair_size() const {
  return host_pair_.size();
}
inline void RedisConf::clear_host_pair() {
  host_pair_.Clear();
}
inline const ::bbts::HostPair& RedisConf::host_pair(int index) const {
  // @@protoc_insertion_point(field_get:bbts.RedisConf.host_pair)
  return host_pair_.Get(index);
}
inline ::bbts::HostPair* RedisConf::mutable_host_pair(int index) {
  // @@protoc_insertion_point(field_mutable:bbts.RedisConf.host_pair)
  return host_pair_.Mutable(index);
}
inline ::bbts::HostPair* RedisConf::add_host_pair() {
  // @@protoc_insertion_point(field_add:bbts.RedisConf.host_pair)
  return host_pair_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::bbts::HostPair >*
RedisConf::mutable_host_pair() {
  // @@protoc_insertion_point(field_mutable_list:bbts.RedisConf.host_pair)
  return &host_pair_;
}
inline const ::google::protobuf::RepeatedPtrField< ::bbts::HostPair >&
RedisConf::host_pair() const {
  // @@protoc_insertion_point(field_list:bbts.RedisConf.host_pair)
  return host_pair_;
}

inline const RedisConf* RedisConf::internal_default_instance() {
  return &RedisConf_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace bbts

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_redis_5fconf_2eproto__INCLUDED
