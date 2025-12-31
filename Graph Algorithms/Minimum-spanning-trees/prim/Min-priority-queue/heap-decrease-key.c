#include <stdio.h>
#include <errno.h>

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

void heap_decrease_d(struct heap *A, int i, int d) {
    int parent(int i);

    // error if new d is larger than current d
    if (d > A->arr[i].d) {
        perror("ERROR: new d is larger than current d");
    }

    A->arr[i].d = d;

    // re-minimize the heap
    struct node temp;
    int temp_pos;
    while (i > 0 && A->arr[parent(i)].d > A->arr[i].d) {
        // exchange i with smallest

        //exchange position
        int temp_pos = A->pos[A->arr[i].key];
        A->pos[A->arr[i].key] = A->pos[A->arr[parent(i)].key];
        A->pos[A->arr[parent(i)].key] = temp_pos;

        // exchange node
        struct node temp = A->arr[i];
        A->arr[i] = A->arr[parent(i)];
        A->arr[parent(i)] = temp;

        i = parent(i);
    }
}