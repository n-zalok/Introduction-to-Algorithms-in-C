#include <stdio.h>
#include <errno.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int heap_extract_min(struct heap *A) {
    void min_heapify(struct heap A, int i);

    // error if heap is empty
    if (A->heap_size < 1) {
        perror("ERROR: heap underflow");
    }

    // exchange first element with last element
    int min = A->arr[0];                
    A->arr[0] = A->arr[(A->heap_size)-1];
    A->arr[(A->heap_size)-1] = min;       

    // re-minimize the heap
    A->heap_size -= 1;
    min_heapify(*A, 0);

    return min;
}