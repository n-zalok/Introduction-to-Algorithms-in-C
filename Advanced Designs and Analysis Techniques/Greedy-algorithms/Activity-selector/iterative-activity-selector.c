#include <stdlib.h>

int iterative_activity_selector(int *s, int *f, int n, int *A) {
    A[1] = 1;
    int k = 1;
    int counter = 2;

    for (int m=2; m<=n; m++) {
        if (s[m] >= f[k]) {
            A[counter++] = m;
            k = m;
        }
    }

    return counter;
}