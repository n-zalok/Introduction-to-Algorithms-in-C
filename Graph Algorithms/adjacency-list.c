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

// retuen adjacency list of graph G
struct ll* adjacency_list(struct graph *G, int n, int m, char type) {
    void graph_single_list_insert(struct ll *L, int key, int w);

    // initialize adjacency list
    struct ll *Adj = malloc(sizeof(struct ll) * n);
    for (int i=0; i<n; i++) {
        Adj[i].head = NULL;
    }

    // directed graph
    if (type == 'd') {
        for (int i=0; i<m; i++) {
            graph_single_list_insert(&Adj[G->E[i].from], G->E[i].to, G->E[i].w);
        }
    }
    // undirected graph
    else {
        for (int i=0; i<m; i++) {
            graph_single_list_insert(&Adj[G->E[i].from], G->E[i].to, G->E[i].w);
            graph_single_list_insert(&Adj[G->E[i].to], G->E[i].from, G->E[i].w);
        }
    }

    return Adj;
}