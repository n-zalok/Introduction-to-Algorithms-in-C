#include <stdio.h>
#include <time.h>
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

int main() {
    srand(time(NULL));
    void flow_network(struct graph *G, int n, int m);
    int Edmonds_Karp(struct graph *G, int n, int m, int s, int t);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>=2): ");
        scanf("%d", &n);
    }
    while (n < 2);

    int min_edges = n-1;
    int max_edges = ((n*n)-n)/2;
    do {
        printf("Enter number of vertices(%d<=m<=%d): ", min_edges, max_edges);
        scanf("%d", &m);
    }
    while (m < min_edges || m > max_edges);

    #define source 0
    #define sink n-1
    // generate random flow network
    struct graph G;
    flow_network(&G, n, m);

    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        if (i==source) {
            printf(" s ");
        }
        else if (i==sink) {
            printf(" t ");
        }
        else {
            printf(" %d ", G.V[i].key);
        }
    }
    printf("]\n");

    printf("Edges (from, to, capacity): [");
    for (int i=0; i<m; i++) {
        if (G.E[i].from == source && G.E[i].to == sink) {
            printf(" (s, t, %d) ", G.E[i].c);
        }
        else if (G.E[i].from == sink && G.E[i].to == source) {
            printf(" (t, s, %d) ", G.E[i].c);
        }
        else if (G.E[i].from == source) {
            printf(" (s, %d, %d) ", G.E[i].to, G.E[i].c);
        }
        else if (G.E[i].to == source) {
            printf(" (%d, s, %d) ", G.E[i].from, G.E[i].c);
        }
        else if (G.E[i].from == sink) {
            printf(" (t, %d, %d) ", G.E[i].to, G.E[i].c);
        }
        else if (G.E[i].to == sink) {
            printf(" (%d, t, %d) ", G.E[i].from, G.E[i].c);
        }
        else {
            printf(" (%d, %d, %d) ", G.E[i].from, G.E[i].to, G.E[i].c);
        }
    }
    printf("]\n");

    printf("Maximum flow: %d\n", Edmonds_Karp(&G, n, m, source, sink));

    return 0;
}