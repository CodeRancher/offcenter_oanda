
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include(GoogleTest)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)
find_package(cpprestsdk REQUIRED)

add_compile_definitions(ELPP_THREAD_SAFE)
add_compile_definitions(ELPP_FRESH_LOG_FILE)
add_compile_definitions(ELPP_NO_DEFAULT_LOG_FILE)

add_executable(oanda_v20_tests
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
	
	${EASYLOGGINGPP_INCLUDE_DIR}/easylogging++.cc	
)

target_link_libraries(oanda_v20_tests
	oanda_v20
	GTest::gtest
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	#nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(oanda_v20_tests
	PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
		${CMAKE_CURRENT_LIST_DIR}/include
#
#	SYSTEM
#		${Easyloggingpp_SOURCE_DIR}/src
)

gtest_discover_tests(oanda_v20_tests)

add_test(NAME monolithic COMMAND oanda_v20_tests)
