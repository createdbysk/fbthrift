/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/doctext/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);

void EnumMetadata<::cpp2::B>::gen(ThriftMetadata& metadata) {
  auto res = metadata.enums_ref()->emplace("module.B", ::apache::thrift::metadata::ThriftEnum{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftEnum& enum_metadata = res.first->second;
  enum_metadata.name_ref() = "module.B";
  using EnumTraits = TEnumTraits<::cpp2::B>;
  for (std::size_t i = 0; i < EnumTraits::size; ++i) {
    enum_metadata.elements_ref()->emplace(static_cast<int32_t>(EnumTraits::values[i]), EnumTraits::names[i].str());
  }
}

const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::A>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.A", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_A = res.first->second;
  module_A.name_ref() = "module.A";
  module_A.is_union_ref() = false;
  static const EncodedThriftField
  module_A_fields[] = {
    {1, "useless_field", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::vector<ThriftConstStruct>{}},
  };
  for (const auto& f : module_A_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = f.id;
    field.name_ref() = f.name;
    field.is_optional_ref() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type_ref(), metadata);
    field.structured_annotations_ref() = f.structured_annotations;
    module_A.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::U>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.U", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_U = res.first->second;
  module_U.name_ref() = "module.U";
  module_U.is_union_ref() = true;
  static const EncodedThriftField
  module_U_fields[] = {
    {1, "i", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE), std::vector<ThriftConstStruct>{}},
    {2, "s", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  };
  for (const auto& f : module_U_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = f.id;
    field.name_ref() = f.name;
    field.is_optional_ref() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type_ref(), metadata);
    field.structured_annotations_ref() = f.structured_annotations;
    module_U.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::Bang>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.Bang", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_Bang = res.first->second;
  module_Bang.name_ref() = "module.Bang";
  module_Bang.is_union_ref() = false;
  static const EncodedThriftField
  module_Bang_fields[] = {
    {1, "message", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  };
  for (const auto& f : module_Bang_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = f.id;
    field.name_ref() = f.name;
    field.is_optional_ref() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type_ref(), metadata);
    field.structured_annotations_ref() = f.structured_annotations;
    module_Bang.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}

void ExceptionMetadata<::cpp2::Bang>::gen(ThriftMetadata& metadata) {
  auto res = metadata.exceptions_ref()->emplace("module.Bang", ::apache::thrift::metadata::ThriftException{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftException& module_Bang = res.first->second;
  module_Bang.name_ref() = "module.Bang";
  static const EncodedThriftField
  module_Bang_fields[] = {
    {1, "message", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE), std::vector<ThriftConstStruct>{}},
  };
  for (const auto& f : module_Bang_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = f.id;
    field.name_ref() = f.name;
    field.is_optional_ref() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type_ref(), metadata);
    module_Bang.fields_ref()->push_back(std::move(field));
  }
}
void ServiceMetadata<::cpp2::CSvIf>::gen_f(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "f";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::CSvIf>::gen_numbers(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "numbers";
  auto func_ret_type = std::make_unique<Stream>(std::make_unique<Typedef>("module.number", std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE)));
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::CSvIf>::gen_thing(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "thing";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  ::apache::thrift::metadata::ThriftField module_C_thing_a_1;
  module_C_thing_a_1.id_ref() = 1;
  module_C_thing_a_1.name_ref() = "a";
  module_C_thing_a_1.is_optional_ref() = false;
  auto module_C_thing_a_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE);
  module_C_thing_a_1_type->writeAndGenType(*module_C_thing_a_1.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_C_thing_a_1));
  ::apache::thrift::metadata::ThriftField module_C_thing_b_2;
  module_C_thing_b_2.id_ref() = 2;
  module_C_thing_b_2.name_ref() = "b";
  module_C_thing_b_2.is_optional_ref() = false;
  auto module_C_thing_b_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  module_C_thing_b_2_type->writeAndGenType(*module_C_thing_b_2.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_C_thing_b_2));
  ::apache::thrift::metadata::ThriftField module_C_thing_c_3;
  module_C_thing_c_3.id_ref() = 3;
  module_C_thing_c_3.name_ref() = "c";
  module_C_thing_c_3.is_optional_ref() = false;
  auto module_C_thing_c_3_type = std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I32_TYPE));
  module_C_thing_c_3_type->writeAndGenType(*module_C_thing_c_3.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_C_thing_c_3));
  ::apache::thrift::metadata::ThriftField module_C_thing_bang_1;
  module_C_thing_bang_1.id_ref() = 1;
  module_C_thing_bang_1.name_ref() = "bang";
  module_C_thing_bang_1.is_optional_ref() = false;
  auto module_C_thing_bang_1_type = std::make_unique<Struct< ::cpp2::Bang>>("module.Bang");
  module_C_thing_bang_1_type->writeAndGenType(*module_C_thing_bang_1.type_ref(), metadata);
  func.exceptions_ref()->push_back(std::move(module_C_thing_bang_1));
  ExceptionMetadata< ::cpp2::Bang>::gen(metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}

void ServiceMetadata<::cpp2::CSvIf>::gen(::apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  const ::apache::thrift::metadata::ThriftServiceContextRef* self = genRecurse(*response.metadata_ref(), *response.services_ref());
  DCHECK(self != nullptr);
  // TODO(praihan): Remove ThriftServiceContext from response. But in the meantime, we need to fill the field with the result of looking up in ThriftMetadata.
  ::apache::thrift::metadata::ThriftServiceContext context;
  context.module_ref() = *self->module_ref();
  context.service_info_ref() = response.metadata_ref()->services_ref()->at(*self->service_name_ref());
  response.context_ref() = std::move(context);
}

const ThriftServiceContextRef* ServiceMetadata<::cpp2::CSvIf>::genRecurse(ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services) {
  (void) metadata;
  ::apache::thrift::metadata::ThriftService module_C;
  module_C.name_ref() = "module.C";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::cpp2::CSvIf>::gen_f,
    ServiceMetadata<::cpp2::CSvIf>::gen_numbers,
    ServiceMetadata<::cpp2::CSvIf>::gen_thing,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, module_C);
  }
  // We need to keep the index around because a reference or iterator could be invalidated.
  auto selfIndex = services.size();
  services.emplace_back();
  ThriftServiceContextRef& context = services[selfIndex];
  metadata.services_ref()->emplace("module.C", std::move(module_C));
  context.service_name_ref() = "module.C";
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.name_ref() = "module";
  context.module_ref() = std::move(module);
  return &context;
}
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
