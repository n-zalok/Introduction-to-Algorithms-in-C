#include <stdio.h>
#include <time.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    void heap_sort(struct heap *A);
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

    printf("Unsorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    struct heap A;
    A.arr = arr;
    A.length = n;

    // heap sort
    heap_sort(&A);
    printf("Sorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", A.arr[i]);
    }
    printf("]\n");;

    return 0;
}