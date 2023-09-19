/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/empty-struct/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/empty-struct/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/empty-struct/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/empty-struct/gen-cpp2/module_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Empty>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Empty>;
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

namespace cpp2 {

const folly::StringPiece Empty::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<Empty>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece Empty::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<Empty>::name;
}


Empty::Empty(apache::thrift::FragileConstructor) {}


void Empty::__fbthrift_clear() {
  // clear all fields
}

void Empty::__fbthrift_clear_terse_fields() {
}

bool Empty::__fbthrift_is_empty() const {
  return true;
}

bool Empty::operator==(FOLLY_MAYBE_UNUSED const Empty& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool Empty::operator<(FOLLY_MAYBE_UNUSED const Empty& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap(FOLLY_MAYBE_UNUSED Empty& a, FOLLY_MAYBE_UNUSED Empty& b) {
  using ::std::swap;
}

template void Empty::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Empty::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Empty::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Empty::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Empty::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Empty::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Empty::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Empty::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Nada>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Nada>;
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

namespace apache { namespace thrift {

#if FOLLY_CPLUSPLUS < 201703L
constexpr std::size_t const TEnumTraits<::cpp2::Nada::Type>::size;
#endif
folly::Range<::cpp2::Nada::Type const*> const TEnumTraits<::cpp2::Nada::Type>::values = folly::range(TEnumDataStorage<::cpp2::Nada::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::Nada::Type>::names = folly::range(TEnumDataStorage<::cpp2::Nada::Type>::names);

bool TEnumTraits<::cpp2::Nada::Type>::findName(type value, folly::StringPiece* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::cpp2::Nada::Type>::findValue(folly::StringPiece name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace cpp2 {

const folly::StringPiece Nada::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<Nada>::fields_names[folly::to_underlying(ord) - 1];
}
const folly::StringPiece Nada::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<Nada>::name;
}

void Nada::__fbthrift_clear() {
  // clear all fields
  if (getType() == Type::__EMPTY__) { return; }
  switch(getType()) {
    default:
      assert(false);
      break;
  }
  type_ = folly::to_underlying(Type::__EMPTY__);
}

bool Nada::__fbthrift_is_empty() const {
  return getType() == Type::__EMPTY__;
}

bool Nada::operator==(const Nada& rhs) const {
  return ::apache::thrift::op::detail::UnionEquality{}(*this, rhs);
}

bool Nada::operator<(FOLLY_MAYBE_UNUSED const Nada& rhs) const {
  FOLLY_MAYBE_UNUSED auto& lhs = *this;
  if (lhs.getType() != rhs.getType()) {
    return lhs.getType() < rhs.getType();
  }
  switch (lhs.getType()) {
    default:
      return false;
  }
}

void swap(Nada& a, Nada& b) {
  Nada temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void Nada::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Nada::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Nada::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Nada::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Nada::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Nada::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Nada::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Nada::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace cpp2 { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}} // cpp2
