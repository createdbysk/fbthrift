cmake_minimum_required(VERSION 3.16)
project(thrift_python_example LANGUAGES NONE)

# Thrift compiler — set via -DTHRIFT1=/path/to/thrift1
if(NOT DEFINED THRIFT1)
  message(FATAL_ERROR "THRIFT1 must be set to the path of the thrift1 compiler")
endif()

# Include ThriftLibrary.cmake from repo root
include("${CMAKE_CURRENT_SOURCE_DIR}/../../../ThriftLibrary.cmake")

enable_testing()

# Generate thrift-python code from sum.thrift
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

# Find Python
find_package(Python3 REQUIRED COMPONENTS Interpreter)

# Test: run test_sum_service.py via unittest discover
# -t sets top-level directory (added to sys.path) so handler.py is importable
# Generated thrift types must already be in site-packages (via cmake --install)
add_test(
  NAME test_sum_service
  COMMAND Python3::Interpreter -m unittest discover
    -t "${CMAKE_CURRENT_SOURCE_DIR}/server"
    -s "${CMAKE_CURRENT_SOURCE_DIR}/server/tests"
    -p "test_*.py"
)

# Install generated Python code to site-packages
install(
  DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/gen-python/"
  DESTINATION "${Python3_SITELIB}"
)
