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

// return True if both vertices belong to the same set
int same_component(struct vertex *V, int u, int v) {
    int find_set(struct vertex *V, int x);

    if (find_set(V, u) == find_set(V, v)) {
        return 1;
    }
    else {
        return 0;
    }
}