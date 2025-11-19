#include <stdio.h>
#include <math.h>

int main() {
    void random_array(int arr[], int n, int min, int max);
    int* radix_sort(int *A, int n, int d);
    int n, min, max;

    printf("Enter array size: ");
    scanf("%d", &n);

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

    int arr[n];
    random_array(arr, n, min, max);

    printf("Unsorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");


    int *sorted_arr = radix_sort(arr, n, ((int)floor(log10(max)))+1);
    printf("Sorted array:   [");
    for (int i=0; i<n; i++) {
        printf(" %d ", sorted_arr[i]);
    }
    printf("]\n");

    return 0;
}