#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

struct node {
    int key;
    int d;
};

struct heap {
    struct node *arr;
    int *pos;
    int length;
    int heap_size;
};

struct node* heap_extract_min(struct heap *A) {
    #define NIL -1
    void min_heapify(struct heap *A, int i);

    // error if heap is empty
    if (A->heap_size < 1) {
        perror("ERROR: heap underflow");
    }

    struct node *min = malloc(sizeof(struct node));
    // exchange first element with last element

    //exchange position
    A->pos[A->arr[(A->heap_size)-1].key] = 0;
    A->pos[A->arr[0].key] = NIL;

    // exchange node
    *min = A->arr[0];
    A->arr[0] = A->arr[(A->heap_size)-1];
    A->arr[(A->heap_size)-1] = *min;
    
    // re-minimize the heap
    A->heap_size -= 1;
    min_heapify(A, 0);

    return min;
}