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

int find_set(struct vertex *V, int x) {
    if (V[x].key != V[x].p) {
        V[x].p = find_set(V, V[x].p);
    }

    return V[x].p;
}