int partition(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    int temp;

    for (int j=p; j<r; j++) {
        if (A[j] <= x) {
            i += 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}