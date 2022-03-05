/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>

#include <thrift/lib/cpp2/type/Tag.h>


namespace apache {
namespace thrift {
namespace tag {
struct message;
struct sonnet;
struct error_message;
struct internal_error_message;
struct error_message;
struct internal_error_message;
struct message;
struct error_code;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_message
#define APACHE_THRIFT_ACCESSOR_message
APACHE_THRIFT_DEFINE_ACCESSOR(message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_sonnet
#define APACHE_THRIFT_ACCESSOR_sonnet
APACHE_THRIFT_DEFINE_ACCESSOR(sonnet);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_error_message
#define APACHE_THRIFT_ACCESSOR_error_message
APACHE_THRIFT_DEFINE_ACCESSOR(error_message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_internal_error_message
#define APACHE_THRIFT_ACCESSOR_internal_error_message
APACHE_THRIFT_DEFINE_ACCESSOR(internal_error_message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_error_message
#define APACHE_THRIFT_ACCESSOR_error_message
APACHE_THRIFT_DEFINE_ACCESSOR(error_message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_internal_error_message
#define APACHE_THRIFT_ACCESSOR_internal_error_message
APACHE_THRIFT_DEFINE_ACCESSOR(internal_error_message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_message
#define APACHE_THRIFT_ACCESSOR_message
APACHE_THRIFT_DEFINE_ACCESSOR(message);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_error_code
#define APACHE_THRIFT_ACCESSOR_error_code
APACHE_THRIFT_DEFINE_ACCESSOR(error_code);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace cpp2 {
class Fiery;
class Serious;
class ComplexFieldNames;
class CustomFieldNames;
class ExceptionWithPrimitiveField;
class Banal;
} // cpp2
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace cpp2 {
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;
} // cpp2
namespace cpp2 {
class FOLLY_EXPORT Fiery : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::TRANSIENT;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::SERVER;

 public:
  using __fbthrift_cpp2_type = Fiery;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Fiery();
  explicit Fiery(std::string __message);

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Fiery(apache::thrift::FragileConstructor, ::std::string message__arg);

  Fiery(Fiery&&) noexcept;

  Fiery(const Fiery& src);


  Fiery& operator=(Fiery&&) noexcept;
  Fiery& operator=(const Fiery& src);

  ~Fiery() override;

 public:
  ::std::string message;

 public:

  bool operator==(const Fiery&) const;
  bool operator<(const Fiery&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::required_field_ref<const T&> message_ref() const& {
    return ::apache::thrift::required_field_ref<const T&>{this->message};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::required_field_ref<const T&&> message_ref() const&& {
    return ::apache::thrift::required_field_ref<const T&&>{static_cast<const T&&>(this->message)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::required_field_ref<T&> message_ref() & {
    return ::apache::thrift::required_field_ref<T&>{this->message};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::required_field_ref<T&&> message_ref() && {
    return ::apache::thrift::required_field_ref<T&&>{static_cast<T&&>(this->message)};
  }

  const ::std::string& get_message() const& {
    return message;
  }

  ::std::string get_message() && {
    return std::move(message);
  }

  template <typename T_Fiery_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.message_ref() = BAR;` instead of `FOO.set_message(BAR);`")]]
  ::std::string& set_message(T_Fiery_message_struct_setter&& message_) {
    message_ref() = std::forward<T_Fiery_message_struct_setter>(message_);
    return message;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return message.c_str();
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Fiery>;
  friend void swap(Fiery& a, Fiery& b);
};

template <class Protocol_>
unsigned long Fiery::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FOLLY_EXPORT Serious : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::STATEFUL;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::SAFE;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::UNSPECIFIED;

 public:
  using __fbthrift_cpp2_type = Serious;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Serious();
  explicit Serious(std::string __message);

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Serious(apache::thrift::FragileConstructor, ::std::string sonnet__arg);

  Serious(Serious&&) noexcept;

  Serious(const Serious& src);


  Serious& operator=(Serious&&) noexcept;
  Serious& operator=(const Serious& src);

  ~Serious() override;

 private:
  ::std::string sonnet;
 private:
  apache::thrift::detail::isset_bitset<1, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const Serious&) const;
  bool operator<(const Serious&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&> sonnet_ref() const& {
    return {this->sonnet, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&&> sonnet_ref() const&& {
    return {static_cast<const T&&>(this->sonnet), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&> sonnet_ref() & {
    return {this->sonnet, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&&> sonnet_ref() && {
    return {static_cast<T&&>(this->sonnet), __isset.at(0), __isset.bit(0)};
  }

  const ::std::string* get_sonnet() const& {
    return sonnet_ref() ? std::addressof(sonnet) : nullptr;
  }

  ::std::string* get_sonnet() & {
    return sonnet_ref() ? std::addressof(sonnet) : nullptr;
  }
  ::std::string* get_sonnet() && = delete;

  template <typename T_Serious_sonnet_struct_setter = ::std::string>
  [[deprecated("Use `FOO.sonnet_ref() = BAR;` instead of `FOO.set_sonnet(BAR);`")]]
  ::std::string& set_sonnet(T_Serious_sonnet_struct_setter&& sonnet_) {
    sonnet_ref() = std::forward<T_Serious_sonnet_struct_setter>(sonnet_);
    return sonnet;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return sonnet.c_str();
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Serious>;
  friend void swap(Serious& a, Serious& b);
};

template <class Protocol_>
unsigned long Serious::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FOLLY_EXPORT ComplexFieldNames : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::CLIENT;

 public:
  using __fbthrift_cpp2_type = ComplexFieldNames;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  ComplexFieldNames();
  explicit ComplexFieldNames(std::string __message);

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  ComplexFieldNames(apache::thrift::FragileConstructor, ::std::string error_message__arg, ::std::string internal_error_message__arg);

  ComplexFieldNames(ComplexFieldNames&&) noexcept;

  ComplexFieldNames(const ComplexFieldNames& src);


  ComplexFieldNames& operator=(ComplexFieldNames&&) noexcept;
  ComplexFieldNames& operator=(const ComplexFieldNames& src);

  ~ComplexFieldNames() override;

 private:
  ::std::string error_message;
 private:
  ::std::string internal_error_message;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const ComplexFieldNames&) const;
  bool operator<(const ComplexFieldNames&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> error_message_ref() const& {
    return {this->error_message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> error_message_ref() const&& {
    return {static_cast<const T&&>(this->error_message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> error_message_ref() & {
    return {this->error_message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> error_message_ref() && {
    return {static_cast<T&&>(this->error_message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> internal_error_message_ref() const& {
    return {this->internal_error_message, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> internal_error_message_ref() const&& {
    return {static_cast<const T&&>(this->internal_error_message), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> internal_error_message_ref() & {
    return {this->internal_error_message, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> internal_error_message_ref() && {
    return {static_cast<T&&>(this->internal_error_message), __isset.at(1), __isset.bit(1)};
  }

  const ::std::string& get_error_message() const& {
    return error_message;
  }

  ::std::string get_error_message() && {
    return std::move(error_message);
  }

  template <typename T_ComplexFieldNames_error_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.error_message_ref() = BAR;` instead of `FOO.set_error_message(BAR);`")]]
  ::std::string& set_error_message(T_ComplexFieldNames_error_message_struct_setter&& error_message_) {
    error_message_ref() = std::forward<T_ComplexFieldNames_error_message_struct_setter>(error_message_);
    return error_message;
  }

  const ::std::string& get_internal_error_message() const& {
    return internal_error_message;
  }

  ::std::string get_internal_error_message() && {
    return std::move(internal_error_message);
  }

  template <typename T_ComplexFieldNames_internal_error_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.internal_error_message_ref() = BAR;` instead of `FOO.set_internal_error_message(BAR);`")]]
  ::std::string& set_internal_error_message(T_ComplexFieldNames_internal_error_message_struct_setter&& internal_error_message_) {
    internal_error_message_ref() = std::forward<T_ComplexFieldNames_internal_error_message_struct_setter>(internal_error_message_);
    return internal_error_message;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return internal_error_message.c_str();
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<ComplexFieldNames>;
  friend void swap(ComplexFieldNames& a, ComplexFieldNames& b);
};

template <class Protocol_>
unsigned long ComplexFieldNames::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FOLLY_EXPORT CustomFieldNames : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::UNSPECIFIED;

 public:
  using __fbthrift_cpp2_type = CustomFieldNames;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  CustomFieldNames();
  explicit CustomFieldNames(std::string __message);

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  CustomFieldNames(apache::thrift::FragileConstructor, ::std::string error_message__arg, ::std::string internal_error_message__arg);

  CustomFieldNames(CustomFieldNames&&) noexcept;

  CustomFieldNames(const CustomFieldNames& src);


  CustomFieldNames& operator=(CustomFieldNames&&) noexcept;
  CustomFieldNames& operator=(const CustomFieldNames& src);

  ~CustomFieldNames() override;

 private:
  ::std::string error_message;
 private:
  ::std::string internal_error_message;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const CustomFieldNames&) const;
  bool operator<(const CustomFieldNames&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> error_message_ref() const& {
    return {this->error_message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> error_message_ref() const&& {
    return {static_cast<const T&&>(this->error_message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> error_message_ref() & {
    return {this->error_message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> error_message_ref() && {
    return {static_cast<T&&>(this->error_message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> internal_error_message_ref() const& {
    return {this->internal_error_message, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> internal_error_message_ref() const&& {
    return {static_cast<const T&&>(this->internal_error_message), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> internal_error_message_ref() & {
    return {this->internal_error_message, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> internal_error_message_ref() && {
    return {static_cast<T&&>(this->internal_error_message), __isset.at(1), __isset.bit(1)};
  }

  const ::std::string& get_error_message() const& {
    return error_message;
  }

  ::std::string get_error_message() && {
    return std::move(error_message);
  }

  template <typename T_CustomFieldNames_error_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.error_message_ref() = BAR;` instead of `FOO.set_error_message(BAR);`")]]
  ::std::string& set_error_message(T_CustomFieldNames_error_message_struct_setter&& error_message_) {
    error_message_ref() = std::forward<T_CustomFieldNames_error_message_struct_setter>(error_message_);
    return error_message;
  }

  const ::std::string& get_internal_error_message() const& {
    return internal_error_message;
  }

  ::std::string get_internal_error_message() && {
    return std::move(internal_error_message);
  }

  template <typename T_CustomFieldNames_internal_error_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.internal_error_message_ref() = BAR;` instead of `FOO.set_internal_error_message(BAR);`")]]
  ::std::string& set_internal_error_message(T_CustomFieldNames_internal_error_message_struct_setter&& internal_error_message_) {
    internal_error_message_ref() = std::forward<T_CustomFieldNames_internal_error_message_struct_setter>(internal_error_message_);
    return internal_error_message;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return internal_error_message.c_str();
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<CustomFieldNames>;
  friend void swap(CustomFieldNames& a, CustomFieldNames& b);
};

template <class Protocol_>
unsigned long CustomFieldNames::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FOLLY_EXPORT ExceptionWithPrimitiveField : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::UNSPECIFIED;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::UNSPECIFIED;

 public:
  using __fbthrift_cpp2_type = ExceptionWithPrimitiveField;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  ExceptionWithPrimitiveField();
  explicit ExceptionWithPrimitiveField(std::string __message);

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  ExceptionWithPrimitiveField(apache::thrift::FragileConstructor, ::std::string message__arg, ::std::int32_t error_code__arg);

  ExceptionWithPrimitiveField(ExceptionWithPrimitiveField&&) noexcept;

  ExceptionWithPrimitiveField(const ExceptionWithPrimitiveField& src);


  ExceptionWithPrimitiveField& operator=(ExceptionWithPrimitiveField&&) noexcept;
  ExceptionWithPrimitiveField& operator=(const ExceptionWithPrimitiveField& src);

  ~ExceptionWithPrimitiveField() override;

 private:
  ::std::string message;
 private:
  ::std::int32_t error_code;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const ExceptionWithPrimitiveField&) const;
  bool operator<(const ExceptionWithPrimitiveField&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> message_ref() const& {
    return {this->message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> message_ref() const&& {
    return {static_cast<const T&&>(this->message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> message_ref() & {
    return {this->message, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> message_ref() && {
    return {static_cast<T&&>(this->message), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> error_code_ref() const& {
    return {this->error_code, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> error_code_ref() const&& {
    return {static_cast<const T&&>(this->error_code), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> error_code_ref() & {
    return {this->error_code, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> error_code_ref() && {
    return {static_cast<T&&>(this->error_code), __isset.at(1), __isset.bit(1)};
  }

  const ::std::string& get_message() const& {
    return message;
  }

  ::std::string get_message() && {
    return std::move(message);
  }

  template <typename T_ExceptionWithPrimitiveField_message_struct_setter = ::std::string>
  [[deprecated("Use `FOO.message_ref() = BAR;` instead of `FOO.set_message(BAR);`")]]
  ::std::string& set_message(T_ExceptionWithPrimitiveField_message_struct_setter&& message_) {
    message_ref() = std::forward<T_ExceptionWithPrimitiveField_message_struct_setter>(message_);
    return message;
  }

  ::std::int32_t get_error_code() const {
    return error_code;
  }

  [[deprecated("Use `FOO.error_code_ref() = BAR;` instead of `FOO.set_error_code(BAR);`")]]
  ::std::int32_t& set_error_code(::std::int32_t error_code_) {
    error_code_ref() = error_code_;
    return error_code;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return message.c_str();
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<ExceptionWithPrimitiveField>;
  friend void swap(ExceptionWithPrimitiveField& a, ExceptionWithPrimitiveField& b);
};

template <class Protocol_>
unsigned long ExceptionWithPrimitiveField::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FOLLY_EXPORT Banal : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;
  static constexpr ::apache::thrift::ExceptionKind __fbthrift_cpp2_gen_exception_kind =
         ::apache::thrift::ExceptionKind::PERMANENT;
  static constexpr ::apache::thrift::ExceptionSafety __fbthrift_cpp2_gen_exception_safety =
         ::apache::thrift::ExceptionSafety::SAFE;
  static constexpr ::apache::thrift::ExceptionBlame __fbthrift_cpp2_gen_exception_blame =
         ::apache::thrift::ExceptionBlame::CLIENT;

 public:
  using __fbthrift_cpp2_type = Banal;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  Banal();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  Banal(apache::thrift::FragileConstructor);

  Banal(Banal&&) noexcept;

  Banal(const Banal& src);


  Banal& operator=(Banal&&) noexcept;
  Banal& operator=(const Banal& src);

  ~Banal() override;


 public:

  bool operator==(const Banal&) const;
  bool operator<(const Banal&) const;

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return "::cpp2::Banal";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<Banal>;
  friend void swap(Banal& a, Banal& b);
};

template <class Protocol_>
unsigned long Banal::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
