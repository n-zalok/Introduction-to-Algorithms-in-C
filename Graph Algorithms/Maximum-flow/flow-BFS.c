struct vertex {
    int key;
    int p;     // parent
    char color;
};

struct edge {
    int from;
    int to;
    int c;  // capacity
};

struct graph {
    struct vertex *V;
    struct edge *E;
};

struct node {
    int c;  // capacity
    int cf;  // flow
};

struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};


int flow_BFS(struct graph *G, int n, struct node **M, int s, int t) {
    #define INF 2147483647
    #define NIL -1
    void enqueue(struct queue *Q, int x);
    int dequeue(struct queue *Q);

    for (int i=0; i<n; i++) {
        if (i == s) {
            G->V[i].color = 'g';
            G->V[i].p = NIL;
        }
        else {
            G->V[i].color = 'w';
            G->V[i].p = NIL;
        }
    }

    struct queue Q;
    int arr[n];
    Q.arr  = arr;
    Q.size = n;
    Q.head = 0;
    Q.tail = 0;

    enqueue(&Q, s);
    while (Q.head != Q.tail) {
        int i = dequeue(&Q);

        struct node *row = M[i];
        for (int j=0; j<n; j++) {
            if (row[j].cf != 0) {
                if (G->V[j].color == 'w') {
                    G->V[j].color = 'g';
                    G->V[j].p = i;

                    if (j == t) {
                        return 1;
                    }
                    enqueue(&Q, j);
                }
            }
        }

        G->V[i].color = 'b';
    }

    return 0;
}