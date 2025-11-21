#include <stdlib.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

void max_heap_insert(struct heap *A, int key) {
    #define INF 2147483647
    void heap_increase_key(struct heap A, int i, int key);

    int *new_arr = malloc(sizeof(int) * (A->length + 1));  // create new array with one more slot
    // copy elements from old array
    for (int i=0; i<(A->length); i++) {
        new_arr[i] = A->arr[i];
    }

    // point the heap to the new array
    A->arr = new_arr;
    A->length += 1;
    A->heap_size += 1;

    // if length is equal to heap size this line does nothing
    // otherwise it moves the element in the position of the last
    // heap element into a safe slot (last slot in the array)
    // to avoid overwriting
    A->arr[(A->length)-1] = A->arr[(A->heap_size)-1];

    A->arr[(A->heap_size)-1] = -INF;
    heap_increase_key(*A, (A->heap_size)-1, key);
}