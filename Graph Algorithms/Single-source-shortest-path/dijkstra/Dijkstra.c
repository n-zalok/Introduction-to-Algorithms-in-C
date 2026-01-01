#include <stdlib.h>

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

struct node {
    int key;
    int d;
};

struct heap {
    struct node *arr;
    int *pos;
    int length;
    int heap_size;
};

void Dijkstra(struct graph *G, int n, struct ll *Adj, int s) {
    #define NULL ((void *)0)
    #define INF 2147483647
    void build_min_heap(struct heap *A);
    struct node* heap_extract_min(struct heap *A);
    void heap_decrease_d(struct heap *A, int i, int d);
    void initialize_single_source(struct graph *G, int n, int s);
    void relax(struct vertex *V, int u, int v, int w);

    initialize_single_source(G, n, s);

    struct node *arr = malloc(sizeof(struct node) * n);
    int *pos = malloc(sizeof(int) * n);
    for (int i=0; i<n; i++) {
        arr[i].key = i;
        arr[i].d = INF;
        pos[i] = i;
    }
    arr[s].d = 0;

    struct heap Q;
    Q.arr = arr;
    Q.pos = pos;
    Q.length = n;

    build_min_heap(&Q);

    while (Q.heap_size != 0) {
        struct node *u = heap_extract_min(&Q);

        struct node_ll *v = Adj[u->key].head;
        while (v != NULL) {
            if (G->V[u->key].d != INF && v->w != INF && G->V[v->key].d > (G->V[u->key].d + v->w)) {
                relax(G->V, u->key, v->key, v->w);
                heap_decrease_d(&Q, Q.pos[v->key], (G->V[u->key].d + v->w));
            }

            v = v->next;
        }
    }
}