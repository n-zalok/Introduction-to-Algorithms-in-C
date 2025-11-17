void merge(int arr[], int p, int q, int r) {
    #define INF 2147483647

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1];

    for (int i=0; i<n1; i++) {
        L[i] = arr[p+i];
    }
    for (int j=0; j<n2; j++) {
        R[j] = arr[q+j+1];
    }

    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;

    for (int k=p; k<=r; k++) {
        arr[k] = (L[i] <= R[j]) ? (L[i++]) : (R[j++]);
    }
}