/* vector.h - A simple vector implementation in C
 * 
 * Copyright (c) 2025 FourteenLinesOfCode
 * 
 * This software is licensed under the MIT License.
 * See the LICENSE file for details.
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int* data;
    int decrease;    // if it gets automatically decreased
    size_t size;     // how much spaced we used
    size_t capacity; // how much capacity we have
}Vector;

void vector_init(Vector *v, int initial_capacity, int auto_decrease);
void vector_push(Vector *v, int value);
int vector_pop(Vector *v);
void vector_free(Vector *v);
void vector_clear(Vector *v);
int vector_get(Vector *v, size_t index);
void vector_decrease_half(Vector *v);
void vector_resize(Vector *v, size_t space);
void vector_set(Vector *v, size_t index, int value);
int vector_find(Vector *v, int value);
int vector_contains(Vector *v, int value);
int vector_size(Vector *v);
int vector_capacity(Vector *v);
int vector_is_empty(Vector *v);
void vector_swap(Vector *v, size_t index1, size_t index2);
//need to be done
void vector_insert(Vector *v, size_t index, int value);
void vector_remove(Vector *v, size_t index);
void vector_sort(Vector *v);
void vector_reverse(Vector *v);
void vector_print(Vector *v);
