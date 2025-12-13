# Auto-generated from Buck TARGETS by buck_to_cmake_generator.py
# This file is designed to be used with add_subdirectory()
# Parent CMakeLists.txt must provide:
#   - Python3 (via find_package)
#   - _cybld variable (build output directory)


# Create package directory structure
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/py3/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/py3/test/auto_migrate)
file(MAKE_DIRECTORY ${_cybld}/thrift/lib/py3/test/interactions)
file(MAKE_DIRECTORY ${_cybld}/thrift/py3)
file(MAKE_DIRECTORY ${_cybld}/thrift/py3/test)
file(MAKE_DIRECTORY ${_cybld}/thrift/py3/test/is_overload)

# Create package directories in source tree for setup.py --inplace
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/py3/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/py3/test/auto_migrate)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/lib/py3/test/interactions)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/py3)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/py3/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/thrift/py3/test/is_overload)

# Create source file directory structure
file(MAKE_DIRECTORY ${_cybld}/test)
file(MAKE_DIRECTORY ${_cybld}/test/auto_migrate)
file(MAKE_DIRECTORY ${_cybld}/test/interactions)
file(MAKE_DIRECTORY ${_cybld}/test/is_overload)

# Symlink .pxd files from external dependencies
# Generated automatically from Buck cpp_deps

# folly
file(MAKE_DIRECTORY "${_cybld}/folly/")
file(GLOB _folly_pxd_files "${FOLLY_INCLUDE_DIR}/folly/*.pxd")
foreach(_pxd ${_folly_pxd_files})
  get_filename_component(_pxd_name "${_pxd}" NAME)
  file(CREATE_LINK "${_pxd}" "${_cybld}/folly/${_pxd_name}" SYMBOLIC)
endforeach()


# Symlink Python library files

add_custom_command(OUTPUT ${_cybld}/thrift/py3/__init__.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/__init__.py
    ${_cybld}/thrift/py3/__init__.py
  COMMENT "Symlinking __init__.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/__init__.pyi
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/__init__.pyi
    ${_cybld}/thrift/py3/__init__.pyi
  COMMENT "Symlinking __init__.pyi"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/testing.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/testing.py
    ${_cybld}/thrift/py3/testing.py
  COMMENT "Symlinking testing.py"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/py3/test/auto_migrate/auto_migrate_util.py
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/auto_migrate/auto_migrate_util.py
    ${_cybld}/thrift/lib/py3/test/auto_migrate/auto_migrate_util.py
  COMMENT "Symlinking auto_migrate_util.py"
)

# Target to create all Python library symlinks
add_custom_target(py3_python_symlinks ALL
  DEPENDS ${_cybld}/thrift/py3/__init__.py ${_cybld}/thrift/py3/__init__.pyi ${_cybld}/thrift/py3/testing.py ${_cybld}/thrift/lib/py3/test/auto_migrate/auto_migrate_util.py
)

# Symlink .pxd and .h files from Cython libraries

add_custom_command(OUTPUT ${_cybld}/exceptions.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.h
    ${_cybld}/exceptions.h
  COMMENT "Symlinking exceptions.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/exceptions.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.pxd
    ${_cybld}/thrift/py3/exceptions.pxd
  COMMENT "Symlinking thrift/py3/exceptions.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/server.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server.pxd
    ${_cybld}/thrift/py3/server.pxd
  COMMENT "Symlinking thrift/py3/server.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client.h
    ${_cybld}/client.h
  COMMENT "Symlinking client.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/client.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client.pxd
    ${_cybld}/thrift/py3/client.pxd
  COMMENT "Symlinking thrift/py3/client.pxd"
)

add_custom_command(OUTPUT ${_cybld}/client_wrapper.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client_wrapper.h
    ${_cybld}/client_wrapper.h
  COMMENT "Symlinking client_wrapper.h"
)

add_custom_command(OUTPUT ${_cybld}/clientcallbacks.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/clientcallbacks.h
    ${_cybld}/clientcallbacks.h
  COMMENT "Symlinking clientcallbacks.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/reflection.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/reflection.pxd
    ${_cybld}/thrift/py3/reflection.pxd
  COMMENT "Symlinking thrift/py3/reflection.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/std_libcpp.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/std_libcpp.pxd
    ${_cybld}/thrift/py3/std_libcpp.pxd
  COMMENT "Symlinking thrift/py3/std_libcpp.pxd"
)

add_custom_command(OUTPUT ${_cybld}/serializer.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/serializer.h
    ${_cybld}/serializer.h
  COMMENT "Symlinking serializer.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/serializer.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/serializer.pxd
    ${_cybld}/thrift/py3/serializer.pxd
  COMMENT "Symlinking thrift/py3/serializer.pxd"
)

