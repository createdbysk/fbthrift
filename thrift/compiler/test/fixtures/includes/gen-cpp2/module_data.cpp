/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache {
namespace thrift {

const std::array<folly::StringPiece, 3> TStructDataStorage<::cpp2::MyStruct>::fields_names = {{
  "MyIncludedField",
  "MyOtherIncludedField",
  "MyIncludedInt",
}};
const std::array<int16_t, 3> TStructDataStorage<::cpp2::MyStruct>::fields_ids = {{
  1,
  2,
  3,
}};
const std::array<protocol::TType, 3> TStructDataStorage<::cpp2::MyStruct>::fields_types = {{
  TType::T_STRUCT,
  TType::T_STRUCT,
  TType::T_I64,
}};

} // namespace thrift
} // namespace apache
