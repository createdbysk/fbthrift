/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/qualified/src/module2.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module2_types.h"
#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module2_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module2_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::module2::Struct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::module2::Struct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace module2 {

const folly::StringPiece Struct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<Struct>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece Struct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<Struct>::name;
}

Struct::Struct(const Struct&) = default;
Struct& Struct::operator=(const Struct&) = default;
Struct::Struct(FOLLY_MAYBE_UNUSED Struct&& other) noexcept :
    __fbthrift_field_first(std::move(other.__fbthrift_field_first)),
    __fbthrift_field_second(std::move(other.__fbthrift_field_second)),
    __isset(other.__isset) {
}

Struct& Struct::operator=(FOLLY_MAYBE_UNUSED Struct&& other) noexcept {
    this->__fbthrift_field_first = std::move(other.__fbthrift_field_first);
    this->__fbthrift_field_second = std::move(other.__fbthrift_field_second);
    __isset = other.__isset;
    return *this;
}


Struct::Struct(apache::thrift::FragileConstructor, ::module0::Struct first__arg, ::module1::Struct second__arg) :
    __fbthrift_field_first(std::move(first__arg)),
    __fbthrift_field_second(std::move(second__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void Struct::__fbthrift_clear() {
  // clear all fields
  ::apache::thrift::clear(this->__fbthrift_field_first);
  ::apache::thrift::clear(this->__fbthrift_field_second);
  __isset = {};
}

void Struct::__fbthrift_clear_terse_fields() {
}

bool Struct::__fbthrift_is_empty() const {
  return false;
}

bool Struct::operator==(FOLLY_MAYBE_UNUSED const Struct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool Struct::operator<(FOLLY_MAYBE_UNUSED const Struct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}

const ::module0::Struct& Struct::get_first() const& {
  return __fbthrift_field_first;
}

::module0::Struct Struct::get_first() && {
  return std::move(__fbthrift_field_first);
}

const ::module1::Struct& Struct::get_second() const& {
  return __fbthrift_field_second;
}

::module1::Struct Struct::get_second() && {
  return std::move(__fbthrift_field_second);
}


void swap(FOLLY_MAYBE_UNUSED Struct& a, FOLLY_MAYBE_UNUSED Struct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_first, b.__fbthrift_field_first);
  swap(a.__fbthrift_field_second, b.__fbthrift_field_second);
  swap(a.__isset, b.__isset);
}

template void Struct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Struct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Struct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Struct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Struct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Struct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Struct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Struct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        Struct,
        ::apache::thrift::type_class::structure,
        ::module0::Struct>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        Struct,
        ::apache::thrift::type_class::structure,
        ::module1::Struct>,
    "inconsistent use of json option");

} // module2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::module2::BigStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::module2::BigStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace module2 {

const folly::StringPiece BigStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<BigStruct>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece BigStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<BigStruct>::name;
}

BigStruct::BigStruct(const BigStruct&) = default;
BigStruct& BigStruct::operator=(const BigStruct&) = default;
BigStruct::BigStruct(FOLLY_MAYBE_UNUSED BigStruct&& other) noexcept :
    __fbthrift_field_s(std::move(other.__fbthrift_field_s)),
    __fbthrift_field_id(std::move(other.__fbthrift_field_id)),
    __isset(other.__isset) {
}

BigStruct& BigStruct::operator=(FOLLY_MAYBE_UNUSED BigStruct&& other) noexcept {
    this->__fbthrift_field_s = std::move(other.__fbthrift_field_s);
    this->__fbthrift_field_id = std::move(other.__fbthrift_field_id);
    __isset = other.__isset;
    return *this;
}


BigStruct::BigStruct(apache::thrift::FragileConstructor, ::module2::Struct s__arg, ::std::int32_t id__arg) :
    __fbthrift_field_s(std::move(s__arg)),
    __fbthrift_field_id(std::move(id__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void BigStruct::__fbthrift_clear() {
  // clear all fields
  ::apache::thrift::clear(this->__fbthrift_field_s);
  this->__fbthrift_field_id = ::std::int32_t();
  __isset = {};
}

void BigStruct::__fbthrift_clear_terse_fields() {
}

bool BigStruct::__fbthrift_is_empty() const {
  return false;
}

bool BigStruct::operator==(FOLLY_MAYBE_UNUSED const BigStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool BigStruct::operator<(FOLLY_MAYBE_UNUSED const BigStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}

const ::module2::Struct& BigStruct::get_s() const& {
  return __fbthrift_field_s;
}

::module2::Struct BigStruct::get_s() && {
  return std::move(__fbthrift_field_s);
}


void swap(FOLLY_MAYBE_UNUSED BigStruct& a, FOLLY_MAYBE_UNUSED BigStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_s, b.__fbthrift_field_s);
  swap(a.__fbthrift_field_id, b.__fbthrift_field_id);
  swap(a.__isset, b.__isset);
}

template void BigStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t BigStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t BigStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t BigStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void BigStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t BigStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t BigStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t BigStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        BigStruct,
        ::apache::thrift::type_class::structure,
        ::module2::Struct>,
    "inconsistent use of json option");

} // module2

namespace module2 { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}} // module2
