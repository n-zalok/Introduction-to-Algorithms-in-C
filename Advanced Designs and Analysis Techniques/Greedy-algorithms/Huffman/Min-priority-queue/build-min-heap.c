#include <math.h>

struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct heap {
    struct node *arr;
    int length;
    int heap_size;
};

void build_min_heap(struct heap *A) {
    void min_heapify(struct heap A, int i);

    A->heap_size = A->length; // include all elements in the heap
    for (int i=floor(A->length/2)-1; i>=0; i--) {
        min_heapify(*A, i);
    }
}