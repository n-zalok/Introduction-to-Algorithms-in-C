#include <math.h>

struct node {
    int key;
    int d;  // distance
};

struct heap {
    struct node *arr;
    int *pos;  // pos[i] is the position of ith element
    int length;
    int heap_size;
};

// transform A into min-heap
void build_min_heap(struct heap *A) {
    void min_heapify(struct heap *A, int i);

    A->heap_size = A->length; // include all elements in the heap
    for (int i=floor(A->length/2)-1; i>=0; i--) {
        min_heapify(A, i);
    }
}