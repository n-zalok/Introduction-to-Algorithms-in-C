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

void relax(struct vertex *V, int u, int v, int w) {
    #define INF 2147483647
    
    if (V[u].d != INF && w != INF && V[v].d > (V[u].d + w)) {
        V[v].d = V[u].d + w;
        V[v].p = u;
    }
}