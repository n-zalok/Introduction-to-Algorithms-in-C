struct queue {
    int* arr;
    int size;
    int head;
    int tail;
};

int dequeue(struct queue *Q) {
    int x = Q->arr[Q->head];
    
    if (Q->head == Q->size) {
        Q->head = 0;
    }
    else {
        Q->head += 1;
    }

    return x;
}