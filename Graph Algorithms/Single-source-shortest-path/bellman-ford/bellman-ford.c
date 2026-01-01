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

int bellman_ford(struct graph *G, int n, int m, int s) {
    #define INF 2147483647
    void initialize_single_source(struct graph *G, int n, int s);
    void relax(struct vertex *V, int u, int v, int w);
    
    initialize_single_source(G, n, s);

    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            int u = G->E[j].from;
            int v = G->E[j].to;
            int w = G->E[j].w;
            relax(G->V, u, v, w);
        }
    }

    for (int j=0; j<m; j++) {
        struct vertex u = G->V[G->E[j].from];
        struct vertex v = G->V[G->E[j].to];
        int w = G->E[j].w;
        if (u.d != INF && w != INF && v.d > (u.d + w)) {
            return 0;
        }
    }

    return 1;
}