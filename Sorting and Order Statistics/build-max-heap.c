#include <math.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

void build_max_heap(struct heap *A) {
    void max_heapify(struct heap A, int i);

    A->heap_size = A->length;
    for (int i=floor(A->length/2)-1; i>=0; i--) {
        max_heapify(*A, i);
    }
}