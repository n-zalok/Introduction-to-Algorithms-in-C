#include <stdio.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    void draw_heap(struct heap A);
    void max_heapify(struct heap A, int i);
    int n, min, max;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    arr[0] = 0;
    for (int i=n-1; i>0; i--) {
        arr[n-i] = i;
    }

    struct heap A;
    A.arr = arr;
    A.length = n;
    A.heap_size = n;

    printf("heap:\n");
    draw_heap(A);

    max_heapify(A, 0);
    printf("max heap:\n");
    draw_heap(A);

    return 0;
}