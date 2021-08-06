/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/tablebased/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::test::fixtures::tablebased::TrivialTypesStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).fieldA_ref()...);
    f(1, static_cast<T&&>(t).fieldB_ref()...);
    f(2, static_cast<T&&>(t).fieldC_ref()...);
    f(3, static_cast<T&&>(t).fieldD_ref()...);
    f(4, static_cast<T&&>(t).fieldE_ref()...);
  }
};

template <>
struct ForEachField<::test::fixtures::tablebased::ContainerStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).fieldA_ref()...);
    f(1, static_cast<T&&>(t).fieldB_ref()...);
    f(2, static_cast<T&&>(t).fieldC_ref()...);
    f(3, static_cast<T&&>(t).fieldD_ref()...);
    f(4, static_cast<T&&>(t).fieldE_ref()...);
    f(5, static_cast<T&&>(t).fieldF_ref()...);
    f(6, static_cast<T&&>(t).fieldG_ref()...);
    f(7, static_cast<T&&>(t).fieldH_ref()...);
  }
};

template <>
struct ForEachField<::test::fixtures::tablebased::ExampleUnion> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).fieldA_ref()...);
    f(1, static_cast<T&&>(t).fieldB_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
