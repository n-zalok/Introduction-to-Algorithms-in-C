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

void min_heap_insert(struct heap *A, struct node *z) {
    #define INF 2147483647
    void heap_decrease_key(struct heap A, int i, int key);

    struct node *new_arr = malloc(sizeof(struct node) * (A->length + 1));  // create new array with one more slot
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

    A->arr[(A->heap_size)-1] = *z;
    A->arr[(A->heap_size)-1].frequency = INF;
    heap_decrease_key(*A, (A->heap_size)-1, z->frequency);
}