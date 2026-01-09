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
    #define INF 2147483647
    srand(time(NULL));
    void directed_graph(struct graph *G, int n, int m);
    int** transitive_closure(int **W, int n);
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
    // make all weights non-negative to avoid negative cycles
    for (int i=0; i<m; i++) {
        if (G.E[i].w < 0) {
            G.E[i].w = rand() % (2*m);
        }
    }

    // initialize weight matrix W
    // W[i][j] is 
    // weight of the edge (i, j) if (i, j) belongs to E
    // 0 if  i = j
    // infinity otherwise
    int **W = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        W[i] = malloc(sizeof(int) * n);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                W[i][j] = 0;
            }
            else {
                W[i][j] = INF;
            }
        }
    }
    for (int i=0; i<m; i++) {
        int u = G.E[i].from;
        int v = G.E[i].to;
        int w = G.E[i].w;

        if (u != v) {
            W[u][v] = w;
        }
    }

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
    
    // compute transitive closure matrix T
    int **T = transitive_closure(W, n);

    // print all reachable pairs
    printf("All reachable pairs (source, reachable vertices):\n");
    for (int i=0; i<n; i++) {
        printf("%d :", i);
        for (int j=0; j<n; j++) {
            if (T[i][j]) {
                printf(" %d ", j);
            }
        }
        printf("\n");
    }
    
    return 0;
}