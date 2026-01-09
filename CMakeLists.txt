# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

# Package information.
if (NOT DEFINED PACKAGE_VERSION)
  set(PACKAGE_VERSION 1.0.0)
endif ()
project(THRIFT VERSION ${PACKAGE_VERSION} LANGUAGES CXX)

# Enable testing early so tests registered in subdirectories are visible to ctest
enable_testing()

if (NOT DEFINED CPACK_GENERATOR)
  set(CPACK_GENERATOR RPM)
endif ()
set(CPACK_RPM_PACKAGE_PROVIDES thrift)
include(CPack)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BIN_INSTALL_DIR bin CACHE STRING
    "The subdirectory where the compiler binary should be installed")
set(INCLUDE_INSTALL_DIR include CACHE STRING
    "The subdirectory where include files should be installed")
set(LIB_INSTALL_DIR lib CACHE STRING
    "The subdirectory where libraries should be installed")
set(CMAKE_INSTALL_DIR lib/cmake/fbthrift CACHE STRING
    "The subdirectory where CMake package config files should be installed")

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_DIR}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Add root dir so qualified includes work, e.g. #include "thrift/compiler/*.h".
include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Set directory of the Find$x.cmake files to properly include dependencies.
set(CMAKE_STD_MODULE_PATH ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/thrift/cmake
  # For in-fbsource builds:
  ${CMAKE_CURRENT_SOURCE_DIR}/../opensource/fbcode_builder/CMake
  # For shipit-transformed builds:
  ${CMAKE_CURRENT_SOURCE_DIR}/build/fbcode_builder/CMake
  ${CMAKE_MODULE_PATH})

# Find required dependencies.
find_package(Boost REQUIRED filesystem)
find_package(fmt CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  message(STATUS "setting C++ standard to C++${CMAKE_CXX_STANDARD}")
endif()
set(CMAKE_CXX_EXTENSIONS OFF)

# Explicitly enable coroutine support, since GCC does not enable it
# by default when targeting C++17.
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fcoroutines>)
endif()

# Enable modular builds.
option(THRIFT_COMPILER_ONLY "Build the Thrift compiler only" OFF)
option(THRIFT_LIB_ONLY "Build the Thrift libraries only" OFF)
if (THRIFT_COMPILER_ONLY OR THRIFT_LIB_ONLY)
  set(build_all OFF)
else ()
  set(build_all ON)
endif ()

set(
  thriftpy AUTO
  CACHE BOOL
  "Install the thrift/lib/py library as an FB Python archive manifest"
)
set_property(CACHE thriftpy PROPERTY STRINGS ON OFF AUTO)
option(thrift_python
  "Include thrift-python library and extensions in the build, requires Cython"
  OFF
)
option(PYTHON_EXTENSIONS
  "Build Python extensions for thrift-python, requires Cython"
  OFF
)

# thrift_python requires PYTHON_EXTENSIONS
if (thrift_python)
  set(PYTHON_EXTENSIONS ON CACHE BOOL
    "Forced ON because thrift_python requires Python extensions" FORCE)
endif()

# Python extensions require position-independent code
# NOTE: BUILD_SHARED_LIBS is commented out because it exposes a circular dependency
# between thrifttype and thriftanyrep in thrift/lib/cpp2/CMakeLists.txt.
# With static libs, symbols resolve at final link time. With shared libs, each .so
# must be self-contained, exposing the missing link. See CHANGELOG.md 2025-01-09.
# TODO: Fix the circular dependency and re-enable BUILD_SHARED_LIBS.
if (PYTHON_EXTENSIONS)
  # set(BUILD_SHARED_LIBS ON CACHE BOOL
  #   "Forced ON because PYTHON_EXTENSIONS requires shared libraries" FORCE)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL
    "Forced ON because PYTHON_EXTENSIONS requires position-independent code" FORCE)
endif()

