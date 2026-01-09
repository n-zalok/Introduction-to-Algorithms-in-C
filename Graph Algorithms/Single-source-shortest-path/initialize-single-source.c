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

// set v.d = infinity and v.p = NIL for all v
// set source.d = 0
void initialize_single_source(struct graph *G, int n, int s) {
    #define NIL -1
    #define INF 2147483647  // to avoid overflow

    for (int i=0; i<n; i++) {
        G->V[i].d = INF;
        G->V[i].p = NIL;
    }

    G->V[s].d = 0;
}