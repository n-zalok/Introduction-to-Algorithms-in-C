// Note not all members of each structure required
// for every application but we just unify the definition
struct vertex {
    int key;
    int rank;  // to use union by rank in sets
    int p;     // parent
    int d;     // distance in BFS and discovery time in DFS
    int f;     // finish time
    char color;
};

struct edge {
    int from;
    int to;
    int w;  // weight
};

struct graph {
    struct vertex *V;
    struct edge *E;
};

struct node_ll {
    int key;
    int w;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

struct queue {
    int* arr;
    int size;
    int head; // element that has been longest in the queue
    int tail; // next location for insertion
};


void BFS(struct graph *G, int n, struct ll *Adj, int s) {
    #define NULL ((void *)0)
    #define INF 2147483647
    #define NIL -1
    void enqueue(struct queue *Q, int x);
    int dequeue(struct queue *Q);

    for (int i=0; i<n; i++) {
        if (i == s) {
            G->V[i].color = 'g';
            G->V[i].d = 0;
            G->V[i].p = NIL;
        }
        else {
            G->V[i].color = 'w';
            G->V[i].d = INF;
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
        int u = dequeue(&Q);

        struct node_ll *v = Adj[u].head;
        while (v != NULL) {
            if (G->V[v->key].color == 'w') {
                G->V[v->key].color = 'g';
                G->V[v->key].d = G->V[u].d + 1;
                G->V[v->key].p = u;

                enqueue(&Q, v->key);
            }

            v = v->next;
        }

        G->V[u].color = 'b';
    }
}