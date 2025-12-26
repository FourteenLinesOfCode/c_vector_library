#include <stdio.h>
#include "vector.h"

int main(){
    Vector *test = (Vector *)malloc(sizeof(Vector));
    vector_init(test,10,0);
    vector_push(test,5);
    vector_push(test,9);
    vector_push(test,7);
    vector_push_front(test, 911);
    printf("test: %d\n", test->data[0]);
    vector_free(test);
    return 0;
}