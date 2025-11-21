#include <stdio.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    void draw_heap(struct heap A);
    void max_heapify(struct heap A, int i);
    int n;

    // get array size
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    // generate an ordered array except the first element
    int arr[n];
    arr[0] = 0;
    for (int i=n-1; i>0; i--) {
        arr[n-i] = i;
    }

    struct heap A;
    A.arr = arr;
    A.length = n;
    A.heap_size = n;

    // print heap
    printf("heap:\n");
    draw_heap(A);

    // print max heap
    max_heapify(A, 0);
    printf("max heap:\n");
    draw_heap(A);

    return 0;
}