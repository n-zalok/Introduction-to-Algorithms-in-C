#include <stdio.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    void random_array(int arr[], int n, int min, int max);
    void draw_heap(struct heap A);
    int n, min, max;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array min: ");
    scanf("%d", &min);
    printf("Enter array max: ");
    scanf("%d", &max);

    int arr[n];
    random_array(arr, n, min, max);

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