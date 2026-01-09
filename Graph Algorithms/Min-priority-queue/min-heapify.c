#include <stdio.h>

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

// min-heapify heap starting at element i
void min_heapify(struct heap *A, int i) {
    int left(int i);
    int right(int i);
    int smallest;

    int L = left(i);
    int R = right(i);

    // select smallest between i, L and R
    smallest = (L < A->heap_size && A->arr[L].d < A->arr[i].d) ? L : i;
    if (R < A->heap_size && A->arr[R].d < A->arr[smallest].d) {
        smallest = R;
    }

    if (smallest != i) {
        // exchange i with smallest

        //exchange position
        int temp_pos = A->pos[A->arr[i].key];
        A->pos[A->arr[i].key] = A->pos[A->arr[smallest].key];
        A->pos[A->arr[smallest].key] = temp_pos;

        // exchange node
        struct node temp = A->arr[i];
        A->arr[i] = A->arr[smallest];
        A->arr[smallest] = temp;
        
        min_heapify(A, smallest);
    }
}