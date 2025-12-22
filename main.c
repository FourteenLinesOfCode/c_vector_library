#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(){
    Vector *test = (Vector *)malloc(sizeof(Vector));
    vector_init(test,10,1);
    vector_push(test,55);
    vector_push(test,7);
    vector_push(test,5);
    vector_push(test,9);
    vector_swap(test,0,2);
    printf("does it work: %d\n",vector_get(test,2));
    printf("does it work: %d\n",vector_get(test,0));
    return 0;
}