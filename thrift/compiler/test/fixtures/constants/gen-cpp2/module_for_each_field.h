/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/constants/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/constants/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::cpp2::Internship> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).weeks_ref()...);
    f(1, static_cast<T&&>(t).title_ref()...);
    f(2, static_cast<T&&>(t).employer_ref()...);
    f(3, static_cast<T&&>(t).compensation_ref()...);
    f(4, static_cast<T&&>(t).school_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::Range> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).min_ref()...);
    f(1, static_cast<T&&>(t).max_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::struct1> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).a_ref()...);
    f(1, static_cast<T&&>(t).b_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::struct2> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).a_ref()...);
    f(1, static_cast<T&&>(t).b_ref()...);
    f(2, static_cast<T&&>(t).c_ref()...);
    f(3, static_cast<T&&>(t).d_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::struct3> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).a_ref()...);
    f(1, static_cast<T&&>(t).b_ref()...);
    f(2, static_cast<T&&>(t).c_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::struct4> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).a_ref()...);
    f(1, static_cast<T&&>(t).b_ref()...);
    f(2, static_cast<T&&>(t).c_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::union1> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).i_ref()...);
    f(1, static_cast<T&&>(t).d_ref()...);
  }
};

template <>
struct ForEachField<::cpp2::union2> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).i_ref()...);
    f(1, static_cast<T&&>(t).d_ref()...);
    f(2, static_cast<T&&>(t).s_ref()...);
    f(3, static_cast<T&&>(t).u_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
