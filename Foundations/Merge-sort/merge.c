void merge(int arr[], int p, int q, int r) {
    #define INF 2147483647

    int n1 = q - p + 1;  // number of elements of first part
    int n2 = r - q;      // number of elements of second part
    int L[n1+1], R[n2+1];

    // copying elements to new arrays
    for (int i=0; i<n1; i++) {
        L[i] = arr[p+i];
    }
    for (int j=0; j<n2; j++) {
        R[j] = arr[q+j+1];
    }

    // adding sentinel element to the end of each array to mark it
    L[n1] = INF;
    R[n2] = INF;
    // current element of each part
    int i = 0;
    int j = 0;

    // compare current elements of each part
    // add the larger element to arr
    // move the to the next element in the part of chosen element
    for (int k=p; k<=r; k++) {
        arr[k] = (L[i] <= R[j]) ? (L[i++]) : (R[j++]);
    }
}