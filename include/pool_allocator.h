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

#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "details/stack_linked_list.h"

typedef struct pool_allocator {
    stack_linked_list_t sll;
    void*  p_memory_pointer;
    size_t sz_memory_total_size;
    size_t sz_memory_used_size;
    size_t sz_alignment;
    size_t sz_chunk_size;
} pool_allocator_t;

int allocators_pl_create(pool_allocator_t* p_allocator, size_t sz_memory_size, size_t sz_chunk_size, size_t sz_alignment);
void* allocators_pl_allocate(pool_allocator_t* p_allocator);
void allocators_pl_free(pool_allocator_t* p_allocator, void* p_pointer);
void allocators_pl_clear(pool_allocator_t* p_allocator);
void allocators_pl_destroy(pool_allocator_t* p_allocator);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // POOL_ALLOCATOR_H
