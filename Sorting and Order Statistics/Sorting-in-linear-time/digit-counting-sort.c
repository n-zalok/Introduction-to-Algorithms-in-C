#include <stdlib.h>

struct current_digit {
    int *arr;    // array of integers
    int *digit;  // current digit to be sorted of each element
};

int* digit_counting_sort(struct current_digit A, int n) {
    int k = 9;                         // max value of a digit for base 10
    int *B = malloc(sizeof(int) * n);  // array to contain sorted elements
    int C[k+1];

    for (int i=0; i<=k; i++) {
        C[i] = 0;
    }

    // make C contain occurances of each value
    for (int j=0; j<n; j++) {
        C[A.digit[j]] += 1;
    }

    // make C contain number of elements before each value
    for (int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }

    // set elements in B in order of increasing
    // number of elements before each one
    for (int j=n-1; j>=0; j--) {
        B[C[A.digit[j]]-1] = A.arr[j];
        C[A.digit[j]] -= 1;
    }

    return B;
} 