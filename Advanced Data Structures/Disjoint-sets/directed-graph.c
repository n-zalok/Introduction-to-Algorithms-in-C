#include <stdlib.h>

struct node {
    int key;
    int rank;
    struct node *p;
};

struct edge {
    struct node *from;
    struct node *to;
};

struct graph {
    struct node *V;
    struct edge *E;
};


void directed_graph(struct graph *G, int n, int m) {
    struct node *V = malloc(sizeof(struct node) * n);
    for (int i=0; i<n; i++) {
        V[i].key = i+1;
    }

    struct edge *E = malloc(sizeof(struct node) * m);
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