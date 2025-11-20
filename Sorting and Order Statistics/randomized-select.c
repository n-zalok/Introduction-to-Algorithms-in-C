int randomized_select(int *A, int p, int r, int i) {
    int randomized_partition(int *A, int p, int r);

    if (p == r) {
        return A[p];
    }

    int q = randomized_partition(A, p, r);
    int k = q - p + 1;

    if (i == k) {
        return A[q];
    }
    else if (i < k) {
        return randomized_select(A, p, q-1, i);
    }
    else {
        return randomized_select(A, q+1, r, i-k);
    }
}