// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mbus.proto

#ifndef PROTOBUF_mbus_2eproto__INCLUDED
#define PROTOBUF_mbus_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)

namespace managarm {
namespace mbus {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_mbus_2eproto();
void protobuf_AssignDesc_mbus_2eproto();
void protobuf_ShutdownFile_mbus_2eproto();

class Capability;
class Interface;
class CntRequest;
class SvrResponse;
class SvrRequest;
class CntResponse;

enum CntReqType {
  REGISTER = 1,
  QUERY_IF = 2
};
bool CntReqType_IsValid(int value);
const CntReqType CntReqType_MIN = REGISTER;
const CntReqType CntReqType_MAX = QUERY_IF;
const int CntReqType_ARRAYSIZE = CntReqType_MAX + 1;

enum SvrReqType {
  BROADCAST = 1,
  REQUIRE_IF = 2
};
bool SvrReqType_IsValid(int value);
const SvrReqType SvrReqType_MIN = BROADCAST;
const SvrReqType SvrReqType_MAX = REQUIRE_IF;
const int SvrReqType_ARRAYSIZE = SvrReqType_MAX + 1;

// ===================================================================

class Capability : public ::google::protobuf::MessageLite {
 public:
  Capability();
  virtual ~Capability();

  Capability(const Capability& from);

  inline Capability& operator=(const Capability& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const Capability& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Capability* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Capability* other);

  // implements Message ----------------------------------------------

  inline Capability* New() const { return New(NULL); }

  Capability* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Capability& from);
  void MergeFrom(const Capability& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Capability* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:managarm.mbus.Capability)
 private:
  inline void set_has_name();
  inline void clear_has_name();

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static Capability* default_instance_;
};
// -------------------------------------------------------------------

class Interface : public ::google::protobuf::MessageLite {
 public:
  Interface();
  virtual ~Interface();

  Interface(const Interface& from);

  inline Interface& operator=(const Interface& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const Interface& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Interface* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Interface* other);

  // implements Message ----------------------------------------------

  inline Interface* New() const { return New(NULL); }

  Interface* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Interface& from);
  void MergeFrom(const Interface& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Interface* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:managarm.mbus.Interface)
 private:
  inline void set_has_name();
  inline void clear_has_name();

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static Interface* default_instance_;
};
// -------------------------------------------------------------------

class CntRequest : public ::google::protobuf::MessageLite {
 public:
  CntRequest();
  virtual ~CntRequest();

  CntRequest(const CntRequest& from);

  inline CntRequest& operator=(const CntRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const CntRequest& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CntRequest* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(CntRequest* other);

  // implements Message ----------------------------------------------

  inline CntRequest* New() const { return New(NULL); }

  CntRequest* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CntRequest& from);
  void MergeFrom(const CntRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CntRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .managarm.mbus.CntReqType req_type = 1;
  bool has_req_type() const;
  void clear_req_type();
  static const int kReqTypeFieldNumber = 1;
  ::managarm::mbus::CntReqType req_type() const;
  void set_req_type(::managarm::mbus::CntReqType value);

  // repeated .managarm.mbus.Capability caps = 2;
  int caps_size() const;
  void clear_caps();
  static const int kCapsFieldNumber = 2;
  const ::managarm::mbus::Capability& caps(int index) const;
  ::managarm::mbus::Capability* mutable_caps(int index);
  ::managarm::mbus::Capability* add_caps();
  const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >&
      caps() const;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >*
      mutable_caps();

  // repeated .managarm.mbus.Interface ifs = 3;
  int ifs_size() const;
  void clear_ifs();
  static const int kIfsFieldNumber = 3;
  const ::managarm::mbus::Interface& ifs(int index) const;
  ::managarm::mbus::Interface* mutable_ifs(int index);
  ::managarm::mbus::Interface* add_ifs();
  const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >&
      ifs() const;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >*
      mutable_ifs();

  // optional int64 object_id = 4;
  bool has_object_id() const;
  void clear_object_id();
  static const int kObjectIdFieldNumber = 4;
  ::google::protobuf::int64 object_id() const;
  void set_object_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:managarm.mbus.CntRequest)
 private:
  inline void set_has_req_type();
  inline void clear_has_req_type();
  inline void set_has_object_id();
  inline void clear_has_object_id();

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability > caps_;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface > ifs_;
  ::google::protobuf::int64 object_id_;
  int req_type_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static CntRequest* default_instance_;
};
// -------------------------------------------------------------------

class SvrResponse : public ::google::protobuf::MessageLite {
 public:
  SvrResponse();
  virtual ~SvrResponse();

