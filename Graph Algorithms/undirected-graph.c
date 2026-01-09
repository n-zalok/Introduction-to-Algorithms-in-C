#include <stdlib.h>

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

// creates an undirected graph with n vertices and m edges
void undirected_graph(struct graph *G, int n, int m) {
    // initialize vertex set
    struct vertex *V = malloc(sizeof(struct vertex) * n);
    for (int i=0; i<n; i++) {
        V[i].key = i;
    }

    // initialize edge set
    struct edge *E = malloc(sizeof(struct edge) * m);
    for (int i=0; i<m; i++) {
        int forbidden, from, to;
        do {
            forbidden = 0;
            from = (rand() % (n));  // [0, n-1]
            to = (rand() % (n));    // [0, n-1]

            for (int j=0; j<i; j++) {
                // duplicate edges
                if (E[j].from == from && E[j].to == to) {
                    forbidden = 1;
                    break;
                }
                // reverse edges
                else if (E[j].from == to && E[j].to == from) {
                    forbidden = 1;
                    break;
                }
                // self-loops
                else if (from == to) {
                    forbidden = 1;
                    break;
                }
            }
        }
        while (forbidden == 1);
        
        // assign
        E[i].from = from;
        E[i].to = to;
        E[i].w = (rand() % (3*m)) - m;
    }

    G->V = V;
    G->E = E;
}