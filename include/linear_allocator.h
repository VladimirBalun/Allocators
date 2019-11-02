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

#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*! 
 * \brief Linear allocator implementation.
 * 
 * This is the simplest kind of allocator. The idea is to keep a pointer at the first 
 * memory address of your memory area and move it every time an allocation is done. 
 * In this allocator, the internal fragmentation is kept to a minimum because all elements 
 * are sequentially (spatial locality) inserted and the only fragmentation between them 
 * is the alignment(that can be disabled).
 * 
 * Complexity:
 *  - allocation: O(1)
 *  - free:       absent in this allocator, all memory is freed together.
 *  - clean:      O(1)
 *  
 *  If the 'LA_WITH_ZEROING' was defined, then linear allocator will use 
 *  zeroing of the unused memory(useful for debugging).
 */
typedef struct linear_allocator {
    void*  p_memory_pointer;
    size_t sz_memory_total_size;
    size_t sz_memory_used_size;
    size_t sz_alignment;
} linear_allocator_t;

/*!
 * Function for initialization of the linear allocator.
 * This function is safe for NULL value of the 'p_allocator'.
 * 
 * \param[in] p_allocator Pointer on the linear allocator structure.
 * \param[in] sz_memory_size Total memory size for linear allocator(size is fixed).
 * \param[in] sz_alignment Alignment for each allocation, if 'sz_alignment' is equal 0, then
 * linear works without alignment of the its elements.
 * \return Returns 1, if the linear allocator was initialized successfully, otherwise returns 0(the linear allocator
 * will not be initialize, if 'sz_memory_size' is equal 0 or 'sz_alignment' is not even or
 * 'sz_memory_size' is less than 'sz_alignment' or system was not allocated necessary memory for allocator).
 */
int allocators_la_create(linear_allocator_t* p_allocator, size_t sz_memory_size, size_t sz_alignment);

/*!
 * Function for allocation memory area from the linear allocator.
 * This function is safe for NULL value of the 'p_allocator'.
 *
 * \warning NULL can be returned.
 * \param[in] p_allocator Pointer on the linear allocator structure.
 * \param[in] sz_allocated_size Size of the allocated memory area.
 * \return Returns allocated memory area, if the allocation was successfully, otherwise
 * returns NULL.
 */
void* allocators_la_allocate(linear_allocator_t* p_allocator, size_t sz_allocated_size);

/*!
 * Function for cleaning all the elements of the linear allocator,
 * after cleaning the linear allocator will be valid for using again.
 * This function is safe for NULL value of the 'p_allocator'.
 *
 * \param[in] p_allocator Pointer on the linear allocator structure.
 */
void allocators_la_clean(linear_allocator_t* p_allocator);

/*!
 * Function for destroying of the linear allocator, after
 * destroying the linear allocator will not be valid for using again.
 * This function is safe for NULL value of the 'p_allocator'.
 *
 * \param[in] p_allocator Pointer on the linear allocator structure.
 */
void allocators_la_destroy(linear_allocator_t* p_allocator);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LINEAR_ALLOCATOR_H