  SvrResponse(const SvrResponse& from);

  inline SvrResponse& operator=(const SvrResponse& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const SvrResponse& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SvrResponse* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(SvrResponse* other);

  // implements Message ----------------------------------------------

  inline SvrResponse* New() const { return New(NULL); }

  SvrResponse* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SvrResponse& from);
  void MergeFrom(const SvrResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SvrResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 object_id = 1;
  bool has_object_id() const;
  void clear_object_id();
  static const int kObjectIdFieldNumber = 1;
  ::google::protobuf::int64 object_id() const;
  void set_object_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:managarm.mbus.SvrResponse)
 private:
  inline void set_has_object_id();
  inline void clear_has_object_id();

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 object_id_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static SvrResponse* default_instance_;
};
// -------------------------------------------------------------------

class SvrRequest : public ::google::protobuf::MessageLite {
 public:
  SvrRequest();
  virtual ~SvrRequest();

  SvrRequest(const SvrRequest& from);

  inline SvrRequest& operator=(const SvrRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const SvrRequest& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SvrRequest* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(SvrRequest* other);

  // implements Message ----------------------------------------------

  inline SvrRequest* New() const { return New(NULL); }

  SvrRequest* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SvrRequest& from);
  void MergeFrom(const SvrRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SvrRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .managarm.mbus.SvrReqType req_type = 1;
  bool has_req_type() const;
  void clear_req_type();
  static const int kReqTypeFieldNumber = 1;
  ::managarm::mbus::SvrReqType req_type() const;
  void set_req_type(::managarm::mbus::SvrReqType value);

  // optional int64 object_id = 2;
  bool has_object_id() const;
  void clear_object_id();
  static const int kObjectIdFieldNumber = 2;
  ::google::protobuf::int64 object_id() const;
  void set_object_id(::google::protobuf::int64 value);

  // repeated .managarm.mbus.Capability caps = 3;
  int caps_size() const;
  void clear_caps();
  static const int kCapsFieldNumber = 3;
  const ::managarm::mbus::Capability& caps(int index) const;
  ::managarm::mbus::Capability* mutable_caps(int index);
  ::managarm::mbus::Capability* add_caps();
  const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >&
      caps() const;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >*
      mutable_caps();

  // repeated .managarm.mbus.Interface ifs = 4;
  int ifs_size() const;
  void clear_ifs();
  static const int kIfsFieldNumber = 4;
  const ::managarm::mbus::Interface& ifs(int index) const;
  ::managarm::mbus::Interface* mutable_ifs(int index);
  ::managarm::mbus::Interface* add_ifs();
  const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >&
      ifs() const;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >*
      mutable_ifs();

  // @@protoc_insertion_point(class_scope:managarm.mbus.SvrRequest)
 private:
  inline void set_has_req_type();
  inline void clear_has_req_type();
  inline void set_has_object_id();
  inline void clear_has_object_id();

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 object_id_;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability > caps_;
  ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface > ifs_;
  int req_type_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static SvrRequest* default_instance_;
};
// -------------------------------------------------------------------

class CntResponse : public ::google::protobuf::MessageLite {
 public:
  CntResponse();
  virtual ~CntResponse();

  CntResponse(const CntResponse& from);

  inline CntResponse& operator=(const CntResponse& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const CntResponse& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CntResponse* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(CntResponse* other);

  // implements Message ----------------------------------------------

  inline CntResponse* New() const { return New(NULL); }

  CntResponse* New(::google::protobuf::Arena* arena) const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CntResponse& from);
  void MergeFrom(const CntResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CntResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _arena_ptr_;
  }
  inline ::google::protobuf::Arena* MaybeArenaPtr() const {
    return _arena_ptr_;
  }
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:managarm.mbus.CntResponse)
 private:

  ::std::string _unknown_fields_;
  ::google::protobuf::Arena* _arena_ptr_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mbus_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mbus_2eproto();
  #endif
  friend void protobuf_AssignDesc_mbus_2eproto();
  friend void protobuf_ShutdownFile_mbus_2eproto();

  void InitAsDefaultInstance();
  static CntResponse* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Capability

// optional string name = 1;
inline bool Capability::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Capability::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Capability::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Capability::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Capability::name() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.Capability.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Capability::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:managarm.mbus.Capability.name)
}
inline void Capability::set_name(const char* value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:managarm.mbus.Capability.name)
}
inline void Capability::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:managarm.mbus.Capability.name)
}
inline ::std::string* Capability::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:managarm.mbus.Capability.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Capability::release_name() {
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Capability::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:managarm.mbus.Capability.name)
}

