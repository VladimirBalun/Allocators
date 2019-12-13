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

#include "details/stack_linked_list.h"

UTEST(using, work_with_invallid_stack_linked_list)
{
    node_t tmp_node;
    stack_linked_list_t* p_sll = NULL;

    const int n_result_creation = allocators_details_sll_create(p_sll);
    ASSERT_FALSE(n_result_creation);

    const int n_result_push = allocators_details_sll_push(p_sll, &tmp_node);
    ASSERT_FALSE(n_result_push);

    void* p_top_node = allocators_details_sll_pop(p_sll);
    allocators_details_sll_destroy(p_sll);
    ASSERT_FALSE(p_top_node);
}

UTEST(using, work_with_invallid_node)
{
    node_t* p_node = NULL;
    stack_linked_list_t sll;
    allocators_details_sll_create(&sll);
    const int n_result = allocators_details_sll_push(&sll, p_node);
    ASSERT_FALSE(n_result);
}

UTEST(using, checking_valid_linking)
{
    node_t first_node;
    node_t second_node;
    stack_linked_list_t sll;
    allocators_details_sll_create(&sll);
    allocators_details_sll_push(&sll, &first_node);
    allocators_details_sll_push(&sll, &second_node);
    void* p_top_node = allocators_details_sll_pop(&sll);
    ASSERT_TRUE(&second_node == p_top_node);
}

UTEST_MAIN()
