#include <stdlib.h>
#include <time.h>

int randomized_partition(int *A, int p, int r) {
    int partition(int *A, int p, int r);

    srand(time(NULL));
    int i = (rand() % (r - p + 1)) + p;

    int temp = A[r];
    A[r] = A[i];
    A[i] = temp;

    return partition(A, p, r);
}