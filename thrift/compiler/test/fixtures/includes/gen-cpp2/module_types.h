/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>

#include <thrift/lib/cpp2/type/Tag.h>

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/includes_types.h"

namespace apache {
namespace thrift {
namespace tag {
struct MyIncludedField;
struct MyOtherIncludedField;
struct MyIncludedInt;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_MyIncludedField
#define APACHE_THRIFT_ACCESSOR_MyIncludedField
APACHE_THRIFT_DEFINE_ACCESSOR(MyIncludedField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_MyOtherIncludedField
#define APACHE_THRIFT_ACCESSOR_MyOtherIncludedField
APACHE_THRIFT_DEFINE_ACCESSOR(MyOtherIncludedField);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_MyIncludedInt
#define APACHE_THRIFT_ACCESSOR_MyIncludedInt
APACHE_THRIFT_DEFINE_ACCESSOR(MyIncludedInt);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace cpp2 {
class MyStruct;
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
class MyStruct final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

  void __fbthrift_clear();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = MyStruct;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

  MyStruct() :
      __fbthrift_field_MyIncludedField(static_cast<::cpp2::Included>(::apache::thrift::detail::make_constant< ::cpp2::Included>(::apache::thrift::type_class::structure{}, ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::tag::MyIntField>(static_cast<::std::int64_t>(2)), ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::tag::MyTransitiveField>(static_cast<::cpp2::Foo>(::apache::thrift::detail::make_constant< ::cpp2::Foo>(::apache::thrift::type_class::structure{}, ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::tag::a>(static_cast<::std::int64_t>(2)))))))),
      __fbthrift_field_MyIncludedInt(static_cast<::cpp2::IncludedInt64>(42)) {
  }
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  MyStruct(apache::thrift::FragileConstructor, ::cpp2::Included MyIncludedField__arg, ::cpp2::Included MyOtherIncludedField__arg, ::cpp2::IncludedInt64 MyIncludedInt__arg);

  MyStruct(MyStruct&&) noexcept;

  MyStruct(const MyStruct& src);


  MyStruct& operator=(MyStruct&&) noexcept;
  MyStruct& operator=(const MyStruct& src);
 private:
  ::cpp2::Included __fbthrift_field_MyIncludedField;
 private:
  ::cpp2::Included __fbthrift_field_MyOtherIncludedField;
 private:
  ::cpp2::IncludedInt64 __fbthrift_field_MyIncludedInt;
 private:
  apache::thrift::detail::isset_bitset<3, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const MyStruct&) const;
  bool operator<(const MyStruct&) const;

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyIncludedField_ref() const& {
    return {this->__fbthrift_field_MyIncludedField, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyIncludedField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyIncludedField), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyIncludedField_ref() & {
    return {this->__fbthrift_field_MyIncludedField, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyIncludedField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyIncludedField), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyIncludedField() const& {
    return {this->__fbthrift_field_MyIncludedField, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyIncludedField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyIncludedField), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyIncludedField() & {
    return {this->__fbthrift_field_MyIncludedField, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyIncludedField() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyIncludedField), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyOtherIncludedField_ref() const& {
    return {this->__fbthrift_field_MyOtherIncludedField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyOtherIncludedField_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyOtherIncludedField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyOtherIncludedField_ref() & {
    return {this->__fbthrift_field_MyOtherIncludedField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyOtherIncludedField_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyOtherIncludedField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyOtherIncludedField() const& {
    return {this->__fbthrift_field_MyOtherIncludedField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyOtherIncludedField() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyOtherIncludedField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyOtherIncludedField() & {
    return {this->__fbthrift_field_MyOtherIncludedField, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::Included>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyOtherIncludedField() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyOtherIncludedField), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyIncludedInt_ref() const& {
    return {this->__fbthrift_field_MyIncludedInt, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyIncludedInt_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyIncludedInt), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyIncludedInt_ref() & {
    return {this->__fbthrift_field_MyIncludedInt, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyIncludedInt_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyIncludedInt), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> MyIncludedInt() const& {
    return {this->__fbthrift_field_MyIncludedInt, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> MyIncludedInt() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_MyIncludedInt), __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> MyIncludedInt() & {
    return {this->__fbthrift_field_MyIncludedInt, __isset.at(2), __isset.bit(2)};
  }

  template <typename..., typename T = ::cpp2::IncludedInt64>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> MyIncludedInt() && {
    return {static_cast<T&&>(this->__fbthrift_field_MyIncludedInt), __isset.at(2), __isset.bit(2)};
  }
  const ::cpp2::Included& get_MyIncludedField() const&;
  ::cpp2::Included get_MyIncludedField() &&;

  template <typename T_MyStruct_MyIncludedField_struct_setter = ::cpp2::Included>
  [[deprecated("Use `FOO.MyIncludedField_ref() = BAR;` instead of `FOO.set_MyIncludedField(BAR);`")]]
  ::cpp2::Included& set_MyIncludedField(T_MyStruct_MyIncludedField_struct_setter&& MyIncludedField_) {
    MyIncludedField_ref() = std::forward<T_MyStruct_MyIncludedField_struct_setter>(MyIncludedField_);
    return __fbthrift_field_MyIncludedField;
  }
  const ::cpp2::Included& get_MyOtherIncludedField() const&;
  ::cpp2::Included get_MyOtherIncludedField() &&;

  template <typename T_MyStruct_MyOtherIncludedField_struct_setter = ::cpp2::Included>
  [[deprecated("Use `FOO.MyOtherIncludedField_ref() = BAR;` instead of `FOO.set_MyOtherIncludedField(BAR);`")]]
  ::cpp2::Included& set_MyOtherIncludedField(T_MyStruct_MyOtherIncludedField_struct_setter&& MyOtherIncludedField_) {
    MyOtherIncludedField_ref() = std::forward<T_MyStruct_MyOtherIncludedField_struct_setter>(MyOtherIncludedField_);
    return __fbthrift_field_MyOtherIncludedField;
  }

  ::cpp2::IncludedInt64 get_MyIncludedInt() const {
    return __fbthrift_field_MyIncludedInt;
  }

  [[deprecated("Use `FOO.MyIncludedInt_ref() = BAR;` instead of `FOO.set_MyIncludedInt(BAR);`")]]
  ::cpp2::IncludedInt64& set_MyIncludedInt(::cpp2::IncludedInt64 MyIncludedInt_) {
    MyIncludedInt_ref() = MyIncludedInt_;
    return __fbthrift_field_MyIncludedInt;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<MyStruct>;
  friend void swap(MyStruct& a, MyStruct& b);
};

template <class Protocol_>
unsigned long MyStruct::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
