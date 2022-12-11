#
# Copyright 2022 Scott Brauer
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an  BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#
#
# @file   OffcenterBuild.cmake
# @author Scott Brauer
# @date   09-25-2022
#

# offcenter_cmake_min
# Basic version of cmake
function(offcenter_cmake_min)
    cmake_minimum_required (VERSION 3.15 FATAL_ERROR)
endfunction()

# offcenter_cxx
# Standard CXX cmake settings across all builds
macro(offcenter_cxx)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endmacro()

# offcenter_gnu_dirs
# Standard GTNU Dirs
macro(offcenter_gnu_dirs)
    include(GNUInstallDirs)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endmacro()

# offcenter_elpp
# Standard Easylogging cmake settings across all builds
macro(offcenter_elpp)
    add_compile_definitions(ELPP_THREAD_SAFE)
    add_compile_definitions(ELPP_FRESH_LOG_FILE)
    add_compile_definitions(ELPP_NO_DEFAULT_LOG_FILE)
endmacro()

# offcenter_cmake_min
# Basic version of cmake
function(offcenter_project name)
    project (name LANGUAGES CXX)

    offcenter_cxx()
    offcenter_gnu_dirs()
endfunction()

# offcenter_lib_constants
# Defines all Offcenter contansts in one macro call
macro(offcenter_lib_constants lib_name lib_tag)
    set(LIB_NAME ${lib_name})
    set(LIB_TAG ${lib_tag})
    set(LIB_TARGETS ${LIB_TAG}Targets)
    set(LIB_NAMESPACE ${LIB_TAG})
    set(LIB_CMAKE_DIR ${LIB_NAME})

    message(STATUS "Library: ${LIB_NAME} tag(${LIB_TAG}) targets(${LIB_TARGETS}) namespace(${LIB_NAMESPACE}) cmake_dir(${LIB_CMAKE_DIR})")
endmacro()

# offcenter_unit_tests
# Basic version of cmake
function(offcenter_unit_tests)
    option(ENABLE_UNIT_TESTS "Build the tests" ON)
    if(ENABLE_UNIT_TESTS)
        enable_testing()
    endif()
    message(STATUS "ENABLE_UNIT_TESTS ${ENABLE_UNIT_TESTS}")
endfunction()

# offcenter_cpp_check
# Basic version of cmake
function(offcenter_cpp_check)
    option(ENABLE_CODE_ANALYSIS "Run code analysis" OFF)
    message(STATUS "ENABLE_CODE_ANALYSIS ${ENABLE_CODE_ANALYSIS}")

    if(ENABLE_CODE_ANALYSIS)
        find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
        message(STATUS "cppcheck                   ${CMAKE_CXX_CPPCHECK}")

    #    set(CPPCHECK_EXCLUDES
    #        ${CMAKE_BINARY_DIR}/_deps
    #        #${CMAKE_BINARY_DIR}/_deps/nlohmann_json-src/single_include/nlohmann
    #        #${CMAKE_BINARY_DIR}/_deps/nlohmann_json-src/test/src
    #        #${CMAKE_BINARY_DIR}/_deps/nlohmann_json-build/test/CMakeFiles/test-unicode.dir/src
    #        ${CMAKE_BINARY_DIR}/extern
    #        ${CMAKE_SOURCE_DIR}/extern
    #        $ENV{HOME}/dev_tools
    #        $ENV{HOME}/dev_libs
    #    )
    #    message(STATUS "CPPCHECK_EXCLUDES                   ${CPPCHECK_EXCLUDES}")

        if(CMAKE_CXX_CPPCHECK)
            # Notes:
            # - unmatchedSuppression needed since not all source files are
            #   analyzed simultaneously
            # - unusedFunction needed since not all source files are
            #   analyzed simultaneously
            # - template needed to force "warning" into output string, and
            #   to make the 'id' available for suppression

            ## set exclude files and folders
    #	    foreach(ex ${CPPCHECK_EXCLUDES})
    #	        list(APPEND _CPPCHECK_EXCLUDES "-i${ex}")
    #	    endforeach(ex)

            list(
                APPEND CMAKE_CXX_CPPCHECK 
                    "--check-config"
                    "--enable=all"
                    "--verbose"
                    "--inconclusive"
                    "--inline-suppr"
                    #"--suppress=missingIncludeSystem"
                    #"--suppress=unmatchedSuppression"
                    #"--suppress=unusedFunction"
                    "--template={file}:{line}:0:warning: {severity}:{id}:{message}"
                )
        endif()
    endif(ENABLE_CODE_ANALYSIS)
                    #"--template='{file}:{line}: warning: {id} ({severity}): {message}'"
                    #"--quiet"
                    #(.*?):(\d+):(\d+:)? [Ee]rror: (conflicting types for .*[`'"](.*)['"].*)
                    #(.*?):(\d+):(\d+:)?\s*(([Ww]arning)|(WARNING)): (.*)


endfunction()

# offcenter_v20_logging
# Basic version of cmake
function(offcenter_v20_logging)
    option(LOG_V20_ACCESS "Log V20 Access" OFF)
    if(LOG_V20_ACCESS)
        message(STATUS "Logging V20 Access")
        add_definitions(-DLOG_V20_ACCESS)
        add_definitions(-DELPP_FRESH_LOG_FILE)
        add_definitions(-DELPP_THREAD_SAFE)
    endif()
endfunction()

# offcenter_version
# Version info
macro(offcenter_version project major minor patch)
    set(${project}_major_version ${major})
    set(${project}_minor_version ${minor})
    set(${project}_patch_version ${patch})
    set(${project}_version ${major}.${minor}.${patch})

    message(STATUS "Project: ${project} version(${project_version})")
endmacro()

# offcenter_example_test_dirs
# Set constants for example and test
macro(offcenter_example_test_dirs)
    set(CMAKE_INSTALL_EXAMPLE_DIR "example")  
    set(EXAMPLE_PREFIX "example")  
    set(CMAKE_INSTALL_TEST_DIR "test")  
    set(TEST_PREFIX "test")  
endmacro()