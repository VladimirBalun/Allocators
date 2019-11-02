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
#include "details/stack_linked_list.h"
#include "details/tools.h"

int allocators_details_sll_create(stack_linked_list_t* p_allocator)
{
    if (!p_allocator)
        return FAIL_RESULT;

    p_allocator->p_head = NULL;
    return SUCCESSFUL_RESULT;
}

int allocators_details_sll_push(stack_linked_list_t* p_allocator, node_t* p_node)
{
    if (!p_allocator || !p_node)
        return FAIL_RESULT;

    p_node->p_next = p_allocator->p_head;
    p_allocator->p_head = p_node;
    return SUCCESSFUL_RESULT;
}

void* allocators_details_sll_pop(stack_linked_list_t* p_allocator)
{
    if (!p_allocator)
        return NULL;

    if (!p_allocator->p_head)
        return NULL;

    node_t* p_top_node = p_allocator->p_head;
    p_allocator->p_head = p_top_node->p_next;
    return p_top_node;
}

void allocators_details_sll_destroy(stack_linked_list_t* p_allocator)
{
    if (!p_allocator)
        return;

    p_allocator->p_head = NULL;
}
