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

// return 0 if a negative cycle exists and 1 otherwise
// construct a path from s to each reachable vertex v
// such that v.d is distance from s to v
int bellman_ford(struct graph *G, int n, int m, int s) {
    #define INF 2147483647
    void initialize_single_source(struct graph *G, int n, int s);
    void relax(struct vertex *V, int u, int v, int w);
    
    initialize_single_source(G, n, s);

    // the longest path at maximum consists of
    // n-1 edges so we loop for n-1 times
    for (int i=1; i<n; i++) {
        // consider all edges
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
        // if a further relaxation is possible
        // then a negative cycle exists
        if (u.d != INF && w != INF && v.d > (u.d + w)) {
            return 0;
        }
    }

    return 1;
}