find_package(folly CONFIG REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Set FOLLY_INCLUDE_DIR for Cython .pxd file symlinking
# folly CONFIG mode doesn't set this variable, but we need it for thrift/lib/CMakeLists.txt
# Get it from the folly package's install prefix
get_target_property(_folly_location Folly::folly LOCATION)
get_filename_component(_folly_prefix "${_folly_location}" DIRECTORY)
get_filename_component(_folly_prefix "${_folly_prefix}" DIRECTORY)
set(FOLLY_INCLUDE_DIR "${_folly_prefix}/include")
message(STATUS "FOLLY_INCLUDE_DIR set to: ${FOLLY_INCLUDE_DIR}")

# Set FOLLY_LIB_DIR for LD_LIBRARY_PATH in tests
set(FOLLY_LIB_DIR "${_folly_prefix}/lib")
message(STATUS "FOLLY_LIB_DIR set to: ${FOLLY_LIB_DIR}")

# Set FOLLY_PYTHON_SITE_PACKAGES for Cython .pxd files (folly.pxd, iobuf.pxd, etc.)
# These are separate from C++ headers and live in Python site-packages
# Note: pip --prefix on Debian/Ubuntu installs to local/lib/pythonX.Y/dist-packages/
# while setup.py install goes to lib/pythonX.Y/site-packages/
# Check both locations to handle different folly build methods
set(_folly_py_version "python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}")
set(_folly_site_packages "${_folly_prefix}/lib/${_folly_py_version}/site-packages")
set(_folly_dist_packages "${_folly_prefix}/local/lib/${_folly_py_version}/dist-packages")

if(EXISTS "${_folly_site_packages}/folly")
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_site_packages}")
  message(STATUS "FOLLY_PYTHON_SITE_PACKAGES set to: ${FOLLY_PYTHON_SITE_PACKAGES} (site-packages)")
elseif(EXISTS "${_folly_dist_packages}/folly")
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_dist_packages}")
  message(STATUS "FOLLY_PYTHON_SITE_PACKAGES set to: ${FOLLY_PYTHON_SITE_PACKAGES} (dist-packages)")
else()
  # Fallback to site-packages and hope it gets created later
  set(FOLLY_PYTHON_SITE_PACKAGES "${_folly_site_packages}")
  message(WARNING "Neither folly site-packages nor dist-packages found. Using default: ${FOLLY_PYTHON_SITE_PACKAGES}")
endif()

# Create folly/__init__.py if missing (folly build doesn't create it, but Python requires it)
if(EXISTS "${FOLLY_PYTHON_SITE_PACKAGES}/folly" AND NOT EXISTS "${FOLLY_PYTHON_SITE_PACKAGES}/folly/__init__.py")
  message(STATUS "Creating missing ${FOLLY_PYTHON_SITE_PACKAGES}/folly/__init__.py")
  file(WRITE "${FOLLY_PYTHON_SITE_PACKAGES}/folly/__init__.py" "# Auto-generated by fbthrift build\n")
endif()

# Find required dependencies for the Thrift compiler.
if (THRIFT_COMPILER_ONLY OR build_all)
  include_directories(${OPENSSL_INCLUDE_DIR})
  set(THRIFT1 thrift1)
  set(THRIFTCPP2 thriftcpp2)
  include(ThriftLibrary.cmake)
  install(FILES ThriftLibrary.cmake DESTINATION ${INCLUDE_INSTALL_DIR}/thrift)
endif ()

