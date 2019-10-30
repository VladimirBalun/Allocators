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

set (TESTS linear_allocator_test)

foreach (__TEST__ ${TESTS})
    add_executable (${__TEST__} ${ALLOCATORS_TESTS_DIR}/${__TEST__}.c)
    target_include_directories (${__TEST__} PRIVATE ${ALLOCATORS_INCLUDE_DIR})
    target_include_directories (${__TEST__} PRIVATE ${ALLOCATORS_DEPENDENCIES_DIR})
	target_link_libraries (${__TEST__} PRIVATE ${ALLOCATORS_LIBRARIES_DIR}/${PROJECT_NAME}.lib)
    set_target_properties (${__TEST__} PROPERTIES RUNTIME_OUTPUT_DIRECTORY         ${ALLOCATORS_BIN_DIR})
    set_target_properties (${__TEST__} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${ALLOCATORS_BIN_DIR})
    set_target_properties (${__TEST__} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ALLOCATORS_BIN_DIR})
    set_target_properties (${__TEST__} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY    ${ALLOCATORS_BIN_DIR})
    add_test (${__TEST__} ${__TEST__})
endforeach ()