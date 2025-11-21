struct heap {
    int *arr;
    int length;
    int heap_size;
};

void heap_sort(struct heap *A) {
    void build_max_heap(struct heap *A);
    void max_heapify(struct heap A, int i);

    build_max_heap(A);

    int temp;
    for (int i=(A->length)-1; i>=1; i--) {
        // exchange current largest element (arr[0]) with arr[i]
        temp = A->arr[0];
        A->arr[0] = A->arr[i];
        A->arr[i] = temp;

        A->heap_size -= 1;
        max_heapify(*A, 0);
    }
}