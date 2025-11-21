#include <stdlib.h>

int* hire_employee(int arr[], int n) {
    int* result = (int*)malloc(3 * sizeof(int));
    result[0] = 0;  // score of candidate
    result[1] = 0;  // index of candidate
    result[2] = 0;  // number of hirings

    for (int i=0; i<n; i++) {
        if (arr[i] > result[0]) {
            result[0] = arr[i];
            result[1] = i;
            result[2] += 1;
        }
    }

    return result;
}