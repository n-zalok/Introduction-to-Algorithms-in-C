#include <stdio.h>

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

// print path from s to v
void print_path(struct graph *G, int s, int v) {
    #define NIL -1

    if (v == s) {
        printf("%d ", s);
    }
    else if (G->V[v].p == NIL) {
        printf("no path from %d to %d exists", s, v);
    }
    else {
        print_path(G, s, G->V[v].p);
        printf("%d ", v);
    }
}