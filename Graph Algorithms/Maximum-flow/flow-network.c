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


void flow_network(struct graph *G, int n, int m) {
    #define source 0
    #define sink n-1
    struct vertex *V = malloc(sizeof(struct vertex) * n);
    for (int i=0; i<n; i++) {
        V[i].key = i;
    }

    struct edge *E = malloc(sizeof(struct edge) * m);
    for(int i=0; i<sink; i++) {
        E[i].from = i;
        E[i].to = i+1;
        E[i].c = rand() % (2*m);
    }

    for (int i=sink; i<m; i++) {
        int forbidden, from, to;
        do {
            forbidden = 0;
            from = (rand() % (n));
            to = (rand() % (n));

            for (int j=0; j<i; j++) {
                if (E[j].from == from && E[j].to == to) {
                    forbidden = 1;
                    break;
                }
                else if (E[j].from == to && E[j].to == from) {
                    forbidden = 1;
                    break;
                }
                else if (from == to) {
                    forbidden = 1;
                    break;
                }
            }
        }
        while (forbidden == 1);
        
        E[i].from = from;
        E[i].to = to;
        E[i].c = rand() % (2*m);
    }

    G->V = V;
    G->E = E;
}