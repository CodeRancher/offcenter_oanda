cmake_minimum_required (VERSION 3.15 FATAL_ERROR)

project (oanda LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
  
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

###############################################################################
# Unit testing
option(ENABLE_UNIT_TESTS "Build the tests" ON)
if(ENABLE_UNIT_TESTS)
    enable_testing()
endif()
message(STATUS "ENABLE_UNIT_TESTS ${ENABLE_UNIT_TESTS}")

###############################################################################
# CPPCheck
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


###############################################################################
# Logging
option(LOG_V20_ACCESS "Log V20 Access" OFF)
if(LOG_V20_ACCESS)
	message(STATUS "Logging V20 Access")
    add_definitions(-DLOG_V20_ACCESS)
    add_definitions(-DELPP_FRESH_LOG_FILE)
    add_definitions(-DELPP_THREAD_SAFE)
endif()

###############################################################################
# sub projects
add_subdirectory(extern)
add_subdirectory(oanda_v20)
add_subdirectory(examples)
add_subdirectory(doc)

        