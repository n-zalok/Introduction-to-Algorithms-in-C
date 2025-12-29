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

void union_sets(struct vertex *V, int x, int y) {
    void link(struct vertex *x, struct vertex *y);
    int find_set(struct vertex *V, int x);
    
    link(&V[find_set(V, x)], &V[find_set(V, y)]);
}