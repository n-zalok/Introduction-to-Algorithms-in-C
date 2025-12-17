#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    void draw_heap(struct heap A);
    void build_min_heap(struct heap *A);
    int heap_min(struct heap A);
    int heap_extract_min(struct heap *A);
    void heap_decrease_key(struct heap A, int i, int key);
    void min_heap_insert(struct heap *A, int key);
    int n, min, max;

    // get array size, min and max
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    printf("Enter array min: ");
    scanf("%d", &min);
    printf("Enter array max: ");
    scanf("%d", &max);

    // generate random array
    int arr[n];
    random_array(arr, n, min, max);

    printf("array: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    struct heap A;
    A.arr = arr;
    A.length = n;

    // print min priority queue
    build_min_heap(&A);
    printf("min heap:\n");
    draw_heap(A);

    // heap_min
    printf("heap_min: %d\n", heap_min(A));

    // heap_extract_min and its effect
    printf("heap_extract_min: %d\n", heap_extract_min(&A));

    printf("array after heap_extract_min: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after heap_extract_min:\n");
    draw_heap(A);

    // heap_decrease_key and its effect
    heap_decrease_key(A, A.heap_size-1, A.arr[0]-1);

    printf("array after heap_decrease_key on last element in the heap: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after heap_decrease_key on last element in the heap:\n");
    draw_heap(A);

    // min_heap_insert and its effect
    min_heap_insert(&A, 10);

    printf("array after min_heap_insert of 10: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after min_heap_insert of 10:\n");
    draw_heap(A);

    return 0;
}