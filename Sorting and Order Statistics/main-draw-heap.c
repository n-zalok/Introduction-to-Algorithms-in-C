#include <stdio.h>
#include <math.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    void draw_heap(struct heap A);
    int n;

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

    printf("array: [");
    for (int i=0; i<A.length; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");

    draw_heap(A);

    return 0;
}