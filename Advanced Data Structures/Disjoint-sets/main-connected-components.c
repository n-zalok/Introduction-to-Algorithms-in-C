#include <stdio.h>
#include <time.h>
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


int main() {
    srand(time(NULL));
    void directed_graph(struct graph *G, int n, int m);
    void connected_components(struct graph *G, int n, int m);
    void print_connected_components(struct graph *G, int n);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    do {
        printf("Enter number of edges(0<=m<=n^2): ");
        scanf("%d", &m);
    }
    while (m < 0 || m > (n*n));

    // generate random directed graph
    struct graph G;
    directed_graph(&G, n, m);

    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", G.V[i].key);
    }
    printf("]\n");

    printf("Edges: [");
    for (int i=0; i<m; i++) {
        printf(" (%d, %d) ", G.E[i].from->key, G.E[i].to->key);
    }
    printf("]\n");

    connected_components(&G, n, m);
    print_connected_components(&G, n);

    return 0;
}