#include <math.h>

struct current_digit {
    int *arr;    // array of integers
    int *digit;  // current digit to be sorted of each element
};

int* radix_sort(int *A, int n, int d) {
    int* digit_counting_sort(struct current_digit A, int n);

    struct current_digit B;
    int D[n];
    B.arr = A;
    B.digit = D;

    // sort elements by digit for all digits
    for (int i=0; i<d; i++) {
        for (int j=0; j<n; j++) {
            B.digit[j] = ((int)(B.arr[j]/pow(10, i))) % 10;
        }
        B.arr = digit_counting_sort(B, n);
    }

    return B.arr;
}