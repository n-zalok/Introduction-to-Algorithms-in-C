#include <stdio.h>

int main() {
    int random_array(int arr[], int n, int min, int max);
    int randomize_in_place(int arr[], int n);
    int* hire_employee(int arr[], int n);
    int n, min, max;

    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter array min: ");
    scanf("%d", &min);
    printf("Enter array max: ");
    scanf("%d", &max);

    int arr[n];
    random_array(arr, n, min, max);
    randomize_in_place(arr, n);

    printf("Candidates: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    // Hiring process
    int* result = hire_employee(arr, n);
    printf("Score of candidate: %d, Index of candidate: %d, Number of hirings: %d\n", result[0], result[1], result[2]);

    return 0;
}