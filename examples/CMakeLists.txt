
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(cpprestsdk REQUIRED)
find_package(EASYLOGGINGPP REQUIRED)
add_compile_definitions(ELPP_THREAD_SAFE)
add_compile_definitions(ELPP_FRESH_LOG_FILE)
add_compile_definitions(ELPP_NO_DEFAULT_LOG_FILE)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

###############################################################################
# eur_usd_to_csv
add_executable(eur_usd_to_csv
	${CMAKE_CURRENT_LIST_DIR}/eur_usd_to_csv.cpp
	${EASYLOGGINGPP_INCLUDE_DIR}/easylogging++.cc
)

target_link_libraries(eur_usd_to_csv
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(eur_usd_to_csv
	PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)

###############################################################################
# list_accounts
add_executable(list_accounts
	${CMAKE_CURRENT_LIST_DIR}/list_accounts.cpp
	${EASYLOGGINGPP_INCLUDE_DIR}/easylogging++.cc
)

target_link_libraries(list_accounts
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(list_accounts
	PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)

###############################################################################
# list_candles
add_executable(list_candles
	${CMAKE_CURRENT_LIST_DIR}/list_candles.cpp
	${EASYLOGGINGPP_INCLUDE_DIR}/easylogging++.cc
)

target_link_libraries(list_candles
	oanda_v20
	cpprestsdk::cpprest
	${EASYLOGGINGPP_LIBRARY}
	nlohmann_json::nlohmann_json
	Threads::Threads
	OpenSSL::Crypto
)

target_include_directories(list_candles
	PUBLIC
		${EASYLOGGINGPP_INCLUDE_DIR}
)
