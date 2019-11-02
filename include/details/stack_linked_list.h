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

#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct node;
typedef struct node node_t;

struct node {
    void*   p_data;
    node_t* p_next;
};

typedef struct stack_linked_list {
    node_t* p_head;
} stack_linked_list_t;

int allocators_details_sll_create(stack_linked_list_t* p_allocator);
int allocators_details_sll_push(stack_linked_list_t* p_allocator, node_t* p_node);
void* allocators_details_sll_pop(stack_linked_list_t* p_allocator);
void allocators_details_sll_destroy(stack_linked_list_t* p_allocator);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // STACK_LINKED_LIST_H