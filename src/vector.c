/* vector.c - A simple vector implementation in C
 * 
 * Copyright (c) 2025 FourteenLinesOfCode
 * 
 * This software is licensed under the MIT License.
 * See the LICENSE file for details.
 */

#include "vector.h"

void vector_init(Vector *v, int initial_capacity, int auto_decrease){
    if(initial_capacity <= 0){
        fprintf(stderr,"ERROR:The initial capacity must be greater than zero using vector_init\n");
        exit(2);
    }
    v->decrease = auto_decrease;
    v->size = 0;
    v->capacity = initial_capacity;
    v->data = (int *)malloc(v->capacity * sizeof(int));
    if (v->data == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed in vector_init!\n");
        exit(1);
    }
}


void vector_push(Vector *v, int value){
    if (v->size >= v->capacity)
    {
        v->capacity *= 2;
        int *new_data = (int *)realloc(v->data, v->capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "ERROR: Memory reallocation failed for vector_push!\n");
            exit(1);
        }
        else{
            v->data = new_data;
        }
    }
    v->data[v->size++] = value;
    if (v->decrease == 1){
            vector_decrease_half(v);
    }
}

int vector_pop(Vector *v){
    if(v->size == 0){
        return 0;
    }
    else{
        int look = v->size - 1;
        int value = v->data[look];
        v->size--;

        if (v->decrease == 1){
            vector_decrease_half(v);
        }

        return value;
    }
}

void vector_free(Vector *v){
    free(v->data);
    v->data = NULL;
    free(v);
}

void vector_clear(Vector *v){
    v->size = 0;
}

int vector_get(Vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "ERROR: Index out of bounds: %zu\n", index);
        return -1;
    }
    return v->data[index];
}


void vector_decrease_half(Vector *v){
    if(v->size > v->capacity / 2){
        fprintf(stderr,"ERROR: the vector cannot be halved due that there are more elements than half of the capacity with vector_decrease_half\n");
        return;
    }
    v->capacity /= 2;
    int *new_data = (int *)realloc(v->data, v->capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "ERROR: Memory reallocation failed for vector_decrease_half!\n");
        exit(1);
    }
    v->data = new_data;
}

void vector_resize(Vector *v, size_t space){
        if(v->size > space){
            fprintf(stderr,"ERROR: You trying to resize to a smaller capacity than the current size with vector_resize\n");
            return;
        }
        else {
            int *new_data = (int *)realloc(v->data, space * sizeof(int));
            if (new_data == NULL) {
            fprintf(stderr, "ERROR: Memory reallocation failed for vector_resize!\n");
            exit(1);
            }
            v->data = new_data;
            v->capacity = space;
        }
}

void vector_set(Vector *v, size_t index, int value) {
    if (index >= v->size) {
        fprintf(stderr, "ERROR: Index out of bounds in vector_set: %zu\n", index);
        return;
    }
    v->data[index] = value;
}


int vector_find(Vector *v, int value){
    for(int index = 0;index < v->size; index++){
        if(v->data[index] == value){
            return index;
        }
    }
    return -1;
}

int vector_contains(Vector *v, int value){
    for(int index = 0;index < v->size; index++){
        if(v->data[index] == value){
            return 1;
        }
    }
    return 0;
}

int vector_size(Vector *v){
    return v->size;
}

int vector_capacity(Vector *v){
    return v->capacity;
}

int vector_is_empty(Vector *v) {
    return v->size == 0;
}

void vector_swap(Vector *v, size_t index1, size_t index2){
    int temp = v->data[index1];
    int temp1 = v->data[index2];
    v->data[index1] = temp1;
    v->data[index2] = temp;
}

void vector_insert(Vector *v, size_t index, int value){
    if(index >= v->size){
        fprintf(stderr, "ERROR: Index out of bounds in vector_insert: %zu\n", index);
        return;
    }

    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }

    for(size_t i = v->size; i > index; i--){
        v->data[i] = v->data[i - 1];
    }

    v->data[index] = value;
    v->size++;
}

void vector_remove(Vector *v, size_t index){
    if(index >= v->size){
        fprintf(stderr, "ERROR: Index out of bounds in vector_remove: %zu\n", index);
        return;
    }

    for (size_t i = index; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->size--;

    if(v->size < v->capacity / 2){
        vector_decrease_half(v);
    }
}

int cmp_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

void vector_sort(Vector *v) {
    if (!v || v->size < 2)
        return;

    qsort(v->data, v->size, sizeof(int), cmp_ints);
}