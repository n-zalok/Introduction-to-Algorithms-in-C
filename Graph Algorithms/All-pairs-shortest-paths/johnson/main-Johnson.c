#include <stdio.h>
#include <time.h>
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

int main() {
    #define NULL ((void *)0)
    srand(time(NULL));
    void directed_graph(struct graph *G, int n, int m);
    int** Johnson(struct graph *G, int n, int m);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    int max_edges = n*n;
    do {
        printf("Enter number of edges(0<=m<=%d): ", max_edges);
        scanf("%d", &m);
    }
    while (m < 0 || m > max_edges);
    

    // generate random directed graph
    struct graph G;
    directed_graph(&G, n, m);

    // print vertices and edges
    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", G.V[i].key);
    }
    printf("]\n");

    printf("Edges (from, to, weight): [");
    for (int i=0; i<m; i++) {
        printf(" (%d, %d, %d) ", G.E[i].from, G.E[i].to, G.E[i].w);
    }
    printf("]\n");
    
    // compute shortest paths matrix D
    int **D = Johnson(&G, n, m);
    // print all pairs paths
    if (D != NULL) {
        printf("All pairs paths:\n");
        for (int i=0; i<n; i++) {
            printf("Source: %d\n", i);
            for (int j=0; j<n; j++) {
                printf("To %d (%d)", j, D[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }

    return 0;
}