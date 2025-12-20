#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    int randomized_select(int *A, int p, int r, int i);
    int n, min, max, i;

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

    // get i
    do {
        printf("Enter ith smallest element to find (1<=i<=n): ");
        scanf("%d", &i);
    }
    while (i < 1 || i > n);

    // generate random array
    int arr[n];
    random_array(arr, n, min, max);

    printf("array: [");
    for (int j=0; j<n; j++) {
        printf(" %d ", arr[j]);
    }
    printf("]\n");

    // get ith_smallest element
    int ith_smallest = randomized_select(arr, 0, n-1, i);
    printf("%dth smallest element: %d\n", i, ith_smallest);

    return 0;
}