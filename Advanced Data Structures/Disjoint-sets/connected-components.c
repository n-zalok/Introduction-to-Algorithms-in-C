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

// make vertices of each connected component belong to the same set
void connected_components(struct graph *G, int n, int m) {
    void make_set(struct vertex *x);
    int find_set(struct vertex *V, int x);
    void union_sets(struct vertex *V, int x, int y);

    for (int i=0; i<n; i++) {
        make_set(&(G->V[i]));
    }

    for (int i=0; i<m; i++) {
        int u = G->E[i].from;
        int v = G->E[i].to;

        if (find_set(G->V, u) != find_set(G->V, v)) {
            union_sets(G->V, u, v);
        }
    }
}
