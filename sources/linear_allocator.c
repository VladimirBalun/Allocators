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

#include "pch.h"
#include "linear_allocator.h"
#include "details/tools.h"

#include <stdint.h>
#include <string.h>

int allocators_la_create(linear_allocator_t* p_allocator, const size_t sz_memory_size)
{
    if ( (!p_allocator) || (sz_memory_size == 0u) )
        return FAIL_RESULT;

    p_allocator->p_memory_pointer = malloc(sz_memory_size);
    if (!p_allocator->p_memory_pointer)
        return FAIL_RESULT;

    p_allocator->sz_memory_used_size = 0u;
    p_allocator->sz_memory_total_size = sz_memory_size;

#ifdef LA_WITH_ZEROING
    memset(p_allocator->p_memory_pointer, 0, p_allocator->sz_memory_total_size);
#endif // WITH_ZEROING

    return SUCCESSFUL_RESULT;
}

void* allocators_la_allocate(linear_allocator_t* p_allocator, const size_t sz_size, size_t sz_alignment)
{
    if (!p_allocator)
        return NULL;

    const size_t sz_free_memory = p_allocator->sz_memory_total_size - p_allocator->sz_memory_used_size;
    const size_t sz_not_aligned_address = (size_t) p_allocator->p_memory_pointer + sz_size;
    const size_t sz_allocation_size = sz_size + calculate_padding(sz_not_aligned_address, sz_alignment);
    if (sz_free_memory < sz_allocation_size)
        return NULL;

    void* p_allocated_area = p_allocator->p_memory_pointer + p_allocator->sz_memory_used_size;
    p_allocator->sz_memory_used_size += sz_allocation_size;
    return p_allocated_area;
}

void allocators_la_clean(linear_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;

    p_allocator->sz_memory_used_size = 0u;

#ifdef LA_WITH_ZEROING
    memset(p_allocator->p_memory_pointer, 0, p_allocator->sz_memory_total_size);
#endif // WITH_ZEROING
}

void allocators_la_destroy(linear_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;

    free(p_allocator->p_memory_pointer);
    p_allocator->p_memory_pointer = NULL;
    p_allocator->sz_memory_total_size = 0u;
    p_allocator->sz_memory_used_size = 0u;
}
