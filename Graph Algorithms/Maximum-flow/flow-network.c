#include <stdlib.h>

struct vertex {
    int key;
    int p;     // parent
    char color;
};

struct edge {
    int from;
    int to;
    int c;  // capacity
};

struct graph {
    struct vertex *V;
    struct edge *E;
};

// creates a flow network with n vertices and m edges
void flow_network(struct graph *G, int n, int m) {
    #define source 0
    #define sink n-1

    // initialize vertex set
    struct vertex *V = malloc(sizeof(struct vertex) * n);
    for (int i=0; i<n; i++) {
        V[i].key = i;
    }

    // initialize edge set
    struct edge *E = malloc(sizeof(struct edge) * m);

    // make a path source->1->2->...->sink
    // to make sure all vertices lie on some path from source to sink
    // to get a non trivial flow network
    for(int i=0; i<sink; i++) {
        E[i].from = i;
        E[i].to = i+1;
        E[i].c = rand() % (2*m);
    }

    // assign other edges randomly
    for (int i=sink; i<m; i++) {
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
        E[i].c = rand() % (2*m);
    }

    G->V = V;
    G->E = E;
}