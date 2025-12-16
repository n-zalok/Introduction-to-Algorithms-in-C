#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    void random_double_array(double arr[], int n, double min, double max);
    void bucket_sort(double *A, int n);
    int n;

    double min = 0.0;
    double max = 1.0;

    // get array size, min and max
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    // generate random array
    double arr[n];
    random_double_array(arr, n, min, max);

    printf("Unsorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %f ", arr[i]);
    }
    printf("]\n");

    // bucket sort
    bucket_sort(arr, n);
    printf("Sorted array:   [");
    for (int i=0; i<n; i++) {
        printf(" %f ", arr[i]);
    }
    printf("]\n");

    return 0;
}