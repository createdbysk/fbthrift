/**
 * Autogenerated by Thrift for src/terse_writes.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/lazy_deserialization/gen-cpp2/terse_writes_types.h"
#include "thrift/compiler/test/fixtures/lazy_deserialization/gen-cpp2/terse_writes_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/lazy_deserialization/gen-cpp2/terse_writes_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::test::TerseFoo>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::test::TerseFoo>;
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

namespace apache { namespace thrift { namespace test {

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseFoo::TerseFoo(const TerseFoo&) = default;
TerseFoo& TerseFoo::operator=(const TerseFoo&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseFoo::TerseFoo(TerseFoo&& other) noexcept  :
    field1(std::move(other.field1)),
    field2(std::move(other.field2)),
    field3(std::move(other.field3)),
    field4(std::move(other.field4)),
    __isset(other.__isset) {}
TerseFoo& TerseFoo::operator=(FOLLY_MAYBE_UNUSED TerseFoo&& other) noexcept {
    this->field1 = std::move(other.field1);
    this->field2 = std::move(other.field2);
    this->field3 = std::move(other.field3);
    this->field4 = std::move(other.field4);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseFoo::TerseFoo(apache::thrift::FragileConstructor, ::std::vector<double> field1__arg, ::std::vector<::std::int32_t> field2__arg, ::std::vector<double> field3__arg, ::std::vector<::std::int32_t> field4__arg) :
    field1(std::move(field1__arg)),
    field2(std::move(field2__arg)),
    field3(std::move(field3__arg)),
    field4(std::move(field4__arg)) {
  __isset.field1 = true;
  __isset.field2 = true;
  __isset.field3 = true;
  __isset.field4 = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END

void TerseFoo::__clear() {
  // clear all fields
  this->field1.clear();
  this->field2.clear();
  this->field3.clear();
  this->field4.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool TerseFoo::operator==(const TerseFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return false;
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return false;
  }
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return false;
  }
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return false;
  }
  return true;
}

bool TerseFoo::operator<(const TerseFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return lhs.field1_ref() < rhs.field1_ref();
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return lhs.field2_ref() < rhs.field2_ref();
  }
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return lhs.field3_ref() < rhs.field3_ref();
  }
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return lhs.field4_ref() < rhs.field4_ref();
  }
  return false;
}

const ::std::vector<double>& TerseFoo::get_field1() const& {
  return field1;
}

::std::vector<double> TerseFoo::get_field1() && {
  return std::move(field1);
}

const ::std::vector<::std::int32_t>& TerseFoo::get_field2() const& {
  return field2;
}

::std::vector<::std::int32_t> TerseFoo::get_field2() && {
  return std::move(field2);
}

const ::std::vector<double>& TerseFoo::get_field3() const& {
  return field3;
}

::std::vector<double> TerseFoo::get_field3() && {
  return std::move(field3);
}

const ::std::vector<::std::int32_t>& TerseFoo::get_field4() const& {
  return field4;
}

::std::vector<::std::int32_t> TerseFoo::get_field4() && {
  return std::move(field4);
}


void swap(TerseFoo& a, TerseFoo& b) {
  using ::std::swap;
  swap(a.field1_ref().value(), b.field1_ref().value());
  swap(a.field2_ref().value(), b.field2_ref().value());
  swap(a.field3_ref().value(), b.field3_ref().value());
  swap(a.field4_ref().value(), b.field4_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void TerseFoo::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TerseFoo::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TerseFoo::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TerseFoo::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void TerseFoo::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TerseFoo::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TerseFoo::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TerseFoo::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



}}} // apache::thrift::test

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::test::TerseLazyFoo>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::test::TerseLazyFoo>;
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

namespace apache { namespace thrift { namespace test {

TerseLazyFoo::TerseLazyFoo(const TerseLazyFoo& srcObj) {
  std::lock_guard<std::mutex> lock(srcObj.__fbthrift_deserializationMutex_);
  __fbthrift_protocol_ = srcObj.__fbthrift_protocol_;
  __fbthrift_serializedData_ = srcObj.__fbthrift_serializedData_;
  field1 = srcObj.field1;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field1 = srcObj.__isset.field1;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  field2 = srcObj.field2;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field2 = srcObj.__isset.field2;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  __fbthrift_isDeserialized_.field3.store(srcObj.__fbthrift_isDeserialized_.field3.load(std::memory_order::memory_order_relaxed),
                                                      std::memory_order::memory_order_relaxed);
  field3 = srcObj.field3;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field3 = srcObj.__isset.field3;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  __fbthrift_isDeserialized_.field4.store(srcObj.__fbthrift_isDeserialized_.field4.load(std::memory_order::memory_order_relaxed),
                                                      std::memory_order::memory_order_relaxed);
  field4 = srcObj.field4;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field4 = srcObj.__isset.field4;
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

TerseLazyFoo& TerseLazyFoo::operator=(const TerseLazyFoo& src) {
  TerseLazyFoo tmp(src);
  swap(*this, tmp);
  return *this;
}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseLazyFoo::TerseLazyFoo(TerseLazyFoo&& other) noexcept  :
    field1(std::move(other.field1)),
    field2(std::move(other.field2)),
    field3(std::move(other.field3)),
    field4(std::move(other.field4)),
    __isset(other.__isset),
    __fbthrift_protocol_(other.__fbthrift_protocol_),
    __fbthrift_serializedData_(std::move(other.__fbthrift_serializedData_)) {
  const auto relaxed = std::memory_order::memory_order_relaxed;
  __fbthrift_isDeserialized_.field3.store(other.__fbthrift_isDeserialized_.field3, relaxed);
  other.__fbthrift_isDeserialized_.field3.store(true, relaxed);
  __fbthrift_isDeserialized_.field4.store(other.__fbthrift_isDeserialized_.field4, relaxed);
  other.__fbthrift_isDeserialized_.field4.store(true, relaxed);
}
TerseLazyFoo& TerseLazyFoo::operator=(FOLLY_MAYBE_UNUSED TerseLazyFoo&& other) noexcept {
    const auto relaxed = std::memory_order::memory_order_relaxed;
    __fbthrift_protocol_ = other.__fbthrift_protocol_;
    __fbthrift_serializedData_ = std::move(other.__fbthrift_serializedData_);
    this->field1 = std::move(other.field1);
    this->field2 = std::move(other.field2);
    this->field3 = std::move(other.field3);
    __fbthrift_isDeserialized_.field3.store(other.__fbthrift_isDeserialized_.field3.exchange(true), relaxed);
    this->field4 = std::move(other.field4);
    __fbthrift_isDeserialized_.field4.store(other.__fbthrift_isDeserialized_.field4.exchange(true), relaxed);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseLazyFoo::TerseLazyFoo(apache::thrift::FragileConstructor, ::std::vector<double> field1__arg, ::std::vector<::std::int32_t> field2__arg, ::std::vector<double> field3__arg, ::std::vector<::std::int32_t> field4__arg) :
    field1(std::move(field1__arg)),
    field2(std::move(field2__arg)),
    field3(std::move(field3__arg)),
    field4(std::move(field4__arg)) {
  __isset.field1 = true;
  __isset.field2 = true;
  __isset.field3 = true;
  __isset.field4 = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
const ::std::vector<double>& TerseLazyFoo::__fbthrift_read_field_field3() const {

  if (__fbthrift_isDeserialized_.field3) {
    return field3;
  }

  std::lock_guard<std::mutex> lock(__fbthrift_deserializationMutex_);
  if (!__fbthrift_isDeserialized_.field3) {
    switch (__fbthrift_protocol_) {
      case ::apache::thrift::protocol::T_COMPACT_PROTOCOL:
        __fbthrift_read_field_field3_impl<::apache::thrift::CompactProtocolReader>();
        break;
      case ::apache::thrift::protocol::T_BINARY_PROTOCOL:
        __fbthrift_read_field_field3_impl<::apache::thrift::BinaryProtocolReader>();
        break;
      default:
        CHECK(false) << int(__fbthrift_protocol_);
    }
    __fbthrift_isDeserialized_.field3 = true;
  }
  return field3;
}

::std::vector<double>& TerseLazyFoo::__fbthrift_read_field_field3() {
  std::as_const(*this).__fbthrift_read_field_field3();
  return field3;
}
const ::std::vector<::std::int32_t>& TerseLazyFoo::__fbthrift_read_field_field4() const {

  if (__fbthrift_isDeserialized_.field4) {
    return field4;
  }

  std::lock_guard<std::mutex> lock(__fbthrift_deserializationMutex_);
  if (!__fbthrift_isDeserialized_.field4) {
    switch (__fbthrift_protocol_) {
      case ::apache::thrift::protocol::T_COMPACT_PROTOCOL:
        __fbthrift_read_field_field4_impl<::apache::thrift::CompactProtocolReader>();
        break;
      case ::apache::thrift::protocol::T_BINARY_PROTOCOL:
        __fbthrift_read_field_field4_impl<::apache::thrift::BinaryProtocolReader>();
        break;
      default:
        CHECK(false) << int(__fbthrift_protocol_);
    }
    __fbthrift_isDeserialized_.field4 = true;
  }
  return field4;
}

::std::vector<::std::int32_t>& TerseLazyFoo::__fbthrift_read_field_field4() {
  std::as_const(*this).__fbthrift_read_field_field4();
  return field4;
}

void TerseLazyFoo::__clear() {
  // clear all fields
  this->field1.clear();
  this->field2.clear();
  this->field3.clear();
  this->field4.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool TerseLazyFoo::operator==(const TerseLazyFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return false;
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return false;
  }
  lhs.field3_ref();
  rhs.field3_ref();
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return false;
  }
  lhs.field4_ref();
  rhs.field4_ref();
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return false;
  }
  return true;
}

bool TerseLazyFoo::operator<(const TerseLazyFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return lhs.field1_ref() < rhs.field1_ref();
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return lhs.field2_ref() < rhs.field2_ref();
  }
  lhs.field3_ref();
  rhs.field3_ref();
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return lhs.field3_ref() < rhs.field3_ref();
  }
  lhs.field4_ref();
  rhs.field4_ref();
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return lhs.field4_ref() < rhs.field4_ref();
  }
  return false;
}

const ::std::vector<double>& TerseLazyFoo::get_field1() const& {
  return field1;
}

::std::vector<double> TerseLazyFoo::get_field1() && {
  return std::move(field1);
}

const ::std::vector<::std::int32_t>& TerseLazyFoo::get_field2() const& {
  return field2;
}

::std::vector<::std::int32_t> TerseLazyFoo::get_field2() && {
  return std::move(field2);
}


void swap(TerseLazyFoo& a, TerseLazyFoo& b) {
  using ::std::swap;
  swap(a.field1_ref().value(), b.field1_ref().value());
  swap(a.field2_ref().value(), b.field2_ref().value());
  swap(a.field3_ref().value(), b.field3_ref().value());
  swap(a.field4_ref().value(), b.field4_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void TerseLazyFoo::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TerseLazyFoo::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TerseLazyFoo::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TerseLazyFoo::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void TerseLazyFoo::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TerseLazyFoo::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TerseLazyFoo::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TerseLazyFoo::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



}}} // apache::thrift::test

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::test::TerseOptionalFoo>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::test::TerseOptionalFoo>;
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

namespace apache { namespace thrift { namespace test {

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseOptionalFoo::TerseOptionalFoo(const TerseOptionalFoo&) = default;
TerseOptionalFoo& TerseOptionalFoo::operator=(const TerseOptionalFoo&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseOptionalFoo::TerseOptionalFoo(TerseOptionalFoo&& other) noexcept  :
    field1(std::move(other.field1)),
    field2(std::move(other.field2)),
    field3(std::move(other.field3)),
    field4(std::move(other.field4)),
    __isset(other.__isset) {}
TerseOptionalFoo& TerseOptionalFoo::operator=(FOLLY_MAYBE_UNUSED TerseOptionalFoo&& other) noexcept {
    this->field1 = std::move(other.field1);
    this->field2 = std::move(other.field2);
    this->field3 = std::move(other.field3);
    this->field4 = std::move(other.field4);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseOptionalFoo::TerseOptionalFoo(apache::thrift::FragileConstructor, ::std::vector<double> field1__arg, ::std::vector<::std::int32_t> field2__arg, ::std::vector<double> field3__arg, ::std::vector<::std::int32_t> field4__arg) :
    field1(std::move(field1__arg)),
    field2(std::move(field2__arg)),
    field3(std::move(field3__arg)),
    field4(std::move(field4__arg)) {
  __isset.field1 = true;
  __isset.field2 = true;
  __isset.field3 = true;
  __isset.field4 = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END

void TerseOptionalFoo::__clear() {
  // clear all fields
  this->field1.clear();
  this->field2.clear();
  this->field3.clear();
  this->field4.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool TerseOptionalFoo::operator==(const TerseOptionalFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return false;
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return false;
  }
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return false;
  }
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return false;
  }
  return true;
}

bool TerseOptionalFoo::operator<(const TerseOptionalFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return lhs.field1_ref() < rhs.field1_ref();
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return lhs.field2_ref() < rhs.field2_ref();
  }
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return lhs.field3_ref() < rhs.field3_ref();
  }
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return lhs.field4_ref() < rhs.field4_ref();
  }
  return false;
}

const ::std::vector<double>* TerseOptionalFoo::get_field1() const& {
  return field1_ref().has_value() ? std::addressof(field1) : nullptr;
}

::std::vector<double>* TerseOptionalFoo::get_field1() & {
  return field1_ref().has_value() ? std::addressof(field1) : nullptr;
}

const ::std::vector<::std::int32_t>* TerseOptionalFoo::get_field2() const& {
  return field2_ref().has_value() ? std::addressof(field2) : nullptr;
}

::std::vector<::std::int32_t>* TerseOptionalFoo::get_field2() & {
  return field2_ref().has_value() ? std::addressof(field2) : nullptr;
}

const ::std::vector<double>* TerseOptionalFoo::get_field3() const& {
  return field3_ref().has_value() ? std::addressof(field3) : nullptr;
}

::std::vector<double>* TerseOptionalFoo::get_field3() & {
  return field3_ref().has_value() ? std::addressof(field3) : nullptr;
}

const ::std::vector<::std::int32_t>* TerseOptionalFoo::get_field4() const& {
  return field4_ref().has_value() ? std::addressof(field4) : nullptr;
}

::std::vector<::std::int32_t>* TerseOptionalFoo::get_field4() & {
  return field4_ref().has_value() ? std::addressof(field4) : nullptr;
}


void swap(TerseOptionalFoo& a, TerseOptionalFoo& b) {
  using ::std::swap;
  swap(a.field1_ref().value_unchecked(), b.field1_ref().value_unchecked());
  swap(a.field2_ref().value_unchecked(), b.field2_ref().value_unchecked());
  swap(a.field3_ref().value_unchecked(), b.field3_ref().value_unchecked());
  swap(a.field4_ref().value_unchecked(), b.field4_ref().value_unchecked());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void TerseOptionalFoo::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TerseOptionalFoo::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TerseOptionalFoo::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TerseOptionalFoo::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void TerseOptionalFoo::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TerseOptionalFoo::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TerseOptionalFoo::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TerseOptionalFoo::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



}}} // apache::thrift::test

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::test::TerseOptionalLazyFoo>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::test::TerseOptionalLazyFoo>;
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

namespace apache { namespace thrift { namespace test {

TerseOptionalLazyFoo::TerseOptionalLazyFoo(const TerseOptionalLazyFoo& srcObj) {
  std::lock_guard<std::mutex> lock(srcObj.__fbthrift_deserializationMutex_);
  __fbthrift_protocol_ = srcObj.__fbthrift_protocol_;
  __fbthrift_serializedData_ = srcObj.__fbthrift_serializedData_;
  field1 = srcObj.field1;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field1 = srcObj.__isset.field1;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  field2 = srcObj.field2;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field2 = srcObj.__isset.field2;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  __fbthrift_isDeserialized_.field3.store(srcObj.__fbthrift_isDeserialized_.field3.load(std::memory_order::memory_order_relaxed),
                                                      std::memory_order::memory_order_relaxed);
  field3 = srcObj.field3;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field3 = srcObj.__isset.field3;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  __fbthrift_isDeserialized_.field4.store(srcObj.__fbthrift_isDeserialized_.field4.load(std::memory_order::memory_order_relaxed),
                                                      std::memory_order::memory_order_relaxed);
  field4 = srcObj.field4;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset.field4 = srcObj.__isset.field4;
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

TerseOptionalLazyFoo& TerseOptionalLazyFoo::operator=(const TerseOptionalLazyFoo& src) {
  TerseOptionalLazyFoo tmp(src);
  swap(*this, tmp);
  return *this;
}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseOptionalLazyFoo::TerseOptionalLazyFoo(TerseOptionalLazyFoo&& other) noexcept  :
    field1(std::move(other.field1)),
    field2(std::move(other.field2)),
    field3(std::move(other.field3)),
    field4(std::move(other.field4)),
    __isset(other.__isset),
    __fbthrift_protocol_(other.__fbthrift_protocol_),
    __fbthrift_serializedData_(std::move(other.__fbthrift_serializedData_)) {
  const auto relaxed = std::memory_order::memory_order_relaxed;
  __fbthrift_isDeserialized_.field3.store(other.__fbthrift_isDeserialized_.field3, relaxed);
  other.__fbthrift_isDeserialized_.field3.store(true, relaxed);
  __fbthrift_isDeserialized_.field4.store(other.__fbthrift_isDeserialized_.field4, relaxed);
  other.__fbthrift_isDeserialized_.field4.store(true, relaxed);
}
TerseOptionalLazyFoo& TerseOptionalLazyFoo::operator=(FOLLY_MAYBE_UNUSED TerseOptionalLazyFoo&& other) noexcept {
    const auto relaxed = std::memory_order::memory_order_relaxed;
    __fbthrift_protocol_ = other.__fbthrift_protocol_;
    __fbthrift_serializedData_ = std::move(other.__fbthrift_serializedData_);
    this->field1 = std::move(other.field1);
    this->field2 = std::move(other.field2);
    this->field3 = std::move(other.field3);
    __fbthrift_isDeserialized_.field3.store(other.__fbthrift_isDeserialized_.field3.exchange(true), relaxed);
    this->field4 = std::move(other.field4);
    __fbthrift_isDeserialized_.field4.store(other.__fbthrift_isDeserialized_.field4.exchange(true), relaxed);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
TerseOptionalLazyFoo::TerseOptionalLazyFoo(apache::thrift::FragileConstructor, ::std::vector<double> field1__arg, ::std::vector<::std::int32_t> field2__arg, ::std::vector<double> field3__arg, ::std::vector<::std::int32_t> field4__arg) :
    field1(std::move(field1__arg)),
    field2(std::move(field2__arg)),
    field3(std::move(field3__arg)),
    field4(std::move(field4__arg)) {
  __isset.field1 = true;
  __isset.field2 = true;
  __isset.field3 = true;
  __isset.field4 = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
const ::std::vector<double>& TerseOptionalLazyFoo::__fbthrift_read_field_field3() const {

  if (__fbthrift_isDeserialized_.field3) {
    return field3;
  }

  std::lock_guard<std::mutex> lock(__fbthrift_deserializationMutex_);
  if (!__fbthrift_isDeserialized_.field3) {
    switch (__fbthrift_protocol_) {
      case ::apache::thrift::protocol::T_COMPACT_PROTOCOL:
        __fbthrift_read_field_field3_impl<::apache::thrift::CompactProtocolReader>();
        break;
      case ::apache::thrift::protocol::T_BINARY_PROTOCOL:
        __fbthrift_read_field_field3_impl<::apache::thrift::BinaryProtocolReader>();
        break;
      default:
        CHECK(false) << int(__fbthrift_protocol_);
    }
    __fbthrift_isDeserialized_.field3 = true;
  }
  return field3;
}

::std::vector<double>& TerseOptionalLazyFoo::__fbthrift_read_field_field3() {
  std::as_const(*this).__fbthrift_read_field_field3();
  return field3;
}
const ::std::vector<::std::int32_t>& TerseOptionalLazyFoo::__fbthrift_read_field_field4() const {

  if (__fbthrift_isDeserialized_.field4) {
    return field4;
  }

  std::lock_guard<std::mutex> lock(__fbthrift_deserializationMutex_);
  if (!__fbthrift_isDeserialized_.field4) {
    switch (__fbthrift_protocol_) {
      case ::apache::thrift::protocol::T_COMPACT_PROTOCOL:
        __fbthrift_read_field_field4_impl<::apache::thrift::CompactProtocolReader>();
        break;
      case ::apache::thrift::protocol::T_BINARY_PROTOCOL:
        __fbthrift_read_field_field4_impl<::apache::thrift::BinaryProtocolReader>();
        break;
      default:
        CHECK(false) << int(__fbthrift_protocol_);
    }
    __fbthrift_isDeserialized_.field4 = true;
  }
  return field4;
}

::std::vector<::std::int32_t>& TerseOptionalLazyFoo::__fbthrift_read_field_field4() {
  std::as_const(*this).__fbthrift_read_field_field4();
  return field4;
}

void TerseOptionalLazyFoo::__clear() {
  // clear all fields
  this->field1.clear();
  this->field2.clear();
  this->field3.clear();
  this->field4.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool TerseOptionalLazyFoo::operator==(const TerseOptionalLazyFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return false;
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return false;
  }
  lhs.field3_ref();
  rhs.field3_ref();
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return false;
  }
  lhs.field4_ref();
  rhs.field4_ref();
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return false;
  }
  return true;
}

bool TerseOptionalLazyFoo::operator<(const TerseOptionalLazyFoo& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.field1_ref() == rhs.field1_ref())) {
    return lhs.field1_ref() < rhs.field1_ref();
  }
  if (!(lhs.field2_ref() == rhs.field2_ref())) {
    return lhs.field2_ref() < rhs.field2_ref();
  }
  lhs.field3_ref();
  rhs.field3_ref();
  if (!(lhs.field3_ref() == rhs.field3_ref())) {
    return lhs.field3_ref() < rhs.field3_ref();
  }
  lhs.field4_ref();
  rhs.field4_ref();
  if (!(lhs.field4_ref() == rhs.field4_ref())) {
    return lhs.field4_ref() < rhs.field4_ref();
  }
  return false;
}

const ::std::vector<double>* TerseOptionalLazyFoo::get_field1() const& {
  return field1_ref().has_value() ? std::addressof(field1) : nullptr;
}

::std::vector<double>* TerseOptionalLazyFoo::get_field1() & {
  return field1_ref().has_value() ? std::addressof(field1) : nullptr;
}

const ::std::vector<::std::int32_t>* TerseOptionalLazyFoo::get_field2() const& {
  return field2_ref().has_value() ? std::addressof(field2) : nullptr;
}

::std::vector<::std::int32_t>* TerseOptionalLazyFoo::get_field2() & {
  return field2_ref().has_value() ? std::addressof(field2) : nullptr;
}


void swap(TerseOptionalLazyFoo& a, TerseOptionalLazyFoo& b) {
  using ::std::swap;
  swap(a.field1_ref().value_unchecked(), b.field1_ref().value_unchecked());
  swap(a.field2_ref().value_unchecked(), b.field2_ref().value_unchecked());
  swap(a.field3_ref().value_unchecked(), b.field3_ref().value_unchecked());
  swap(a.field4_ref().value_unchecked(), b.field4_ref().value_unchecked());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void TerseOptionalLazyFoo::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TerseOptionalLazyFoo::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TerseOptionalLazyFoo::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TerseOptionalLazyFoo::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void TerseOptionalLazyFoo::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TerseOptionalLazyFoo::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TerseOptionalLazyFoo::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TerseOptionalLazyFoo::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



}}} // apache::thrift::test
