/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module_no_uri.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/module_no_uri_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::cpp2::RefUnion> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).field1_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
