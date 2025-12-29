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

void union_sets(struct vertex *x, struct vertex *y) {
    void link(struct vertex *x, struct vertex *y);
    struct vertex* find_set(struct vertex *x);
    
    link(find_set(x), find_set(y));
}