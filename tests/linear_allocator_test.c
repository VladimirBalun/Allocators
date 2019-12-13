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
    const int result = allocators_la_create(&allocator, KILLOBYTE_SIZE, WITHOUT_ALIGNMENT);
    ASSERT_TRUE(result);
    ASSERT_EQ(allocator.sz_memory_total_size, KILLOBYTE_SIZE);

    allocators_la_clean(&allocator);
    allocators_la_destroy(&allocator);
    ASSERT_TRUE(!allocator.p_memory_pointer);
}

UTEST(initializtion, initializtion_of_the_linear_allocator_with_0_bytes_of_memory)
{
    linear_allocator_t allocator;
    const int result = allocators_la_create(&allocator, 0u, WITHOUT_ALIGNMENT);
    ASSERT_FALSE(result);
}

UTEST(initialization, initializtion_of_the_linear_allocator_with_not_even_alignment)
{
    linear_allocator_t allocator;
    const int result = allocators_la_create(&allocator, BYTES_16_SIZE, 1);
    ASSERT_FALSE(result);
}

UTEST(initialization, initializtion_of_the_linear_allocator_with_aligment_more_than_memory_size)
{
    linear_allocator_t allocator;
    const int result = allocators_la_create(&allocator, BYTES_16_SIZE, KILLOBYTES_16_SIZE);
    ASSERT_FALSE(result);
}

UTEST(using, work_with_invallid_allocator)
{
    linear_allocator_t* p_allocator = NULL;
    const int result = allocators_la_create(p_allocator, BYTES_32_SIZE, WITHOUT_ALIGNMENT);
    ASSERT_FALSE(result);
}

UTEST(allocation, allocation_of_the_5_double_elements_without_alignment)
{
    linear_allocator_t allocator;
    allocators_la_create(&allocator, BYTES_64_SIZE, WITHOUT_ALIGNMENT);

    const size_t sz_double_size = sizeof(double);
    for (size_t i = 1u; i <= 5; ++i)
    {
        void* p_allocated_element = allocators_la_allocate(&allocator, sz_double_size);
        ASSERT_EQ((p_allocated_element != NULL), (allocator.sz_memory_used_size == (sz_double_size * i)));
    }

    allocators_la_clean(&allocator);
    allocators_la_destroy(&allocator);
}

UTEST_MAIN();
