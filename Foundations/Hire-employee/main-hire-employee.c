#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    void randomize_in_place(int arr[], int n);
    int* hire_employee(int arr[], int n);
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

    printf("Candidates: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    // hiring process
    randomize_in_place(arr, n);
    int* result = hire_employee(arr, n);
    printf("Score of candidate: %d, Index of candidate: %d, Number of hirings: %d\n", result[0], result[1], result[2]);

    return 0;
}