// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_user_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_user_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_user_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_user_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_2eproto;
namespace fixbug {
class LoginRequest;
struct LoginRequestDefaultTypeInternal;
extern LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
class LoginResponse;
struct LoginResponseDefaultTypeInternal;
extern LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
class ResultCode;
struct ResultCodeDefaultTypeInternal;
extern ResultCodeDefaultTypeInternal _ResultCode_default_instance_;
}  // namespace fixbug
PROTOBUF_NAMESPACE_OPEN
template<> ::fixbug::LoginRequest* Arena::CreateMaybeMessage<::fixbug::LoginRequest>(Arena*);
template<> ::fixbug::LoginResponse* Arena::CreateMaybeMessage<::fixbug::LoginResponse>(Arena*);
template<> ::fixbug::ResultCode* Arena::CreateMaybeMessage<::fixbug::ResultCode>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace fixbug {

// ===================================================================

class ResultCode final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fixbug.ResultCode) */ {
 public:
  inline ResultCode() : ResultCode(nullptr) {}
  ~ResultCode() override;
  explicit PROTOBUF_CONSTEXPR ResultCode(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ResultCode(const ResultCode& from);
  ResultCode(ResultCode&& from) noexcept
    : ResultCode() {
    *this = ::std::move(from);
  }

  inline ResultCode& operator=(const ResultCode& from) {
    CopyFrom(from);
    return *this;
  }
  inline ResultCode& operator=(ResultCode&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ResultCode& default_instance() {
    return *internal_default_instance();
  }
  static inline const ResultCode* internal_default_instance() {
    return reinterpret_cast<const ResultCode*>(
               &_ResultCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ResultCode& a, ResultCode& b) {
    a.Swap(&b);
  }
  inline void Swap(ResultCode* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ResultCode* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ResultCode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ResultCode>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ResultCode& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ResultCode& from) {
    ResultCode::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ResultCode* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fixbug.ResultCode";
  }
  protected:
  explicit ResultCode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrcodeFieldNumber = 1,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_errmsg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_errmsg();
  PROTOBUF_NODISCARD std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // int32 errcode = 1;
  void clear_errcode();
  int32_t errcode() const;
  void set_errcode(int32_t value);
  private:
  int32_t _internal_errcode() const;
  void _internal_set_errcode(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:fixbug.ResultCode)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
    int32_t errcode_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class LoginRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fixbug.LoginRequest) */ {
 public:
  inline LoginRequest() : LoginRequest(nullptr) {}
  ~LoginRequest() override;
  explicit PROTOBUF_CONSTEXPR LoginRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginRequest(const LoginRequest& from);
  LoginRequest(LoginRequest&& from) noexcept
    : LoginRequest() {
    *this = ::std::move(from);
  }

  inline LoginRequest& operator=(const LoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginRequest& operator=(LoginRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LoginRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginRequest* internal_default_instance() {
    return reinterpret_cast<const LoginRequest*>(
               &_LoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LoginRequest& a, LoginRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LoginRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const LoginRequest& from) {
    LoginRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LoginRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fixbug.LoginRequest";
  }
  protected:
  explicit LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUsernameFieldNumber = 1,
    kPasswordFieldNumber = 2,
  };
  // bytes username = 1;
  void clear_username();
  const std::string& username() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_username(ArgT0&& arg0, ArgT... args);
  std::string* mutable_username();
  PROTOBUF_NODISCARD std::string* release_username();
  void set_allocated_username(std::string* username);
  private:
  const std::string& _internal_username() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_username(const std::string& value);
  std::string* _internal_mutable_username();
  public:

  // bytes password = 2;
  void clear_password();
  const std::string& password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_password();
  PROTOBUF_NODISCARD std::string* release_password();
  void set_allocated_password(std::string* password);
  private:
  const std::string& _internal_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // @@protoc_insertion_point(class_scope:fixbug.LoginRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr username_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class LoginResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fixbug.LoginResponse) */ {
 public:
  inline LoginResponse() : LoginResponse(nullptr) {}
  ~LoginResponse() override;
  explicit PROTOBUF_CONSTEXPR LoginResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginResponse(const LoginResponse& from);
  LoginResponse(LoginResponse&& from) noexcept
    : LoginResponse() {
    *this = ::std::move(from);
  }

  inline LoginResponse& operator=(const LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginResponse& operator=(LoginResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LoginResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginResponse* internal_default_instance() {
    return reinterpret_cast<const LoginResponse*>(
               &_LoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(LoginResponse& a, LoginResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LoginResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const LoginResponse& from) {
    LoginResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LoginResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fixbug.LoginResponse";
  }
  protected:
  explicit LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSuccessFieldNumber = 2,
    kResultFieldNumber = 1,
  };
  // bytes success = 2;
  void clear_success();
  const std::string& success() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_success(ArgT0&& arg0, ArgT... args);
  std::string* mutable_success();
  PROTOBUF_NODISCARD std::string* release_success();
  void set_allocated_success(std::string* success);
  private:
  const std::string& _internal_success() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_success(const std::string& value);
  std::string* _internal_mutable_success();
  public:

  // .fixbug.ResultCode result = 1;
  bool has_result() const;
  private:
  bool _internal_has_result() const;
  public:
  void clear_result();
  const ::fixbug::ResultCode& result() const;
  PROTOBUF_NODISCARD ::fixbug::ResultCode* release_result();
  ::fixbug::ResultCode* mutable_result();
  void set_allocated_result(::fixbug::ResultCode* result);
  private:
  const ::fixbug::ResultCode& _internal_result() const;
  ::fixbug::ResultCode* _internal_mutable_result();
  public:
  void unsafe_arena_set_allocated_result(
      ::fixbug::ResultCode* result);
  ::fixbug::ResultCode* unsafe_arena_release_result();

  // @@protoc_insertion_point(class_scope:fixbug.LoginResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr success_;
    ::fixbug::ResultCode* result_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_user_2eproto;
};
// ===================================================================

class UserServiceRpc_Stub;

class UserServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline UserServiceRpc() {};
 public:
  virtual ~UserServiceRpc();

  typedef UserServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc);
};

class UserServiceRpc_Stub : public UserServiceRpc {
 public:
  UserServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  UserServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~UserServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements UserServiceRpc ------------------------------------------

  void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ResultCode

// int32 errcode = 1;
inline void ResultCode::clear_errcode() {
  _impl_.errcode_ = 0;
}
inline int32_t ResultCode::_internal_errcode() const {
  return _impl_.errcode_;
}
inline int32_t ResultCode::errcode() const {
  // @@protoc_insertion_point(field_get:fixbug.ResultCode.errcode)
  return _internal_errcode();
}
inline void ResultCode::_internal_set_errcode(int32_t value) {
  
  _impl_.errcode_ = value;
}
inline void ResultCode::set_errcode(int32_t value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:fixbug.ResultCode.errcode)
}

// bytes errmsg = 2;
inline void ResultCode::clear_errmsg() {
  _impl_.errmsg_.ClearToEmpty();
}
inline const std::string& ResultCode::errmsg() const {
  // @@protoc_insertion_point(field_get:fixbug.ResultCode.errmsg)
  return _internal_errmsg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ResultCode::set_errmsg(ArgT0&& arg0, ArgT... args) {
 
 _impl_.errmsg_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:fixbug.ResultCode.errmsg)
}
inline std::string* ResultCode::mutable_errmsg() {
  std::string* _s = _internal_mutable_errmsg();
  // @@protoc_insertion_point(field_mutable:fixbug.ResultCode.errmsg)
  return _s;
}
inline const std::string& ResultCode::_internal_errmsg() const {
  return _impl_.errmsg_.Get();
}
inline void ResultCode::_internal_set_errmsg(const std::string& value) {
  
  _impl_.errmsg_.Set(value, GetArenaForAllocation());
}
inline std::string* ResultCode::_internal_mutable_errmsg() {
  
  return _impl_.errmsg_.Mutable(GetArenaForAllocation());
}
inline std::string* ResultCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:fixbug.ResultCode.errmsg)
  return _impl_.errmsg_.Release();
}
inline void ResultCode::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  _impl_.errmsg_.SetAllocated(errmsg, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.errmsg_.IsDefault()) {
    _impl_.errmsg_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:fixbug.ResultCode.errmsg)
}

// -------------------------------------------------------------------

// LoginRequest

// bytes username = 1;
inline void LoginRequest::clear_username() {
  _impl_.username_.ClearToEmpty();
}
inline const std::string& LoginRequest::username() const {
  // @@protoc_insertion_point(field_get:fixbug.LoginRequest.username)
  return _internal_username();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_username(ArgT0&& arg0, ArgT... args) {
 
 _impl_.username_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:fixbug.LoginRequest.username)
}
inline std::string* LoginRequest::mutable_username() {
  std::string* _s = _internal_mutable_username();
  // @@protoc_insertion_point(field_mutable:fixbug.LoginRequest.username)
  return _s;
}
inline const std::string& LoginRequest::_internal_username() const {
  return _impl_.username_.Get();
}
inline void LoginRequest::_internal_set_username(const std::string& value) {
  
  _impl_.username_.Set(value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_username() {
  
  return _impl_.username_.Mutable(GetArenaForAllocation());
}
inline std::string* LoginRequest::release_username() {
  // @@protoc_insertion_point(field_release:fixbug.LoginRequest.username)
  return _impl_.username_.Release();
}
inline void LoginRequest::set_allocated_username(std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  _impl_.username_.SetAllocated(username, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.username_.IsDefault()) {
    _impl_.username_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:fixbug.LoginRequest.username)
}

// bytes password = 2;
inline void LoginRequest::clear_password() {
  _impl_.password_.ClearToEmpty();
}
inline const std::string& LoginRequest::password() const {
  // @@protoc_insertion_point(field_get:fixbug.LoginRequest.password)
  return _internal_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_password(ArgT0&& arg0, ArgT... args) {
 
 _impl_.password_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:fixbug.LoginRequest.password)
}
inline std::string* LoginRequest::mutable_password() {
  std::string* _s = _internal_mutable_password();
  // @@protoc_insertion_point(field_mutable:fixbug.LoginRequest.password)
  return _s;
}
inline const std::string& LoginRequest::_internal_password() const {
  return _impl_.password_.Get();
}
inline void LoginRequest::_internal_set_password(const std::string& value) {
  
  _impl_.password_.Set(value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_password() {
  
  return _impl_.password_.Mutable(GetArenaForAllocation());
}
inline std::string* LoginRequest::release_password() {
  // @@protoc_insertion_point(field_release:fixbug.LoginRequest.password)
  return _impl_.password_.Release();
}
inline void LoginRequest::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  _impl_.password_.SetAllocated(password, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.password_.IsDefault()) {
    _impl_.password_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:fixbug.LoginRequest.password)
}

// -------------------------------------------------------------------

// LoginResponse

// .fixbug.ResultCode result = 1;
inline bool LoginResponse::_internal_has_result() const {
  return this != internal_default_instance() && _impl_.result_ != nullptr;
}
inline bool LoginResponse::has_result() const {
  return _internal_has_result();
}
inline void LoginResponse::clear_result() {
  if (GetArenaForAllocation() == nullptr && _impl_.result_ != nullptr) {
    delete _impl_.result_;
  }
  _impl_.result_ = nullptr;
}
inline const ::fixbug::ResultCode& LoginResponse::_internal_result() const {
  const ::fixbug::ResultCode* p = _impl_.result_;
  return p != nullptr ? *p : reinterpret_cast<const ::fixbug::ResultCode&>(
      ::fixbug::_ResultCode_default_instance_);
}
inline const ::fixbug::ResultCode& LoginResponse::result() const {
  // @@protoc_insertion_point(field_get:fixbug.LoginResponse.result)
  return _internal_result();
}
inline void LoginResponse::unsafe_arena_set_allocated_result(
    ::fixbug::ResultCode* result) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.result_);
  }
  _impl_.result_ = result;
  if (result) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:fixbug.LoginResponse.result)
}
inline ::fixbug::ResultCode* LoginResponse::release_result() {
  
  ::fixbug::ResultCode* temp = _impl_.result_;
  _impl_.result_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::fixbug::ResultCode* LoginResponse::unsafe_arena_release_result() {
  // @@protoc_insertion_point(field_release:fixbug.LoginResponse.result)
  
  ::fixbug::ResultCode* temp = _impl_.result_;
  _impl_.result_ = nullptr;
  return temp;
}
inline ::fixbug::ResultCode* LoginResponse::_internal_mutable_result() {
  
  if (_impl_.result_ == nullptr) {
    auto* p = CreateMaybeMessage<::fixbug::ResultCode>(GetArenaForAllocation());
    _impl_.result_ = p;
  }
  return _impl_.result_;
}
inline ::fixbug::ResultCode* LoginResponse::mutable_result() {
  ::fixbug::ResultCode* _msg = _internal_mutable_result();
  // @@protoc_insertion_point(field_mutable:fixbug.LoginResponse.result)
  return _msg;
}
inline void LoginResponse::set_allocated_result(::fixbug::ResultCode* result) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.result_;
  }
  if (result) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(result);
    if (message_arena != submessage_arena) {
      result = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.result_ = result;
  // @@protoc_insertion_point(field_set_allocated:fixbug.LoginResponse.result)
}

// bytes success = 2;
inline void LoginResponse::clear_success() {
  _impl_.success_.ClearToEmpty();
}
inline const std::string& LoginResponse::success() const {
  // @@protoc_insertion_point(field_get:fixbug.LoginResponse.success)
  return _internal_success();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginResponse::set_success(ArgT0&& arg0, ArgT... args) {
 
 _impl_.success_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:fixbug.LoginResponse.success)
}
inline std::string* LoginResponse::mutable_success() {
  std::string* _s = _internal_mutable_success();
  // @@protoc_insertion_point(field_mutable:fixbug.LoginResponse.success)
  return _s;
}
inline const std::string& LoginResponse::_internal_success() const {
  return _impl_.success_.Get();
}
inline void LoginResponse::_internal_set_success(const std::string& value) {
  
  _impl_.success_.Set(value, GetArenaForAllocation());
}
inline std::string* LoginResponse::_internal_mutable_success() {
  
  return _impl_.success_.Mutable(GetArenaForAllocation());
}
inline std::string* LoginResponse::release_success() {
  // @@protoc_insertion_point(field_release:fixbug.LoginResponse.success)
  return _impl_.success_.Release();
}
inline void LoginResponse::set_allocated_success(std::string* success) {
  if (success != nullptr) {
    
  } else {
    
  }
  _impl_.success_.SetAllocated(success, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.success_.IsDefault()) {
    _impl_.success_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:fixbug.LoginResponse.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace fixbug

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_user_2eproto
