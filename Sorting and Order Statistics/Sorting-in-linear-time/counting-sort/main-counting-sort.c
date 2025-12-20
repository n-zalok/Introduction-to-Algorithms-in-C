#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    int* counting_sort(int *A, int n, int k);
    int n, min, max;

    // get array size, min and max
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    do {
        printf("Enter array min(>=0): ");
        scanf("%d", &min);
    }
    while (min < 0);

    do {
        printf("Enter array max(>=0): ");
        scanf("%d", &max);
    }
    while (max < 0);

    // generate random array
    int arr[n];
    random_array(arr, n, min, max);

    printf("Unsorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");


    // counting sort
    int *sorted_arr = counting_sort(arr, n, max);
    printf("Sorted array:   [");
    for (int i=0; i<n; i++) {
        printf(" %d ", sorted_arr[i]);
    }
    printf("]\n");

    return 0;
}