/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/basic-enum/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::test::fixtures::enumstrict::EmptyEnum> {
  using type = ::test::fixtures::enumstrict::EmptyEnum;
  static constexpr const std::size_t size = 0;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TEnumDataStorage<::test::fixtures::enumstrict::MyEnum> {
  using type = ::test::fixtures::enumstrict::MyEnum;
  static constexpr const std::size_t size = 2;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TEnumDataStorage<::test::fixtures::enumstrict::MyBigEnum> {
  using type = ::test::fixtures::enumstrict::MyBigEnum;
  static constexpr const std::size_t size = 20;
  static const std::array<type, size> values;
  static const std::array<folly::StringPiece, size> names;
};

template <> struct TStructDataStorage<::test::fixtures::enumstrict::MyStruct> {
  static constexpr const std::size_t fields_size = 2;
  static const std::array<folly::StringPiece, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;
};

}} // apache::thrift
