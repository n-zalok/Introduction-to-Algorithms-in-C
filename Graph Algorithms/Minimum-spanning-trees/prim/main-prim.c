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

struct node_ll {
    int key;
    int w;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

int main() {
    #define NIL -1
    srand(time(NULL));
    void undirected_graph(struct graph *G, int n, int m);
    void edge_quick_sort(struct edge *E, int p, int r);
    struct ll* adjacency_list(struct graph *G, int n, int m, char type);
    void MST_prim(struct graph *G, int n, struct ll *Adj, int r);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    
    // set m to max edges to guarantee multiple possible trees
    // such that the problem is not trivial
    m = ((n*n)-n)/2;

    // generate random directed graph
    struct graph G;
    undirected_graph(&G, n, m);
    edge_quick_sort(G.E, 0, m-1);

    // print vertices and edges
    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", G.V[i].key);
    }
    printf("]\n");

    printf("Sorted edges (from, to, weight): [");
    for (int i=0; i<m; i++) {
        printf(" (%d, %d, %d) ", G.E[i].from, G.E[i].to, G.E[i].w);
    }
    printf("]\n");

    // get adjacency list
    struct ll *Adj = adjacency_list(&G, n, m, 'u');

    // construct MST with root r
    int r = rand() % n;
    printf("root: %d\n", r);
    MST_prim(&G, n, Adj, r);

    // print MST edges
    printf("MST Edges (from, to, weight): [");
    for (int i=0; i<n; i++) {
        if (G.V[i].p != NIL) {
            printf(" (%d, %d, %d) ",  G.V[i].p, G.V[i].key, G.V[i].d);
        }
    }
    printf("]\n");


    return 0;
}