# Find required dependencies for thrift/lib
if (THRIFT_LIB_ONLY OR build_all)
  find_package(Gflags REQUIRED)
  find_package(Glog REQUIRED)
  find_package(fizz CONFIG REQUIRED)
  find_package(wangle CONFIG REQUIRED)
  find_package(ZLIB REQUIRED)
  find_package(Zstd REQUIRED)
  find_package(Xxhash REQUIRED)
  find_package(mvfst CONFIG REQUIRED)
  # https://cmake.org/cmake/help/v3.9/module/FindThreads.html
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads)
  include_directories(
    ${LIBGFLAGS_INCLUDE_DIR}
    ${GLOG_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    ${ZSTD_INCLUDE_DIRS}
    ${Xxhash_INCLUDE_DIR}
  )
  add_definitions("-DTHRIFT_HAVE_LIBSNAPPY=0")
  if (THRIFT_LIB_ONLY)
    find_program(THRIFT1 thrift1)
    include(${THRIFT_COMPILER_INCLUDE}/thrift/ThriftLibrary.cmake)
  endif ()

endif ()

if(thrift_python)
  # Compatibility shims for code expecting old variable names
  set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
  set(PYTHON_LIBRARY ${Python3_LIBRARIES})
  set(PYTHON_LIBRARIES ${Python3_LIBRARIES})
  set(PYTHON_INCLUDE_DIRS ${Python3_INCLUDE_DIRS})
  find_package(Cython 0.28 REQUIRED)

  # ==========================================================================
  # Find all transitive dependencies needed for DEPENDENCY_LIB_PATH
  # ==========================================================================
  # These are transitive deps of folly/fizz/wangle that we need at runtime.
  # We must call find_package() explicitly because folly's CMake config
  # doesn't export these variables.
  #
  # Each find_package(X REQUIRED) will FATAL_ERROR if X is not found,
  # so no conditional checks are needed after - variables are guaranteed set.
  # ==========================================================================

  find_package(LibEvent REQUIRED)
  find_package(Sodium REQUIRED)
  find_package(Glog REQUIRED)
  find_package(LibUnwind REQUIRED)
  find_package(DoubleConversion REQUIRED)
  find_package(Zstd REQUIRED)
  find_package(fizz CONFIG REQUIRED)
  find_package(wangle CONFIG REQUIRED)
  find_package(mvfst CONFIG REQUIRED)

  # ==========================================================================
  # Build DEPENDENCY_LIB_PATH for Python test LD_LIBRARY_PATH
  # ==========================================================================

  set(DEPENDENCY_LIB_DIRS "")

  list(APPEND DEPENDENCY_LIB_DIRS "${FOLLY_LIB_DIR}")

  get_filename_component(_glog_lib_dir "${GLOG_LIBRARY}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_glog_lib_dir}")

  get_filename_component(_gflags_cmake_parent "${gflags_DIR}" DIRECTORY)
  get_filename_component(_gflags_lib_dir "${_gflags_cmake_parent}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_gflags_lib_dir}")

  get_filename_component(_fmt_cmake_parent "${fmt_DIR}" DIRECTORY)
  get_filename_component(_fmt_lib_dir "${_fmt_cmake_parent}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_fmt_lib_dir}")

  get_filename_component(_libevent_lib_dir "${LIBEVENT_LIB}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_libevent_lib_dir}")

  get_filename_component(_libunwind_lib_dir "${LIBUNWIND_LIBRARY}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_libunwind_lib_dir}")

  get_filename_component(_fizz_cmake_parent "${fizz_DIR}" DIRECTORY)
  get_filename_component(_fizz_lib_dir "${_fizz_cmake_parent}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_fizz_lib_dir}")

  get_filename_component(_wangle_cmake_parent "${wangle_DIR}" DIRECTORY)
  get_filename_component(_wangle_lib_dir "${_wangle_cmake_parent}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_wangle_lib_dir}")

  get_filename_component(_mvfst_cmake_parent "${mvfst_DIR}" DIRECTORY)
  get_filename_component(_mvfst_lib_dir "${_mvfst_cmake_parent}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_mvfst_lib_dir}")

  get_filename_component(_dc_lib_dir "${DOUBLE_CONVERSION_LIBRARY}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_dc_lib_dir}")

  list(APPEND DEPENDENCY_LIB_DIRS ${Boost_LIBRARY_DIRS})

  get_filename_component(_sodium_lib_dir "${sodium_LIBRARY_RELEASE}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_sodium_lib_dir}")

  get_filename_component(_zstd_lib_dir "${ZSTD_LIBRARY}" DIRECTORY)
  list(APPEND DEPENDENCY_LIB_DIRS "${_zstd_lib_dir}")

  # TODO: Remove if tests don't need these. If tests fail, add find_package(X REQUIRED).
  # find_package(LZ4 REQUIRED)
  # get_filename_component(_lz4_lib_dir "${LZ4_LIBRARY}" DIRECTORY)
  # list(APPEND DEPENDENCY_LIB_DIRS "${_lz4_lib_dir}")
  #
  # find_package(Snappy REQUIRED)
  # get_filename_component(_snappy_lib_dir "${SNAPPY_LIBRARY}" DIRECTORY)
  # list(APPEND DEPENDENCY_LIB_DIRS "${_snappy_lib_dir}")
  #
  # find_package(LibLZMA REQUIRED)
  # get_filename_component(_lzma_lib_dir "${LIBLZMA_LIBRARY}" DIRECTORY)
  # list(APPEND DEPENDENCY_LIB_DIRS "${_lzma_lib_dir}")

  list(REMOVE_DUPLICATES DEPENDENCY_LIB_DIRS)
  string(REPLACE ";" ":" DEPENDENCY_LIB_PATH "${DEPENDENCY_LIB_DIRS}")
  message(STATUS "DEPENDENCY_LIB_PATH for Python tests: ${DEPENDENCY_LIB_PATH}")
endif()

# Add the test dependencies
# To run tests: `make test`
if(enable_tests)
  find_package(PythonInterp REQUIRED)
  find_package(GTest REQUIRED)
  find_package(GMock REQUIRED)
  include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
  )
endif(enable_tests)

# Create a generalized function for tests
function(thrift_gtest tname srcfile)
  add_executable("${tname}-t" ${srcfile})
  target_link_libraries(
    "${tname}-t"

    ${ARGN}
    ${GTEST_BOTH_LIBRARIES}
    ${GMOCK_BOTH_LIBRARIES}
    pthread
  )
  gtest_add_tests("${tname}-t" "" ${srcfile})
endfunction(thrift_gtest)

add_subdirectory(thrift)
