/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/visitation/visit_union.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitUnion<::test_cpp2::cpp_reflection::union1> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::ui:
      return f(0, *static_cast<T&&>(t).ui_ref());
    case Union::Type::ud:
      return f(1, *static_cast<T&&>(t).ud_ref());
    case Union::Type::us:
      return f(2, *static_cast<T&&>(t).us_ref());
    case Union::Type::ue:
      return f(3, *static_cast<T&&>(t).ue_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::test_cpp2::cpp_reflection::union2> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::ui_2:
      return f(0, *static_cast<T&&>(t).ui_2_ref());
    case Union::Type::ud_2:
      return f(1, *static_cast<T&&>(t).ud_2_ref());
    case Union::Type::us_2:
      return f(2, *static_cast<T&&>(t).us_2_ref());
    case Union::Type::ue_2:
      return f(3, *static_cast<T&&>(t).ue_2_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::test_cpp2::cpp_reflection::union3> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::ui_3:
      return f(0, *static_cast<T&&>(t).ui_3_ref());
    case Union::Type::ud_3:
      return f(1, *static_cast<T&&>(t).ud_3_ref());
    case Union::Type::us_3:
      return f(2, *static_cast<T&&>(t).us_3_ref());
    case Union::Type::ue_3:
      return f(3, *static_cast<T&&>(t).ue_3_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::test_cpp2::cpp_reflection::unionA> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::i:
      return f(0, *static_cast<T&&>(t).i_ref());
    case Union::Type::d:
      return f(1, *static_cast<T&&>(t).d_ref());
    case Union::Type::s:
      return f(2, *static_cast<T&&>(t).s_ref());
    case Union::Type::e:
      return f(3, *static_cast<T&&>(t).e_ref());
    case Union::Type::a:
      return f(4, *static_cast<T&&>(t).a_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
template <>
struct VisitUnion<::test_cpp2::cpp_reflection::union_with_special_names> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::get:
      return f(0, *static_cast<T&&>(t).get_ref());
    case Union::Type::getter:
      return f(1, *static_cast<T&&>(t).getter_ref());
    case Union::Type::lists:
      return f(2, *static_cast<T&&>(t).lists_ref());
    case Union::Type::maps:
      return f(3, *static_cast<T&&>(t).maps_ref());
    case Union::Type::name:
      return f(4, *static_cast<T&&>(t).name_ref());
    case Union::Type::name_to_value:
      return f(5, *static_cast<T&&>(t).name_to_value_ref());
    case Union::Type::names:
      return f(6, *static_cast<T&&>(t).names_ref());
    case Union::Type::prefix_tree:
      return f(7, *static_cast<T&&>(t).prefix_tree_ref());
    case Union::Type::sets:
      return f(8, *static_cast<T&&>(t).sets_ref());
    case Union::Type::setter:
      return f(9, *static_cast<T&&>(t).setter_ref());
    case Union::Type::str:
      return f(10, *static_cast<T&&>(t).str_ref());
    case Union::Type::strings:
      return f(11, *static_cast<T&&>(t).strings_ref());
    case Union::Type::type:
      return f(12, *static_cast<T&&>(t).type_ref());
    case Union::Type::value:
      return f(13, *static_cast<T&&>(t).value_ref());
    case Union::Type::value_to_name:
      return f(14, *static_cast<T&&>(t).value_to_name_ref());
    case Union::Type::values:
      return f(15, *static_cast<T&&>(t).values_ref());
    case Union::Type::id:
      return f(16, *static_cast<T&&>(t).id_ref());
    case Union::Type::ids:
      return f(17, *static_cast<T&&>(t).ids_ref());
    case Union::Type::descriptor:
      return f(18, *static_cast<T&&>(t).descriptor_ref());
    case Union::Type::descriptors:
      return f(19, *static_cast<T&&>(t).descriptors_ref());
    case Union::Type::key:
      return f(20, *static_cast<T&&>(t).key_ref());
    case Union::Type::keys:
      return f(21, *static_cast<T&&>(t).keys_ref());
    case Union::Type::annotation:
      return f(22, *static_cast<T&&>(t).annotation_ref());
    case Union::Type::annotations:
      return f(23, *static_cast<T&&>(t).annotations_ref());
    case Union::Type::member:
      return f(24, *static_cast<T&&>(t).member_ref());
    case Union::Type::members:
      return f(25, *static_cast<T&&>(t).members_ref());
    case Union::Type::field:
      return f(26, *static_cast<T&&>(t).field_ref());
    case Union::Type::fields:
      return f(27, *static_cast<T&&>(t).fields_ref());
    case Union::Type::__EMPTY__: ;
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
