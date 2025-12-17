struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct heap {
    struct node *arr;
    int length;
    int heap_size;
};

void min_heapify(struct heap A, int i) {
    int left(int i);
    int right(int i);
    int smallest;

    int L = left(i);
    int R = right(i);

    // select smallest between i, L and R
    smallest = (L < A.heap_size && A.arr[L].frequency < A.arr[i].frequency) ? L : i;
    if (R < A.heap_size && A.arr[R].frequency < A.arr[smallest].frequency) {
        smallest = R;
    }

    if (smallest != i) {
        // exchange i with smallest
        struct node temp = A.arr[i];
        A.arr[i] = A.arr[smallest];
        A.arr[smallest] = temp;

        min_heapify(A, smallest);
    }
}