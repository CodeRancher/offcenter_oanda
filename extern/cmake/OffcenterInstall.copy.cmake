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
# @file   OffcenterInstall.cmake
# @author Scott Brauer
# @date   09-25-2022
#

function(offcenter_lib_install LIB_TARGETS LIB_NAMESPACE LIB_CMAKE_DIR LIB_NAME version LIB_TAG)

    install(
        TARGETS ${LIB_NAME}
        EXPORT  ${LIB_TARGETS}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )
    
    install (
        DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
    )
    
    install(
        EXPORT ${LIB_TARGETS}
        FILE ${LIB_TARGETS}.cmake
        NAMESPACE ${LIB_NAMESPACE}::
        DESTINATION lib/cmake/${LIB_CMAKE_DIR}
    )

    include(CMakePackageConfigHelpers)
    set(version 0.0.1)

    set_property(TARGET ${LIB_NAME} PROPERTY VERSION ${version})
    set_property(TARGET ${LIB_NAME} PROPERTY SOVERSION 0)
    set_property(TARGET ${LIB_NAME} PROPERTY INTERFACE_${LIB_TAG}_MAJOR_VERSION 0)
    set_property(TARGET ${LIB_NAME} APPEND PROPERTY COMPATIBLE_INTERFACE_STRING ${LIB_TAG}_MAJOR_VERSION)

    # generate the version file for the config file
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${LIB_TAG}ConfigVersion.cmake"
        VERSION "${version}"
        COMPATIBILITY AnyNewerVersion
    )

    # create config file
    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME}-config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/${LIB_TAG}Config.cmake"
        INSTALL_DESTINATION lib/cmake/${LIB_CMAKE_DIR}
    )

    # install config files
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${LIB_TAG}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${LIB_TAG}ConfigVersion.cmake"
        DESTINATION lib/cmake/${LIB_CMAKE_DIR}
    )

    # generate the export targets for the build tree
    export(EXPORT ${LIB_TARGETS}
        FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${LIB_TARGETS}.cmake"
        NAMESPACE ${LIB_NAMESPACE}::
    )

endfunction(offcenter_lib_install)

# macro(header_interface build_dir install_dir header_file)
#     $<BUILD_INTERFACE:${build_dir}/${header_file}
# 	$<INSTALL_INTERFACE:${install_dir}/${header_file}
# endmacro()

# macro(headers_interface build_dir install_dir)
#     foreach(header_file IN LISTS ARGN)
#         header_interface(${build_dir} ${install_dir} ${header_file})
#     endforeach()
# endmacro()