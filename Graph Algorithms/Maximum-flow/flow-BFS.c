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
    int c;   // capacity
    int cf;  // residual capacity
};

struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};

// return 1 if an augmenting path exists 0 otherwise
// constructs the augmenting path from source to sink
// M is adjacency matrix
int flow_BFS(struct graph *G, int n, struct node **M, int s, int t) {
    #define INF 2147483647
    #define NIL -1
    void enqueue(struct queue *Q, int x);
    int dequeue(struct queue *Q);

    // initialize vertices
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

    // initialize queue
    struct queue Q;
    int arr[n];
    Q.arr  = arr;
    Q.size = n;
    Q.head = 0;
    Q.tail = 0;

    // enqueue source
    enqueue(&Q, s);
    while (Q.head != Q.tail) {  // while Q is not empty
        int i = dequeue(&Q);

        // check all vertices relative to i
        struct node *row = M[i];
        for (int j=0; j<n; j++) {
            // if path can accept flow visit it
            if (row[j].cf != 0) {
                if (G->V[j].color == 'w') {
                    G->V[j].color = 'g';
                    G->V[j].p = i;

                    // if sink reached return
                    if (j == t) {
                        return 1;
                    }
                    enqueue(&Q, j);
                }
            }
        }

        // mark i as finished
        G->V[i].color = 'b';
    }

    // no augmenting path found
    return 0;
}