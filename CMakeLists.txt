#
# Copyright 2019 Vladimir Balun
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
#

cmake_minimum_required (VERSION 3.10)

project (Allocators)

set (ALLOCATORS_ROOT_DIR         ${CMAKE_CURRENT_SOURCE_DIR})
set (ALLOCATORS_BUILD_DIR        ${ALLOCATORS_ROOT_DIR}/build)
set (ALLOCATORS_BIN_DIR          ${ALLOCATORS_ROOT_DIR}/bin)
set (ALLOCATORS_DEPENDENCIES_DIR ${ALLOCATORS_ROOT_DIR}/dependencies)
set (ALLOCATORS_LIBRARIES_DIR    ${ALLOCATORS_ROOT_DIR}/libraries)
set (ALLOCATORS_INCLUDE_DIR      ${ALLOCATORS_ROOT_DIR}/include)
set (ALLOCATORS_SOURCES_DIR      ${ALLOCATORS_ROOT_DIR}/sources)
set (ALLOCATORS_TESTS_DIR        ${ALLOCATORS_ROOT_DIR}/tests)

file (GLOB_RECURSE HEADERS ${ALLOCATORS_INCLUDE_DIR}/*.h)
file (GLOB_RECURSE SOURCES ${ALLOCATORS_SOURCES_DIR}/*.c)

add_library (${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE ${ALLOCATORS_INCLUDE_DIR})

if (MSVC)
	set_target_properties (${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY         ${ALLOCATORS_LIBRARIES_DIR})
	set_target_properties (${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${ALLOCATORS_LIBRARIES_DIR})
	set_target_properties (${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ALLOCATORS_LIBRARIES_DIR})
	set_target_properties (${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY         ${ALLOCATORS_LIBRARIES_DIR})
	set_target_properties (${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${ALLOCATORS_LIBRARIES_DIR})
	set_target_properties (${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${ALLOCATORS_LIBRARIES_DIR})
elseif ()	
	set_target_properties (${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${ALLOCATORS_LIBRARIES_DIR})
    set_target_properties (${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${ALLOCATORS_LIBRARIES_DIR}) 
endif ()

option (ENABLE_TESTS "Enable tests for project" ON)
if (ENABLE_TESTS)
	add_subdirectory (tests)
endif ()