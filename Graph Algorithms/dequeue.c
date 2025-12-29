struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};

int dequeue(struct queue *Q) {
    int x = Q->arr[Q->head];
    
    if (Q->head == (Q->size)-1) {
        Q->head = 0;  // get back to first cell
    }
    else {
        Q->head += 1;
    }

    return x;
}