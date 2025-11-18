#include <stdlib.h>

int* counting_sort(int *A, int n, int k) {
    int *B = malloc(sizeof(int) * n);
    int C[k+1];

    for (int i=0; i<=k; i++) {
        C[i] = 0;
    }

    for (int j=0; j<n; j++) {
        C[A[j]] += 1;
    }

    for (int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }

    for (int j=n-1; j>=0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]] -= 1;
    }

    return B;
} 