#
# Copyright 2021 Scott Brauer
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
# @date   10-01-2022
#

offcenter_cxx()
offcenter_elpp()
offcenter_test_constants(oanda_v20)

add_executable(${EXE_NAME}
	${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/account_json_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/GlobalVariables.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/oanda_exception_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/basic_build_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/endpoint_parameters_test.cpp

	${CMAKE_CURRENT_LIST_DIR}/src/OandaEndpointsFixture.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/OandaEndpointParametersFixture.cpp

	${CMAKE_CURRENT_LIST_DIR}/src/utility_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/account_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/instrument_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/order_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/string_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/json_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/pricing_test.cpp
)

target_link_libraries(${EXE_NAME}
	oanda_v20
	GTest::gtest
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	#nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(${EXE_NAME}
	PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
		${CMAKE_CURRENT_LIST_DIR}/include
#
#	SYSTEM
#		${Easyloggingpp_SOURCE_DIR}/src
)

offcenter_test()