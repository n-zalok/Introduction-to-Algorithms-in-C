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

int same_component(struct vertex *u, struct vertex *v) {
    struct vertex* find_set(struct vertex *x);

    if (find_set(u) == find_set(v)) {
        return 1;
    }
    else {
        return 0;
    }
}