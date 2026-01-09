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

// make the shallow set a child of the deep set
void link(struct vertex *x, struct vertex *y) {
    if (x->rank > y->rank) {
        y->p = x->key;
    }
    else {
        x->p = y->key;
        if (x->rank == y->rank) {
            y->rank += 1;
        }
    }
}