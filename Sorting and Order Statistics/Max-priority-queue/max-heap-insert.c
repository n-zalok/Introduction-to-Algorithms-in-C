#include <stdlib.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

void max_heap_insert(struct heap *A, int key) {
    #define INF 2147483647
    void heap_increase_key(struct heap A, int i, int key);

    int *new_arr = malloc(sizeof(int) * (A->length + 1));
    for (int i=0; i<(A->length); i++) {
        new_arr[i] = A->arr[i];
    }

    A->arr = new_arr;
    A->length += 1;
    A->heap_size += 1;

    A->arr[(A->length)-1] = A->arr[(A->heap_size)-1];
    A->arr[(A->heap_size)-1] = -INF;
    heap_increase_key(*A, (A->heap_size)-1, key);
}