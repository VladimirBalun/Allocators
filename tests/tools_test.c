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

UTEST(using, check_padding_for_aligned_address)
{
    const size_t sz_alignment = 2u;
    const size_t sz_aligned_address = 0xffaa02;
    const size_t sz_padding = calculate_padding(sz_aligned_address, sz_alignment);
    const size_t sz_result_address = sz_aligned_address + sz_padding;
    ASSERT_EQ(sz_aligned_address, sz_result_address);
}

UTEST(using, check_padding_for_not_aligned_address)
{
    const size_t sz_alignment = 2u;
    const size_t sz_not_aligned_address = 0xffaa01;
    const size_t sz_padding = calculate_padding(sz_not_aligned_address, sz_alignment);
    const size_t sz_result_address = sz_not_aligned_address + sz_padding;
    ASSERT_EQ(sz_not_aligned_address + 1, sz_result_address);
}

UTEST_MAIN()
