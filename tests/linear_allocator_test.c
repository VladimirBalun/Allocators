/*
 * Copyright 2019 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <utest.h>

#include "details/tools.h"
#include "linear_allocator.h"

UTEST(initialization, initialization_of_the_linear_allocator_with_1_kb_memory)
{
    linear_allocator_t allocator;
    const int result = allocators_la_create(&allocator, KILLOBYTE_SIZE);
    ASSERT_TRUE(result);
    ASSERT_EQ(allocator.sz_memory_total_size, KILLOBYTE_SIZE);

    allocators_la_clean(&allocator);
    allocators_la_destroy(&allocator);
    ASSERT_TRUE(!allocator.p_memory_pointer);
}

UTEST(initializtion, initializtion_of_the_linear_allocator_with_0_bytes_of_memory)
{
    linear_allocator_t allocator;
    const int result = allocators_la_create(&allocator, 0u);
    ASSERT_FALSE(result);
}

UTEST(using, work_with_invallid_allocator)
{
    linear_allocator_t* p_allocator = NULL;
    const int result = allocators_la_create(p_allocator, BYTES_32_SIZE);
    ASSERT_FALSE(result);
}

UTEST(allocation, allocation_of_the_5_double_elements_without_alignment)
{
    linear_allocator_t allocator;
    allocators_la_create(&allocator, BYTES_64_SIZE);

    const size_t sz_double_size = sizeof(double);
    for (size_t i = 1u; i <= 5; ++i)
    {
        void* p_allocated_element = allocators_la_allocate(&allocator, sz_double_size, WITHOUT_ALIGNMENT);
        ASSERT_EQ((p_allocated_element != NULL), (allocator.sz_memory_used_size == (sz_double_size * i)));
    }

    allocators_la_destroy(&allocator);
}

UTEST(allocation, allocation_of_the_4_memory_blocks_without_alignment)
{
    linear_allocator_t allocator;
    allocators_la_create(&allocator, 14u);

    const size_t sz_alignment = 0u;
    uint32_t* p_memory_block_1 = (uint32_t*) allocators_la_allocate(&allocator, sizeof(uint32_t), sz_alignment);
    uint64_t* p_memory_block_2 = (uint64_t*) allocators_la_allocate(&allocator, sizeof(uint64_t), sz_alignment);
    uint8_t* p_memory_block_3 = (uint8_t*) allocators_la_allocate(&allocator, sizeof(uint8_t), sz_alignment);
    uint8_t* p_memory_block_4 = (uint8_t*) allocators_la_allocate(&allocator, sizeof(uint8_t), sz_alignment);

    ASSERT_TRUE(p_memory_block_1 && p_memory_block_2 && p_memory_block_3 && p_memory_block_4);

    allocators_la_destroy(&allocator);
}

UTEST(allocation, allocation_of_the_4_memory_blocks_with_alignment)
{
    linear_allocator_t allocator;
    allocators_la_create(&allocator, 14u);

    const size_t sz_alignment = 2u;
    uint32_t* p_memory_block_1 = (uint32_t*) allocators_la_allocate(&allocator, sizeof(uint32_t), sz_alignment);
    uint64_t* p_memory_block_2 = (uint64_t*) allocators_la_allocate(&allocator, sizeof(uint64_t), sz_alignment);
    uint8_t* p_memory_block_3 = (uint8_t*) allocators_la_allocate(&allocator, sizeof(uint8_t), sz_alignment);
    uint8_t* p_memory_block_4 = (uint8_t*) allocators_la_allocate(&allocator, sizeof(uint8_t), sz_alignment);

    ASSERT_TRUE(p_memory_block_1 && p_memory_block_2 && p_memory_block_3 && !p_memory_block_4);

    allocators_la_destroy(&allocator);
}

UTEST_MAIN();
