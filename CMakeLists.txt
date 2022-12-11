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
# @file   CMakeLists.txt
# @author Scott Brauer
# @date   09-30-2021
#

cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

set(PROJECT_NAME oanda_v20)
project (${PROJECT_NAME} LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/extern/cmake)

include(OffcenterBuild)
offcenter_proj_setup(${PROJECT_NAME} 0 0 1)

###############################################################################
# Unit testing
offcenter_unit_tests(ON)

###############################################################################
# CPPCheck
offcenter_cpp_check(OFF)

###############################################################################
# Logging
offcenter_v20_logging(OFF)

find_package(nlohmann_json 3.9.1 REQUIRED)
find_package(EASYLOGGINGPP REQUIRED)
find_package(cpprestsdk REQUIRED)

offcenter_find_threads()
offcenter_find_openssl()

###############################################################################
# sub projects
add_subdirectory(extern)
offcenter_libs_setup()
add_subdirectory(oanda_v20)
offcenter_libs_install_no_lib_dir()
add_subdirectory(examples)
add_subdirectory(doc)

offcenter_proj_install()
