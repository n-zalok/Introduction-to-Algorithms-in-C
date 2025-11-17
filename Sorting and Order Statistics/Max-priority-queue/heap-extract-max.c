#include <stdio.h>
#include <errno.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int heap_extract_max(struct heap *A) {
    void max_heapify(struct heap A, int i);

    if (A->heap_size < 1) {
        perror("ERROR: heap underflow");
    }

    int max = A->arr[0];
    A->arr[0] = A->arr[(A->heap_size)-1];
    A->arr[(A->heap_size)-1] = max;

    A->heap_size -= 1;
    max_heapify(*A, 0);

    return max;
}