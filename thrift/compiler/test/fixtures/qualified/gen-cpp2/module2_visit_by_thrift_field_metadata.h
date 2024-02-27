/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/qualified/src/module2.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module2_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::module2::Struct> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).first_ref());
    case 2:
      return f(1, static_cast<T&&>(t).second_ref());
    default:
      throwInvalidThriftId(fieldId, "::module2::Struct");
    }
  }
};

template <>
struct VisitByFieldId<::module2::BigStruct> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).s_ref());
    case 2:
      return f(1, static_cast<T&&>(t).id_ref());
    default:
      throwInvalidThriftId(fieldId, "::module2::BigStruct");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