// -------------------------------------------------------------------

// Interface

// optional string name = 1;
inline bool Interface::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Interface::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Interface::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Interface::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Interface::name() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.Interface.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Interface::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:managarm.mbus.Interface.name)
}
inline void Interface::set_name(const char* value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:managarm.mbus.Interface.name)
}
inline void Interface::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:managarm.mbus.Interface.name)
}
inline ::std::string* Interface::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:managarm.mbus.Interface.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Interface::release_name() {
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Interface::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:managarm.mbus.Interface.name)
}

// -------------------------------------------------------------------

// CntRequest

// optional .managarm.mbus.CntReqType req_type = 1;
inline bool CntRequest::has_req_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CntRequest::set_has_req_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CntRequest::clear_has_req_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CntRequest::clear_req_type() {
  req_type_ = 1;
  clear_has_req_type();
}
inline ::managarm::mbus::CntReqType CntRequest::req_type() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.CntRequest.req_type)
  return static_cast< ::managarm::mbus::CntReqType >(req_type_);
}
inline void CntRequest::set_req_type(::managarm::mbus::CntReqType value) {
  assert(::managarm::mbus::CntReqType_IsValid(value));
  set_has_req_type();
  req_type_ = value;
  // @@protoc_insertion_point(field_set:managarm.mbus.CntRequest.req_type)
}

// repeated .managarm.mbus.Capability caps = 2;
inline int CntRequest::caps_size() const {
  return caps_.size();
}
inline void CntRequest::clear_caps() {
  caps_.Clear();
}
inline const ::managarm::mbus::Capability& CntRequest::caps(int index) const {
  // @@protoc_insertion_point(field_get:managarm.mbus.CntRequest.caps)
  return caps_.Get(index);
}
inline ::managarm::mbus::Capability* CntRequest::mutable_caps(int index) {
  // @@protoc_insertion_point(field_mutable:managarm.mbus.CntRequest.caps)
  return caps_.Mutable(index);
}
inline ::managarm::mbus::Capability* CntRequest::add_caps() {
  // @@protoc_insertion_point(field_add:managarm.mbus.CntRequest.caps)
  return caps_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >&
CntRequest::caps() const {
  // @@protoc_insertion_point(field_list:managarm.mbus.CntRequest.caps)
  return caps_;
}
inline ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >*
CntRequest::mutable_caps() {
  // @@protoc_insertion_point(field_mutable_list:managarm.mbus.CntRequest.caps)
  return &caps_;
}

// repeated .managarm.mbus.Interface ifs = 3;
inline int CntRequest::ifs_size() const {
  return ifs_.size();
}
inline void CntRequest::clear_ifs() {
  ifs_.Clear();
}
inline const ::managarm::mbus::Interface& CntRequest::ifs(int index) const {
  // @@protoc_insertion_point(field_get:managarm.mbus.CntRequest.ifs)
  return ifs_.Get(index);
}
inline ::managarm::mbus::Interface* CntRequest::mutable_ifs(int index) {
  // @@protoc_insertion_point(field_mutable:managarm.mbus.CntRequest.ifs)
  return ifs_.Mutable(index);
}
inline ::managarm::mbus::Interface* CntRequest::add_ifs() {
  // @@protoc_insertion_point(field_add:managarm.mbus.CntRequest.ifs)
  return ifs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >&
CntRequest::ifs() const {
  // @@protoc_insertion_point(field_list:managarm.mbus.CntRequest.ifs)
  return ifs_;
}
inline ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >*
CntRequest::mutable_ifs() {
  // @@protoc_insertion_point(field_mutable_list:managarm.mbus.CntRequest.ifs)
  return &ifs_;
}

// optional int64 object_id = 4;
inline bool CntRequest::has_object_id() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CntRequest::set_has_object_id() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CntRequest::clear_has_object_id() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CntRequest::clear_object_id() {
  object_id_ = GOOGLE_LONGLONG(0);
  clear_has_object_id();
}
inline ::google::protobuf::int64 CntRequest::object_id() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.CntRequest.object_id)
  return object_id_;
}
inline void CntRequest::set_object_id(::google::protobuf::int64 value) {
  set_has_object_id();
  object_id_ = value;
  // @@protoc_insertion_point(field_set:managarm.mbus.CntRequest.object_id)
}

// -------------------------------------------------------------------

// SvrResponse

