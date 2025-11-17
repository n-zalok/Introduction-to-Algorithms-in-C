#include <stdio.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    void random_array(int arr[], int n, int min, int max);
    void draw_heap(struct heap A);
    void build_max_heap(struct heap *A);
    int heap_max(struct heap A);
    int heap_extract_max(struct heap *A);
    void heap_increase_key(struct heap A, int i, int key);
    void max_heap_insert(struct heap *A, int key);
    int n, min, max;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array min: ");
    scanf("%d", &min);
    printf("Enter array max: ");
    scanf("%d", &max);

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

    build_max_heap(&A);
    printf("max heap:\n");
    draw_heap(A);


    printf("heap_max: %d\n", heap_max(A));


    printf("heap_extract_max: %d\n", heap_extract_max(&A));

    printf("array after heap_extract_max: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after heap_extract_max:\n");
    draw_heap(A);


    heap_increase_key(A, A.heap_size-1, A.arr[0]+1);

    printf("array after heap_increase_key on last element in the heap: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after heap_increase_key on last element in the heap:\n");
    draw_heap(A);


    max_heap_insert(&A, 10);

    printf("array after max_heap_insert of 10: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    printf("heap after max_heap_insert of 10:\n");
    draw_heap(A);

    return 0;
}