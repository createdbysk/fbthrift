/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/frozen-struct/src/include1.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/compiler/test/fixtures/frozen-struct/gen-cpp2/include1_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::some::ns::IncludedA> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).i32Field_ref());
    case 2:
      return f(1, static_cast<T&&>(t).strField_ref());
    default:
      throwInvalidThriftId(fieldId, "::some::ns::IncludedA");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
