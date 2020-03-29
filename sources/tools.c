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
#include "details/tools.h"

size_t calculate_padding(const size_t sz_not_aligned_address, const size_t sz_alignment)
{
    if ( (sz_alignment != 0u) && (sz_not_aligned_address % sz_alignment != 0u) )
    {
        const size_t sz_multiplier = (sz_not_aligned_address / sz_alignment) + 1u;
        const size_t sz_aligned_address = sz_multiplier * sz_alignment;
        return sz_aligned_address - sz_not_aligned_address;
    }

    return 0u;
}

