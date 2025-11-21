int partition(int *A, int p, int r) {
    int x = A[r];  // pivot point
    int i = p - 1;
    int temp;

    for (int j=p; j<r; j++) {
        if (A[j] <= x) {
            i += 1;
            //exchange A[i] with A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // set pivot point in its correct position
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    // return pivot point index 
    return i+1;
}