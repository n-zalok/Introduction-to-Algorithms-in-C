#include <stdio.h>

int main() {
    void random_array(int arr[], int n, int min, int max);
    int randomized_select(int *A, int p, int r, int i);
    int n, min, max, i;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array min: ");
    scanf("%d", &min);
    printf("Enter array max: ");
    scanf("%d", &max);

    do {
        printf("Enter ith smallest element to find (1<=i<=n): ");
        scanf("%d", &i);
    }
    while (i < 1 || i > n);
    

    int arr[n];
    random_array(arr, n, min, max);

    printf("array: [");
    for (int j=0; j<n; j++) {
        printf(" %d ", arr[j]);
    }
    printf("]\n");


    int ith_smallest = randomized_select(arr, 0, n-1, i);
    printf("%dth smallest element: %d\n", i, ith_smallest);

    return 0;
}