#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct subarray {
    int low;
    int high;
    int sum;
};

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    struct subarray kadane_max_subarray(int arr[], int n);
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

    printf("array:        [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    // find max subarray
    struct subarray max_subarray = kadane_max_subarray(arr, n);
    printf("Max Subarray: [");
    for (int i=max_subarray.low; i<=max_subarray.high; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");
    printf("Sum: %d\n", max_subarray.sum);

    return 0;
}