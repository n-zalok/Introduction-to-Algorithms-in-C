#include <stdlib.h>

int* counting_sort(int *A, int n, int k) {
    int *B = malloc(sizeof(int) * n);  // array to contain sorted elements
    int C[k+1];                        

    for (int i=0; i<=k; i++) {
        C[i] = 0;
    }

    // make C contain occurances of each value
    for (int j=0; j<n; j++) {
        C[A[j]] += 1;
    }

    // make C contain number of elements before each value
    for (int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }

    // set elements in B in order of increasing
    // number of elements before each one
    for (int j=n-1; j>=0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]] -= 1;
    }

    return B;
} 