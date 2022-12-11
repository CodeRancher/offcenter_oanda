# set minimum cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(extern LANGUAGES CXX)

# require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
cmake_policy(SET CMP0074 NEW)

#include(FetchContent)
include(ExternalProject)

find_package(Boost
	1.76
	COMPONENTS atomic thread system regex filesystem random chrono serialization 
)
# websocketpp  date-time

#FetchContent_Declare(
#	nlohmann_json
#	GIT_REPOSITORY	https://github.com/nlohmann/json.git
#	GIT_TAG			v3.9.1
#)
find_package(nlohmann_json 3.9.1 REQUIRED)

#FetchContent_Declare(
#	cpprestsdk
#    GIT_REPOSITORY	https://github.com/microsoft/cpprestsdk.git
#    GIT_TAG			v2.10.16
#)
find_package(cpprestsdk REQUIRED)

#set(build_static_lib ON)
#FetchContent_Declare(
#	easyloggingpp
#    GIT_REPOSITORY	https://github.com/amrayn/easyloggingpp.git
#    GIT_TAG			v9.97.0
#)
find_package(EASYLOGGINGPP REQUIRED)

if(ENABLE_UNIT_TESTS)
  # the following code to fetch googletest
  # is inspired by and adapted after:
  #   - https://cmake.org/cmake/help/v3.11/module/FetchContent.html

#	FetchContent_Declare(
#    	googletest
#    	GIT_REPOSITORY https://github.com/google/googletest.git
#    	GIT_TAG        release-1.10.0
#	)
	find_package(GTest REQUIRED)

#	FetchContent_MakeAvailable(
#		googletest
#	)

endif()

set(PYTHON_VERSION 3)

#FetchContent_MakeAvailable(
#	#nlohmann_json
#    cpprestsdk
#    easyloggingpp
#)

##ExternalProject_Add(thorsserializer
##    #DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
##    GIT_REPOSITORY https://github.com/Loki-Astari/ThorsSerializer.git
##    GIT_TAG header-only
##    #GIT_SHALLOW true
##    #UPDATE_COMMAND ""
##    #SOURCE_DIR ${thorsserializer_SOURCE_DIR}
##    #BUILD_IN_SOURCE 1
##    CONFIGURE_COMMAND ""
##    BUILD_COMMAND ""
##    INSTALL_COMMAND ""
##    LOG_DOWNLOAD ON
##    LOG_INSTALL ON
##)

#git clone --single-branch --branch header-only https://github.com/Loki-Astari/ThorsSerializer.git

#PYTHON_VERSION=3 ./configure --disable-vera

#ExternalProject_Get_property(thorsserializer SOURCE_DIR INCLUDE_DIR)
#message("Source dir of myExtProj = ${SOURCE_DIR}")
#message("Source dir of myExtProj = ${INCLUDE_DIR}")

##message(STATUS "NLOHMANN_JSON include dir: ${NLOHMANN_JSON_INCLUDE_DIR}")
##message(STATUS "NLOHMANN_JSON binary dir: ${NLOHMANN_JSON_BINARY_DIR}")

#message(STATUS "nlohmann_json found: ${nlohmann_json_FOUND}")
#message(STATUS "nlohmann_json include dir: ${nlohmann_json_INCLUDE_DIR}")
#message(STATUS "nlohmann_json binary dir: ${nlohmann_json_BINARY_DIR}")

set(CMAKE_VERBOSE_MAKEFILE ON)
