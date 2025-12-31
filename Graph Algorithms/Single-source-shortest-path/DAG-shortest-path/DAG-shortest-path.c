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

void DAG_shortest_path(struct graph *G, int n, int m, struct ll *Adj, int s) {
    #define NULL ((void *)0)
    struct ll* topological_sort(struct graph *G, int n, struct ll *Adj);
    void initialize_single_source(struct graph *G, int n, int s);
    void relax(struct vertex *V, int u, int v, int w);

    struct ll *order = topological_sort(G, n, Adj);
    initialize_single_source(G, n, s);

    struct node_ll *u = order->head;
    while (u != NULL) {
        struct node_ll *v = Adj[u->key].head;
        while (v != NULL) {
            relax(G->V, u->key, v->key, v->w);
            v = v->next;
        }

        u = u->next;
    }
}