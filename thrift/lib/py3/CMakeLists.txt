# Auto-generated from Buck TARGETS by buck_to_cmake_generator.py
# This file is designed to be used with add_subdirectory()
# Parent CMakeLists.txt must provide:
#   - Python3 (via find_package)
#   - _cybld variable (build output directory)


# Create package directory structure
file(MAKE_DIRECTORY ${_cybld}/thrift/py3)
file(MAKE_DIRECTORY ${_cybld}/thrift/py3/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/py3/test/is_overload)

# Target for Cython API generation (--api-only phase)
add_custom_target(py3_cython_api_generation ALL
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py --api-only
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "Generating Cython API headers"
)

# Target for Cython compilation (build_ext phase)
add_custom_target(py3_cython_build_ext ALL
  COMMAND ${CMAKE_COMMAND} -E env
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py build_ext --inplace
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS py3_cython_api_generation
  COMMENT "Building Cython extensions"
)

# Buck parameters for all targets:

# exceptions:
#   package: thrift.py3
#   cpp_compiler_flags: ['-fno-strict-aliasing']

# server:
#   package: thrift.py3
#   cpp_compiler_flags: ['-fno-strict-aliasing', '']

# client:
#   package: thrift.py3

# reflection:
#   package: thrift.py3

# std_libcpp:
#   package: thrift.py3

# types:
#   package: thrift.py3

# common:
#   package: thrift.py3

# stream:
#   package: thrift.py3
#   api: ['stream']

# builder:
#   package: thrift.py3

# converter:
#   package: thrift.py3

# metadata:
#   package: thrift.py3

# cpp_handler:
#   package: thrift.py3.test

# cpp_converter_helper:
#   package: thrift.py3.test

# helper:
#   package: thrift.py3.test.is_overload