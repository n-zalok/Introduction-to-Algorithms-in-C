void insertion_sort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i];  // saving value of current element
        int j = i - 1;
        // comparing current element to elements before it
        // moving each element to next position if it's larger than current element
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; // setting current element in its right place
    }
}