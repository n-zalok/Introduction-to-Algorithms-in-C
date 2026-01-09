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
    #define NIL -1
    #define INF 2147483647
    srand(time(NULL));
    void directed_graph(struct graph *G, int n, int m);
    int*** repeated_squaring_recursive(int **W, int **P, int n);
    void print_all_pairs_path(int **P, int i, int j);
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

    // initialize weight matrix W and parent matrix P
    // W[i][j] is 
    // weight of the edge (i, j) if (i, j) belongs to E
    // 0 if  i = j
    // infinity otherwise
    // P[i][j] is
    // i if (i, j) belongs to E
    // NIL otherwise
    int **W = malloc(sizeof(int*) * n);
    int **P = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        W[i] = malloc(sizeof(int) * n);
        P[i] = malloc(sizeof(int) * n);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                W[i][j] = 0;
            }
            else {
                W[i][j] = INF;
            }

            P[i][j] = NIL;
        }
    }
    for (int i=0; i<m; i++) {
        int u = G.E[i].from;
        int v = G.E[i].to;
        int w = G.E[i].w;

        if (u != v) {
            W[u][v] = w;
            P[u][v] = u;
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
    

    // compute shortest paths matrix L and 
    // its corresponding parent matrix P_print
    int ***location = repeated_squaring_recursive(W, P, n);
    int **L = location[0];
    int **P_print = location[1];

    // print all pairs paths
    printf("All pairs paths:\n");
    for (int i=0; i<n; i++) {
        printf("Source: %d\n", i);
        for (int j=0; j<n; j++) {
            printf("To %d (%d): ", j, L[i][j]);
            print_all_pairs_path(P_print, i, j);
            printf("\n");
        }
        printf("\n");
    }
    

    return 0;
}