add_custom_command(OUTPUT ${_cybld}/types.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/types.h
    ${_cybld}/types.h
  COMMENT "Symlinking types.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/types.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/types.pxd
    ${_cybld}/thrift/py3/types.pxd
  COMMENT "Symlinking thrift/py3/types.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/common.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/common.pxd
    ${_cybld}/thrift/py3/common.pxd
  COMMENT "Symlinking thrift/py3/common.pxd"
)

add_custom_command(OUTPUT ${_cybld}/stream.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/stream.h
    ${_cybld}/stream.h
  COMMENT "Symlinking stream.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/stream.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/stream.pxd
    ${_cybld}/thrift/py3/stream.pxd
  COMMENT "Symlinking thrift/py3/stream.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/builder.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/builder.pxd
    ${_cybld}/thrift/py3/builder.pxd
  COMMENT "Symlinking thrift/py3/builder.pxd"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/converter.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/converter.pxd
    ${_cybld}/thrift/py3/converter.pxd
  COMMENT "Symlinking thrift/py3/converter.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/cpp_handler.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/cpp_handler.h
    ${_cybld}/test/cpp_handler.h
  COMMENT "Symlinking test/cpp_handler.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/test/cpp_handler.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/cpp_handler.pxd
    ${_cybld}/thrift/py3/test/cpp_handler.pxd
  COMMENT "Symlinking thrift/py3/test/cpp_handler.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/interactions/interaction_test.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/interaction_test.h
    ${_cybld}/test/interactions/interaction_test.h
  COMMENT "Symlinking test/interactions/interaction_test.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/lib/py3/test/interactions/run_interaction.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/run_interaction.pxd
    ${_cybld}/thrift/lib/py3/test/interactions/run_interaction.pxd
  COMMENT "Symlinking thrift/lib/py3/test/interactions/run_interaction.pxd"
)

add_custom_command(OUTPUT ${_cybld}/test/is_overload/func.h
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/is_overload/func.h
    ${_cybld}/test/is_overload/func.h
  COMMENT "Symlinking test/is_overload/func.h"
)

add_custom_command(OUTPUT ${_cybld}/thrift/py3/test/is_overload/func.pxd
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/is_overload/func.pxd
    ${_cybld}/thrift/py3/test/is_overload/func.pxd
  COMMENT "Symlinking thrift/py3/test/is_overload/func.pxd"
)

# Target to create all .pxd and .h header symlinks
add_custom_target(py3_pxd_symlinks ALL
  DEPENDS ${_cybld}/thrift/py3/exceptions.pxd ${_cybld}/thrift/py3/server.pxd ${_cybld}/thrift/py3/client.pxd ${_cybld}/thrift/py3/reflection.pxd ${_cybld}/thrift/py3/std_libcpp.pxd ${_cybld}/thrift/py3/serializer.pxd ${_cybld}/thrift/py3/types.pxd ${_cybld}/thrift/py3/common.pxd ${_cybld}/thrift/py3/stream.pxd ${_cybld}/thrift/py3/builder.pxd ${_cybld}/thrift/py3/converter.pxd ${_cybld}/thrift/py3/test/cpp_handler.pxd ${_cybld}/thrift/lib/py3/test/interactions/run_interaction.pxd ${_cybld}/thrift/py3/test/is_overload/func.pxd ${_cybld}/exceptions.h ${_cybld}/client.h ${_cybld}/client_wrapper.h ${_cybld}/clientcallbacks.h ${_cybld}/serializer.h ${_cybld}/types.h ${_cybld}/stream.h ${_cybld}/test/cpp_handler.h ${_cybld}/test/interactions/interaction_test.h ${_cybld}/test/is_overload/func.h
)

# Symlink .pyx and C++ source files for Cython compilation

add_custom_command(OUTPUT ${_cybld}/exceptions.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/exceptions.pyx
    ${_cybld}/exceptions.pyx
  COMMENT "Symlinking exceptions.pyx"
)

add_custom_command(OUTPUT ${_cybld}/server.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/server.pyx
    ${_cybld}/server.pyx
  COMMENT "Symlinking server.pyx"
)

add_custom_command(OUTPUT ${_cybld}/client.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/client.pyx
    ${_cybld}/client.pyx
  COMMENT "Symlinking client.pyx"
)

add_custom_command(OUTPUT ${_cybld}/reflection.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/reflection.pyx
    ${_cybld}/reflection.pyx
  COMMENT "Symlinking reflection.pyx"
)

