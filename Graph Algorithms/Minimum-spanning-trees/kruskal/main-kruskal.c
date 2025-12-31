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
    srand(time(NULL));
    void directed_graph(struct graph *G, int n, int m);
    int* MST_kruskal(struct graph *G, int n, int m);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    
    m = n * n;

    // generate random directed graph
    struct graph G;
    directed_graph(&G, n, m);

    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", G.V[i].key);
    }
    printf("]\n");

    
    int *MST = MST_kruskal(&G, n, m);
    printf("MST Edges (from, to, weight): [");
    for (int i=0; i<n-1; i++) {
        printf(" (%d, %d, %d) ", G.E[MST[i]].from, G.E[MST[i]].to, G.E[MST[i]].w);
    }
    printf("]\n");

    return 0;
}