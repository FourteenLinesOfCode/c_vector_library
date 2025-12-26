/* vector.h - A simple vector implementation in C
 * 
 * Copyright (c) 2025 FourteenLinesOfCode
 * 
 * This software is licensed under the MIT License.
 * See the LICENSE file for details.
 */

#include <stdlib.h>
#include <stdio.h>
#include "../src/vector.h"

int main(){

    //this only gives you examples of how to use the vector library
    Vector *test1 = (Vector *)malloc(sizeof(Vector)); // how to create a Vector variable

    vector_init(test1,10,1); // how to initialize a Vector vector_init(Vector *variable,int capacity,int auto_decrease(put 1 if the vector should automatically be halfed if possible))

    vector_push(test1,55); // this is how you add an value to the vector at the end
    vector_push(test1,7);  

    int variable = vector_pop(test1); // this is how you pop you can put it in a variable 

    vector_free(test1); // this is how you delete and free the vector

    Vector *test = (Vector *)malloc(sizeof(Vector));
    vector_init(test,10,1);
    vector_push(test,variable);

    vector_clear(test); // this is how you clear all the data
    vector_push(test,variable);
    vector_push(test,variable);

    int var = vector_get(test,1); // this is how you get the value from a certain index

    vector_decrease_half(test); // this is how you half the space

    vector_resize(test,10); // this is how you resize a vector vector_resize(Vector *vector, size_t space);

    vector_set(test,1,124); // this is how you change the value at an certain index

    int index = vector_find(test,7); // looks for the value in the vector and returns an index

    int does_contain = vector_contains(test,7); // it looks if the vector contains the given value and return 1 if true and 0 if wrong

    int size = vector_size(test); // returns the size(the space used) of the vector

    int capacity = vector_capacity(test); // returns the capacity the vector has

    int is_empty = vector_is_empty(test); // returns if the vector is empty

    vector_swap(test,0,1); // swaps the values of the given indexes

    vector_insert(test,1, 33); // inserts a value at the index given to it   vector_insert(Vector *v,size_t index,int value)

    vector_remove(test,1); // removes a value at the given index   void vector_remove(Vector *v, size_t index);

    vector_sort(test); // sorts the vector from the smallest at index 0 to the biggest at the last index   void vector_sort(Vector *v);

    vector_print(test); // prints the entire vector out

    int value = vector_back(test); // gets the last element of the vector can be stored in and variable

    int value1 = vector_front(test); // gets the first element of the vector can also be stored in a variable

    vector_shrink_to_fit(test); // shrinks the vector to fit perfectly to the size meaning if the capacity is 10 and you use 5 of that that after that the capacity is 5

    vector_free(test); // don't forget to free

    return 0;
}