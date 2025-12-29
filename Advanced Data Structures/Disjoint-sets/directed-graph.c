#include <stdlib.h>

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

struct edge {
    struct vertex *from;
    struct vertex *to;
    int w;  // weight
};

struct graph {
    struct vertex *V;
    struct edge *E;
};


void directed_graph(struct graph *G, int n, int m) {
    struct vertex *V = malloc(sizeof(struct vertex) * n);
    for (int i=0; i<n; i++) {
        V[i].key = i+1;
    }

    struct edge *E = malloc(sizeof(struct vertex) * m);
    for (int i=0; i<m; i++) {
        int duplicate, from, to;
        do {
            duplicate = 0;
            from = (rand() % (n));
            to = (rand() % (n));

            for (int j=0; j<i; j++) {
                if (E[j].from == &V[from] && E[j].to == &V[to]) {
                    duplicate = 1;
                    break;
                }
            }
        }
        while (duplicate == 1);
        
        E[i].from = &V[from];
        E[i].to = &V[to];
    }

    G->V = V;
    G->E = E;
}