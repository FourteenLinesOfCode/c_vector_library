#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(){
    Vector *test = (Vector *)malloc(sizeof(Vector)); // how to create a Vector variable

    vector_init(test,10,1); // how to initialize a Vector vector_init(Vector *variable,int capacity,int auto_decrease(put 1 if the vector should automatically be halfed))

    vector_push(test,55); // this is how you add an value to the vactor
    vector_push(test,7);  

    int variable = vector_pop(test); // this is how you pop the you can put it in a variable

    vector_free(test); // this is how you delete and free the vector

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

    vector_swap(test,0,1); //swaps the values of the given indexes

    return 0;
}