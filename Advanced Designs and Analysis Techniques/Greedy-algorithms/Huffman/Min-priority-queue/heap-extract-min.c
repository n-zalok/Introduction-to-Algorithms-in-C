#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

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

struct node* heap_extract_min(struct heap *A) {
    void min_heapify(struct heap A, int i);

    // error if heap is empty
    if (A->heap_size < 1) {
        perror("ERROR: heap underflow");
    }

    struct node *min = malloc(sizeof(struct node));
    // exchange first element with last element
    *min = A->arr[0];                
    A->arr[0] = A->arr[(A->heap_size)-1];
    A->arr[(A->heap_size)-1] = *min;       

    // re-minimize the heap
    A->heap_size -= 1;
    min_heapify(*A, 0);

    return min;
}