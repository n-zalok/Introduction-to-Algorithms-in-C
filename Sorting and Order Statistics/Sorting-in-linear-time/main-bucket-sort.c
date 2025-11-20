#include <stdio.h>

int main() {
    void random_double_array(double arr[], int n, double min, double max);
    void bucket_sort(double *A, int n);
    int n;

    double min = 0.0;
    double max = 1.0;

    printf("Enter array size: ");
    scanf("%d", &n);


    double arr[n];
    random_double_array(arr, n, min, max);

    printf("Unsorted array: [");
    for (int i=0; i<n; i++) {
        printf(" %f ", arr[i]);
    }
    printf("]\n");


    bucket_sort(arr, n);
    printf("Sorted array:   [");
    for (int i=0; i<n; i++) {
        printf(" %f ", arr[i]);
    }
    printf("]\n");

    return 0;
}