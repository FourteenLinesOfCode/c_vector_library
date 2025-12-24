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

// Initialization

/* Set up a new vector if auto_decrease is 0 it won't automatically decrease
* if it is 1 it will decrease if v->size is less than v->capacity / 2
*/
void vector_init(Vector *v, int initial_capacity, int auto_decrease);
void vector_clear(Vector *v);  // Clear vector contents (size -> 0) but keep capacity


// Memory Management

void vector_free(Vector *v);  // Free all allocated memory
void vector_decrease_half(Vector *v);  // Shrink capacity to half
void vector_resize(Vector *v, size_t space); // Resize the underlying storage to a specific size
void vector_shrink_to_fit(Vector *v);  // Shrink capacity to match current size

// Element Access

int vector_get(Vector *v, size_t index);  // Get element at index
void vector_set(Vector *v, size_t index, int value);  // Set element at index
int vector_front(Vector *v);  // Get first element
int vector_back(Vector *v);  // Get last element


// Adding / Removing Elements

void vector_push(Vector *v, int value);  // Add element to the end
int vector_pop(Vector *v);  // Remove element from the end
void vector_insert(Vector *v, size_t index, int value);  // Insert element at specific index
void vector_remove(Vector *v, size_t index);  // Remove element at specific index
void vector_swap(Vector *v, size_t index1, size_t index2);  // Swap two elements


// Query Functions

int vector_size(Vector *v);  // Number of elements currently in vector
int vector_capacity(Vector *v);  // Current capacity of the vector
int vector_is_empty(Vector *v);  // Check if vector is empty
int vector_contains(Vector *v, int value);  // Check if vector contains a value
int vector_find(Vector *v, int value);  // Find the index of a value (first occurrence)


// Sorting / Utilities

int cmp_ints(const void *a, const void *b);  // Compare two integers (helper for sorting)
void vector_sort(Vector *v);  // Sort the vector in ascending order
void vector_print(Vector *v);  // Prints the entire vector
void vector_version(); // Prints the version of the vector library


// needs to be implemented
// =====================
// Initialization & Memory Management
// =====================


// =====================
// Element Access
// =====================

// =====================
// Adding / Removing Elements
// =====================
//void vector_push_front(Vector *v, int value);          // Add element to the start
//int vector_pop_front(Vector *v);                       // Remove element from the start
//void vector_remove_all(Vector *v, int value);          // Remove all occurrences of a value

// =====================
// Query Functions
// =====================
//int vector_index_of(Vector *v, int value);             // Index of first occurrence
//int vector_last_index_of(Vector *v, int value);        // Index of last occurrence
//int vector_count(Vector *v, int value);                // Count how many times a value appears
//int vector_all(Vector *v, int (*predicate)(int));      // Check if all elements satisfy a condition
//int vector_any(Vector *v, int (*predicate)(int));      // Check if any element satisfies a condition

// =====================
// Sorting / Utilities
// =====================
//void vector_reverse(Vector *v);                         // Reverse order of elements
//void vector_shuffle(Vector *v);                         // Randomize order of elements
//void vector_unique(Vector *v);                          // Remove duplicate values
//Vector vector_clone(Vector *v);                         // Create a copy of the vector
//void vector_concat(Vector *v1, Vector *v2);            // Append all elements of another vector
//Vector vector_slice(Vector *v, size_t start, size_t end); // Get a subvector

// =====================
// Numeric / Math Operations
// =====================
//int vector_sum(Vector *v);                               // Sum of all elements
//int vector_product(Vector *v);                           // Product of all elements
//double vector_avg(Vector *v);                            // Average of elements
//int vector_min(Vector *v);                               // Smallest element
//int vector_max(Vector *v);                               // Largest element
//void vector_clamp(Vector *v, int min, int max);         // Clamp all elements to [min, max]

// =====================
// Functional / Advanced Operations
// =====================
//void vector_map(Vector *v, int (*func)(int));           // Apply a function to all elements
//Vector vector_filter(Vector *v, int (*predicate)(int)); // Return a new vector with filtered elements
//int vector_reduce(Vector *v, int (*func)(int acc, int elem), int initial); // Reduce vector to single value
