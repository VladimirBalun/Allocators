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
#include "pool_allocator.h"
#include "details/tools.h"

int allocators_pl_create(pool_allocator_t* p_allocator, size_t sz_memory_size, size_t sz_chunk_size, size_t sz_alignment)
{
    if (!p_allocator)
        return FAIL_RESULT;

    if ((sz_memory_size == 0u) || (!IS_EVEN_UNSIGNED_NUMBER(sz_alignment)) || (sz_memory_size < sz_alignment))
        return FAIL_RESULT;

    return SUCCESSFUL_RESULT;
}

void* allocators_pl_allocate(pool_allocator_t* p_allocator)
{
    if (!p_allocator)
        return NULL;

    return NULL;
}

void allocators_pl_free(pool_allocator_t* p_allocator, void* p_pointer)
{
    if (!p_allocator || !p_pointer)
        return;
}

void allocators_pl_clear(pool_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;
}

void allocators_pl_destroy(pool_allocator_t* p_allocator)
{
    if (!p_allocator)
        return;
}
