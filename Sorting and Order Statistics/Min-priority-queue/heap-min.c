struct heap {
    int *arr;
    int length;
    int heap_size;
};

int heap_min(struct heap A) {
    return A.arr[0];
}