add_custom_command(OUTPUT ${_cybld}/serializer.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/serializer.pyx
    ${_cybld}/serializer.pyx
  COMMENT "Symlinking serializer.pyx"
)

add_custom_command(OUTPUT ${_cybld}/types.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/types.pyx
    ${_cybld}/types.pyx
  COMMENT "Symlinking types.pyx"
)

add_custom_command(OUTPUT ${_cybld}/stream.cpp
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/stream.cpp
    ${_cybld}/stream.cpp
  COMMENT "Symlinking stream.cpp"
)

add_custom_command(OUTPUT ${_cybld}/stream.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/stream.pyx
    ${_cybld}/stream.pyx
  COMMENT "Symlinking stream.pyx"
)

add_custom_command(OUTPUT ${_cybld}/builder.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/builder.pyx
    ${_cybld}/builder.pyx
  COMMENT "Symlinking builder.pyx"
)

add_custom_command(OUTPUT ${_cybld}/converter.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/converter.pyx
    ${_cybld}/converter.pyx
  COMMENT "Symlinking converter.pyx"
)

add_custom_command(OUTPUT ${_cybld}/metadata.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/metadata.pyx
    ${_cybld}/metadata.pyx
  COMMENT "Symlinking metadata.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/cpp_handler.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/cpp_handler.pyx
    ${_cybld}/test/cpp_handler.pyx
  COMMENT "Symlinking test/cpp_handler.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/exception_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/exception_helper.pyx
    ${_cybld}/test/exception_helper.pyx
  COMMENT "Symlinking test/exception_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/auto_migrate/cpp_converter_helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/auto_migrate/cpp_converter_helper.pyx
    ${_cybld}/test/auto_migrate/cpp_converter_helper.pyx
  COMMENT "Symlinking test/auto_migrate/cpp_converter_helper.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/interactions/run_interaction.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/interactions/run_interaction.pyx
    ${_cybld}/test/interactions/run_interaction.pyx
  COMMENT "Symlinking test/interactions/run_interaction.pyx"
)

add_custom_command(OUTPUT ${_cybld}/test/is_overload/helper.pyx
  COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/test/is_overload/helper.pyx
    ${_cybld}/test/is_overload/helper.pyx
  COMMENT "Symlinking test/is_overload/helper.pyx"
)

# Target to create all Cython source symlinks
add_custom_target(py3_cython_source_symlinks ALL
  DEPENDS ${_cybld}/exceptions.pyx ${_cybld}/server.pyx ${_cybld}/client.pyx ${_cybld}/reflection.pyx ${_cybld}/serializer.pyx ${_cybld}/types.pyx ${_cybld}/stream.cpp ${_cybld}/stream.pyx ${_cybld}/builder.pyx ${_cybld}/converter.pyx ${_cybld}/metadata.pyx ${_cybld}/test/cpp_handler.pyx ${_cybld}/test/exception_helper.pyx ${_cybld}/test/auto_migrate/cpp_converter_helper.pyx ${_cybld}/test/interactions/run_interaction.pyx ${_cybld}/test/is_overload/helper.pyx
)

# Target for Cython API generation (--api-only phase)
add_custom_target(py3_cython_api_generation ALL
  DEPENDS py3_python_symlinks py3_pxd_symlinks py3_cython_source_symlinks
  COMMAND ${CMAKE_COMMAND} -E env
    "CYTHON_INCLUDE_PATH=${_cybld}"
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py --api-only
  WORKING_DIRECTORY ${_cybld}
  COMMENT "Generating Cython API headers"
)

# Target for Cython compilation (build_ext phase)
add_custom_target(py3_cython_build_ext ALL
  COMMAND ${CMAKE_COMMAND} -E env
    "CYTHON_INCLUDE_PATH=${_cybld}"
    ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/setup.py build_ext --inplace
  WORKING_DIRECTORY ${_cybld}
  DEPENDS py3_cython_api_generation
  COMMENT "Building Cython extensions"
)

# Target dependencies
add_dependencies(py3_cython_build_ext py3_cython_build_ext)

# Buck parameters for all targets:

# exceptions:
#   package: thrift.py3
#   cpp_compiler_flags: ['-fno-strict-aliasing']

# server:
#   package: thrift.py3
#   cpp_compiler_flags: ['-fno-strict-aliasing']

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

# exception_helper:
#   package: thrift.lib.py3.test

# cpp_converter_helper:
#   package: thrift.py3.test

# run_interaction:
#   package: thrift.lib.py3.test.interactions

# helper:
#   package: thrift.py3.test.is_overload

# base:
#   package: thrift.py3

# testing:
#   package: thrift.py3

# auto_migrate_util:
#   package: thrift.lib.py3.test.auto_migrate