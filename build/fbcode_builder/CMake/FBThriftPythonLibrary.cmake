# Copyright (c) Facebook, Inc. and its affiliates.

include(FBCMakeParseArgs)
include(FBPythonBinary)

# Generate a Python library from a thrift file using thrift-python (mstch_python)
#
# Usage:
#   add_fbthrift_python_library(
#     my_thrift_lib
#     my_service.thrift
#     SERVICES MyService
#     DEPENDS other_thrift_lib
#   )
#
function(add_fbthrift_python_library LIB_NAME THRIFT_FILE)
  # Parse the arguments
  set(one_value_args NAMESPACE THRIFT_INCLUDE_DIR)
  set(multi_value_args SERVICES DEPENDS OPTIONS)
  fb_cmake_parse_args(
    ARG "" "${one_value_args}" "${multi_value_args}" "${ARGN}"
  )

  if(NOT DEFINED ARG_THRIFT_INCLUDE_DIR)
    set(ARG_THRIFT_INCLUDE_DIR "include/thrift-files")
  endif()

  get_filename_component(base ${THRIFT_FILE} NAME_WE)
  set(output_dir "${CMAKE_CURRENT_BINARY_DIR}/${THRIFT_FILE}-python")

  # Parse the namespace value - thrift-python uses the thrift file's namespace
  if (NOT DEFINED ARG_NAMESPACE)
    set(ARG_NAMESPACE "${base}")
  endif()

  string(REPLACE "." "/" namespace_dir "${ARG_NAMESPACE}")
  set(python_output_dir "${output_dir}/gen-python/${namespace_dir}")

  # thrift-python generates these files unconditionally:
  list(APPEND generated_sources
    "${python_output_dir}/thrift_types.py"
    "${python_output_dir}/thrift_types.pyi"
    "${python_output_dir}/thrift_metadata.py"
    "${python_output_dir}/thrift_enums.py"
    "${python_output_dir}/thrift_abstract_types.py"
    "${python_output_dir}/thrift_mutable_types.py"
    "${python_output_dir}/thrift_mutable_types.pyi"
  )

  # If there are services, additional files are generated
  if(ARG_SERVICES)
    list(APPEND generated_sources
      "${python_output_dir}/thrift_services.py"
      "${python_output_dir}/thrift_clients.py"
      "${python_output_dir}/thrift_mutable_services.py"
      "${python_output_dir}/thrift_mutable_clients.py"
    )
  endif()

  # Define a dummy interface library to help propagate the thrift include
  # directories between dependencies.
  add_library("${LIB_NAME}.thrift_includes" INTERFACE)
  target_include_directories(
    "${LIB_NAME}.thrift_includes"
    INTERFACE
      "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
      "$<INSTALL_INTERFACE:${ARG_THRIFT_INCLUDE_DIR}>"
  )
  foreach(dep IN LISTS ARG_DEPENDS)
    target_link_libraries(
      "${LIB_NAME}.thrift_includes"
      INTERFACE "${dep}.thrift_includes"
    )
  endforeach()

  # This generator expression gets the list of include directories required
  # for all of our dependencies.
  if (NOT POLICY CMP0067)
    message(FATAL_ERROR "add_fbthrift_python_library() requires CMake 3.8+")
  endif()
  set(
    thrift_include_options
    "-I;$<JOIN:$<TARGET_PROPERTY:${LIB_NAME}.thrift_includes,INTERFACE_INCLUDE_DIRECTORIES>,;-I;>"
  )

  # Build options string
  if(ARG_OPTIONS)
    string(REPLACE ";" "," GEN_ARG_STR "${ARG_OPTIONS}")
    set(gen_arg "--gen;mstch_python:${GEN_ARG_STR}")
  else()
    set(gen_arg "--gen;mstch_python")
  endif()

  # Emit the rule to run the thrift compiler
  add_custom_command(
    OUTPUT
      ${generated_sources}
    COMMAND_EXPAND_LISTS
    COMMAND
      "${CMAKE_COMMAND}" -E make_directory "${output_dir}"
    COMMAND
      "${THRIFT1}"
      ${gen_arg}
      "${thrift_include_options}"
      -o "${output_dir}"
      "${CMAKE_CURRENT_SOURCE_DIR}/${THRIFT_FILE}"
    WORKING_DIRECTORY
      "${CMAKE_BINARY_DIR}"
    MAIN_DEPENDENCY
      "${THRIFT_FILE}"
    DEPENDS
      "${THRIFT1}"
  )

  # Create Python library target
  # Note: thrift_python runtime is built via setup.py, not add_fb_python_library,
  # so we don't add it as a CMake dependency here. The runtime must be installed
  # separately.
  add_fb_python_library(
    "${LIB_NAME}"
    BASE_DIR "${output_dir}/gen-python"
    NAMESPACE ""
    SOURCES ${generated_sources}
    DEPENDS ${ARG_DEPENDS}
  )
endfunction()
