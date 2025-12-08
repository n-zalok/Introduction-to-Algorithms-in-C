#include <stdio.h>

struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};

int main() {
    void enqueue(struct queue *Q, int x);
    int dequeue(struct queue *Q);
    int n;

    // get array size
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    int arr[n];
    
    // create queue
    struct queue Q;
    Q.arr = arr;
    Q.size = n;
    Q.head = 0;
    Q.tail = 0; 

    // op to hold operation to be performed
    // x to hold element's value
    int op, x;
    while (1) {
        do {
            printf("Choose operation enqueue(1) or dequeue(-1) or print(0): ");
            scanf("%d", &op);
        }
        while (op != 1 && op != -1 && op != 0);

        if (op == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(&Q, x);
        }
        else if (op == -1) {
            x = dequeue(&Q);
            if (x) {
                printf("Value: %d\n", x);
            }
        }
        else {
            printf("Queue:\n");
            if (Q.head < Q.tail) {
                for (int i=Q.head; i<Q.tail; i++) {
                    printf("%d\n", Q.arr[i]);
                }
            }
            else {
                for (int i=Q.head; i<Q.size; i++) {
                    printf("%d\n", Q.arr[i]);
                }
                for (int i=0; i<Q.tail; i++) {
                    printf("%d\n", Q.arr[i]);
                }
            }
        }
    }

    return 0;
}