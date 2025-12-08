struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};

void enqueue(struct queue *Q, int x) {
    Q->arr[Q->tail] = x;
    
    if (Q->tail == (Q->size)-1) {
        Q->tail = 0;  // get back to first cell 
    }
    else {
        Q->tail += 1;
    }
}