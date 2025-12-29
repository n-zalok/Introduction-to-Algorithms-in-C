// Note not all members of each structure required
// for every application but we just unify the definition
struct vertex {
    int key;
    int rank;          // to use union by rank in sets
    struct vertex *p;  // parent
    int d;             // distance in BFS and discovery time in DFS
    int f;             // finish time
    char color;
};

struct edge {
    struct vertex *from;
    struct vertex *to;
    int w;  // weight
};

struct graph {
    struct vertex *V;
    struct edge *E;
};


void connected_components(struct graph *G, int n, int m) {
    void make_set(struct vertex *x);
    struct vertex* find_set(struct vertex *x);
    void union_sets(struct vertex *x, struct vertex *y);

    for (int i=0; i<n; i++) {
        make_set(&(G->V[i]));
    }

    for (int i=0; i<m; i++) {
        struct vertex *u = G->E[i].from;
        struct vertex *v = G->E[i].to;

        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
        }
    }
}
