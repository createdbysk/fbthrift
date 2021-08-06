/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/visitation/visit_union.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitUnion<::cpp2::MyUnion> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::first:
      return f(0, *static_cast<T&&>(t).first_ref());
    case Union::Type::second:
      return f(1, *static_cast<T&&>(t).second_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
