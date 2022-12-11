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
# @date   10-01-2022
#

offcenter_cxx()
offcenter_elpp()

###############################################################################
# eur_usd_to_csv
offcenter_example_constants(eur_usd_to_csv)
add_executable(${EXE_NAME}
	${CMAKE_CURRENT_LIST_DIR}/src/eur_usd_to_csv.cpp
)

target_link_libraries(${EXE_NAME}
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(${EXE_NAME}
	SYSTEM PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)

offcenter_example()

###############################################################################
# list_accounts
offcenter_example_constants(list_accounts)
add_executable(${EXE_NAME}
	${CMAKE_CURRENT_LIST_DIR}/src/list_accounts.cpp
)

target_link_libraries(${EXE_NAME}
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(${EXE_NAME}
	SYSTEM PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)

offcenter_example()

###############################################################################
# list_candles
offcenter_example_constants(list_candles)
add_executable(${EXE_NAME}
	${CMAKE_CURRENT_LIST_DIR}/src/list_candles.cpp
)

target_link_libraries(${EXE_NAME}
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(${EXE_NAME}
	SYSTEM PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)

offcenter_example()