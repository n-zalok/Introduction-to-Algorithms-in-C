#include <stdlib.h>

struct current_digit {
    int *arr;
    int *digit;
};

int* digit_counting_sort(struct current_digit A, int n) {
    int k = 9;
    int *B = malloc(sizeof(int) * n);
    int C[k+1];

    for (int i=0; i<=k; i++) {
        C[i] = 0;
    }

    for (int j=0; j<n; j++) {
        C[A.digit[j]] += 1;
    }

    for (int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }

    for (int j=n-1; j>=0; j--) {
        B[C[A.digit[j]]-1] = A.arr[j];
        C[A.digit[j]] -= 1;
    }

    return B;
} 