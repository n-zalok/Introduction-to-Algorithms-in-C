struct heap {
    int *arr;
    int length;
    int heap_size;
};

void max_heapify(struct heap A, int i) {
    int left(int i);
    int right(int i);
    int largest;

    int L = left(i);
    int R = right(i);

    // select largest between i, L and R
    largest = (L < A.heap_size && A.arr[L] > A.arr[i]) ? L : i;
    if (R < A.heap_size && A.arr[R] > A.arr[largest]) {
        largest = R;
    }

    if (largest != i) {
        // exchange i with largest
        int temp = A.arr[i];
        A.arr[i] = A.arr[largest];
        A.arr[largest] = temp;

        max_heapify(A, largest);
    }
}