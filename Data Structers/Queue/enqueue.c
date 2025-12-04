struct queue {
    int* arr;
    int size;
    int head;
    int tail;
};

void enqueue(struct queue *Q, int x) {
    Q->arr[Q->tail] = x;
    
    if (Q->tail == (Q->size)-1) {
        Q->tail = 0;
    }
    else {
        Q->tail += 1;
    }
}