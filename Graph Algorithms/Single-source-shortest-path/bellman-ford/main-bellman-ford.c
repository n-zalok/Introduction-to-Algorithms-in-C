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
    int bellman_ford(struct graph *G, int n, int m, int s);
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
    
    // compute shortest paths
    int s = rand() % n;  // pick a source
    printf("source: %d\n", s);
    if (bellman_ford(&G, n, m, s)) {  // no negative cycle
        // print shortest paths
        printf("(vertex, shortest-path): [");
        for (int i=0; i<n; i++) {
            printf(" (%d, %d) ", G.V[i].key, G.V[i].d);
        }
        printf("]\n");
    }
    else {  // negative cycle
        printf("A negative cycle exists\n");
    }

    return 0;
}