// optional int64 object_id = 1;
inline bool SvrResponse::has_object_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SvrResponse::set_has_object_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SvrResponse::clear_has_object_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SvrResponse::clear_object_id() {
  object_id_ = GOOGLE_LONGLONG(0);
  clear_has_object_id();
}
inline ::google::protobuf::int64 SvrResponse::object_id() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.SvrResponse.object_id)
  return object_id_;
}
inline void SvrResponse::set_object_id(::google::protobuf::int64 value) {
  set_has_object_id();
  object_id_ = value;
  // @@protoc_insertion_point(field_set:managarm.mbus.SvrResponse.object_id)
}

// -------------------------------------------------------------------

// SvrRequest

// optional .managarm.mbus.SvrReqType req_type = 1;
inline bool SvrRequest::has_req_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SvrRequest::set_has_req_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SvrRequest::clear_has_req_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SvrRequest::clear_req_type() {
  req_type_ = 1;
  clear_has_req_type();
}
inline ::managarm::mbus::SvrReqType SvrRequest::req_type() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.SvrRequest.req_type)
  return static_cast< ::managarm::mbus::SvrReqType >(req_type_);
}
inline void SvrRequest::set_req_type(::managarm::mbus::SvrReqType value) {
  assert(::managarm::mbus::SvrReqType_IsValid(value));
  set_has_req_type();
  req_type_ = value;
  // @@protoc_insertion_point(field_set:managarm.mbus.SvrRequest.req_type)
}

// optional int64 object_id = 2;
inline bool SvrRequest::has_object_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SvrRequest::set_has_object_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SvrRequest::clear_has_object_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SvrRequest::clear_object_id() {
  object_id_ = GOOGLE_LONGLONG(0);
  clear_has_object_id();
}
inline ::google::protobuf::int64 SvrRequest::object_id() const {
  // @@protoc_insertion_point(field_get:managarm.mbus.SvrRequest.object_id)
  return object_id_;
}
inline void SvrRequest::set_object_id(::google::protobuf::int64 value) {
  set_has_object_id();
  object_id_ = value;
  // @@protoc_insertion_point(field_set:managarm.mbus.SvrRequest.object_id)
}

// repeated .managarm.mbus.Capability caps = 3;
inline int SvrRequest::caps_size() const {
  return caps_.size();
}
inline void SvrRequest::clear_caps() {
  caps_.Clear();
}
inline const ::managarm::mbus::Capability& SvrRequest::caps(int index) const {
  // @@protoc_insertion_point(field_get:managarm.mbus.SvrRequest.caps)
  return caps_.Get(index);
}
inline ::managarm::mbus::Capability* SvrRequest::mutable_caps(int index) {
  // @@protoc_insertion_point(field_mutable:managarm.mbus.SvrRequest.caps)
  return caps_.Mutable(index);
}
inline ::managarm::mbus::Capability* SvrRequest::add_caps() {
  // @@protoc_insertion_point(field_add:managarm.mbus.SvrRequest.caps)
  return caps_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >&
SvrRequest::caps() const {
  // @@protoc_insertion_point(field_list:managarm.mbus.SvrRequest.caps)
  return caps_;
}
inline ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Capability >*
SvrRequest::mutable_caps() {
  // @@protoc_insertion_point(field_mutable_list:managarm.mbus.SvrRequest.caps)
  return &caps_;
}

// repeated .managarm.mbus.Interface ifs = 4;
inline int SvrRequest::ifs_size() const {
  return ifs_.size();
}
inline void SvrRequest::clear_ifs() {
  ifs_.Clear();
}
inline const ::managarm::mbus::Interface& SvrRequest::ifs(int index) const {
  // @@protoc_insertion_point(field_get:managarm.mbus.SvrRequest.ifs)
  return ifs_.Get(index);
}
inline ::managarm::mbus::Interface* SvrRequest::mutable_ifs(int index) {
  // @@protoc_insertion_point(field_mutable:managarm.mbus.SvrRequest.ifs)
  return ifs_.Mutable(index);
}
inline ::managarm::mbus::Interface* SvrRequest::add_ifs() {
  // @@protoc_insertion_point(field_add:managarm.mbus.SvrRequest.ifs)
  return ifs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >&
SvrRequest::ifs() const {
  // @@protoc_insertion_point(field_list:managarm.mbus.SvrRequest.ifs)
  return ifs_;
}
inline ::google::protobuf::RepeatedPtrField< ::managarm::mbus::Interface >*
SvrRequest::mutable_ifs() {
  // @@protoc_insertion_point(field_mutable_list:managarm.mbus.SvrRequest.ifs)
  return &ifs_;
}

// -------------------------------------------------------------------

// CntResponse

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mbus
}  // namespace managarm

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::managarm::mbus::CntReqType> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::managarm::mbus::SvrReqType> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mbus_2eproto__INCLUDED
