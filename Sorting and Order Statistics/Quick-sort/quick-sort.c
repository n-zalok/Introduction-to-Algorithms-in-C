void quick_sort(int *A, int p, int r) {
    int randomized_partition(int *A, int p, int r);

    if (p < r) {
        int q = randomized_partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}