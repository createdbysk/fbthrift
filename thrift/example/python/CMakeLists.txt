cmake_minimum_required(VERSION 3.16)
project(thrift_python_example LANGUAGES NONE)

if(NOT DEFINED THRIFT1)
  message(FATAL_ERROR "THRIFT1 must be set to the path of the thrift1 compiler")
endif()

include("${CMAKE_CURRENT_SOURCE_DIR}/../../../ThriftLibrary.cmake")

enable_testing()

thrift_library(
  "sum"                           #file_name
  "SumService"                    #services
  "python"                        #language
  ""                              #options
  "${CMAKE_CURRENT_SOURCE_DIR}"   #file_path
  "${CMAKE_CURRENT_BINARY_DIR}"   #output_path
  ""                              #include_prefix
  NAMESPACE "facebook.thrift.example.sum"
)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

# Copy generated types to site-packages during build
add_custom_target(install_sum_python ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_BINARY_DIR}/gen-python"
    "${Python3_SITELIB}"
)
add_dependencies(install_sum_python sum-python)

# Wire test to depend on install via fixtures
add_test(NAME setup_sum_python_fixture COMMAND ${CMAKE_COMMAND} -E true)
set_tests_properties(setup_sum_python_fixture PROPERTIES FIXTURES_SETUP sum_python_installed)

add_test(
  NAME test_sum_service
  COMMAND Python3::Interpreter -m unittest discover
    -t "${CMAKE_CURRENT_SOURCE_DIR}/server"
    -s "${CMAKE_CURRENT_SOURCE_DIR}/server/tests"
    -p "test_*.py"
)
set_tests_properties(test_sum_service PROPERTIES FIXTURES_REQUIRED sum_python_installed)
