/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/complex-struct/gen-cpp2/module_constants.h"

#include <thrift/lib/cpp2/gen/module_constants_cpp.h>


namespace cpp2 {

constexpr ::std::int32_t const module_constants::DEFAULT_PORT_NUM_;

::cpp2::MyUnion const& module_constants::constEnumUnion() {
  static folly::Indestructible<::cpp2::MyUnion> const instance(::apache::thrift::detail::make_constant< ::cpp2::MyUnion>(::apache::thrift::type_class::variant{}, ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::tag::myEnum>( ::cpp2::MyEnum::MyValue2)));
  return *instance;
}

} // cpp2
