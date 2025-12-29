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

struct vertex* find_set(struct vertex *x) {
    if (x != x->p) {
        x->p = find_set(x->p);
    }

    return x->p;
}