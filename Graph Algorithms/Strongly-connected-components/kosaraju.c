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

// construct a forest containing all vertices of G
// where each tree is a strongly-connected component(SCC)
void kosaraju(struct graph *G, int n, int m, struct ll *Adj) {
    struct ll* topological_sort(struct graph *G, int n, struct ll *Adj);
    struct ll* adjacency_list(struct graph *G, int n, int m, char type);
    void SCCs_DFS(struct graph *G, int n, struct ll *Adj, struct ll *order);

    // this is not a topological sort because G is not a DAG
    // we just vertices ordered by their finish times
    struct ll *order = topological_sort(G, n, Adj);

    // construct E transpose
    struct edge E_T[m];
    for (int i=0; i<m; i++) {
        E_T[i].from = G->E[i].to;
        E_T[i].to = G->E[i].from;
    }

    // initialize G transpose
    struct graph G_T;
    G_T.V = G->V;
    G_T.E = E_T;

    // create adjacency list of G transpose
    struct ll *Adj_T = adjacency_list(&G_T, n, m, 'd');

    // construct forest of SCCs
    SCCs_DFS(&G_T, n, Adj_T, order);
}