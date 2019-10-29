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

#include "linear_allocator.h"
#include "tools.h"

#include <stdint.h>
#include <string.h>

int la_create(linear_allocator_t* p_allocator, const size_t sz_memory_size, const size_t sz_alignment)
{
    if (!p_allocator)
        return FAIL_RESULT;

    if ( (sz_memory_size == 0u) || (!IS_EVEN_UNSIGNED_NUMBER(sz_alignment)) || (sz_memory_size < sz_alignment) )
        return FAIL_RESULT;

    p_allocator->p_memory_pointer = malloc(sz_memory_size);
    if (!p_allocator->p_memory_pointer)
        return FAIL_RESULT;

    p_allocator->sz_memory_used_size = 0u;
    p_allocator->sz_alignment = sz_alignment;
    p_allocator->sz_memory_total_size = sz_memory_size;

#ifdef LA_WITH_ZEROING
    memset(p_allocator->p_memory_pointer, 0, p_allocator->sz_memory_total_size);
#endif // WITH_ZEROING

    return SUCCESSFUL_RESULT;
}

void* la_allocate(linear_allocator_t* p_allocator, const size_t sz_allocated_size)
{
    if (!p_allocator)
        return NULL;

    const size_t sz_alignment = p_allocator->sz_alignment;
    const size_t sz_used_size = p_allocator->sz_memory_used_size;
    const size_t sz_total_size = p_allocator->sz_memory_total_size;
    const uint8_t* p_memory_pointer = (const uint8_t*)p_allocator->p_memory_pointer;

    if (sz_total_size - sz_used_size < sz_allocated_size)
        return NULL;

    if (sz_alignment == 0u)
    {
        p_allocator->sz_memory_used_size += sz_allocated_size;
        void* p_allocated_area = (void*)((size_t)p_memory_pointer + sz_used_size);
        return p_allocated_area;
    }
    else
    {
        // TODO: need to implement allocation with alignment
        p_allocator->sz_memory_used_size += sz_allocated_size;
        void* p_allocated_area = (void*)((size_t)p_memory_pointer + sz_used_size);
        return p_allocated_area;
    }
}

void la_clean(linear_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;

    p_allocator->sz_memory_used_size = 0u;

#ifdef LA_WITH_ZEROING
    memset(p_allocator->p_memory_pointer, 0, p_allocator->sz_memory_total_size);
#endif // WITH_ZEROING
}

void la_destroy(linear_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;

    free(p_allocator->p_memory_pointer);
    p_allocator->p_memory_pointer = NULL;
    p_allocator->sz_memory_total_size = 0u;
    p_allocator->sz_memory_used_size = 0u;
    p_allocator->sz_alignment = 0u;
}
