#include <stdlib.h>
#include <stdio.h>

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

// return list A of edges used in MST
int* MST_kruskal(struct graph *G, int n, int m) {
    void make_set(struct vertex *x);
    int find_set(struct vertex *V, int x);
    void union_sets(struct vertex *V, int x, int y);
    void edge_quick_sort(struct edge *E, int p, int r);

    // initialize A
    int *A = malloc(sizeof(int) * (n-1));

    // initialize sets
    for (int i=0; i<n; i++) {
        make_set(&(G->V[i]));
    }

    // sort edges
    edge_quick_sort(G->E, 0, m-1);

    int counter = 0;
    printf("Sorted edges (from, to, weight): [");
    for (int i=0; i<m; i++) {
        int u = G->E[i].from;
        int v = G->E[i].to;
        printf(" (%d, %d, %d) ", u, v, G->E[i].w);

        // only add edges between separate sets
        if (find_set(G->V, u) != find_set(G->V, v)) {
            A[counter++] = i;
            union_sets(G->V, u, v);
        }
    }
    printf("]\n");
    
    return A;
}
