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


int dfs_time = 0;

struct ll* topological_sort(struct graph *G, int n, struct ll *Adj) {
    #define NIL -1
    void topological_DFS_visit(struct graph *G, struct ll *Adj, int u, struct ll *order);

    for (int i=0; i<n; i++) {
        G->V[i].color = 'w';
        G->V[i].p = NIL;
    }

    struct ll *order = malloc(sizeof(struct ll));
    for (int i=0; i<n; i++) {
        if (G->V[i].color == 'w') {
            topological_DFS_visit(G, Adj, i, order);
        }
    }

    return order;
}

void topological_DFS_visit(struct graph *G, struct ll *Adj, int u, struct ll *order) {
    #define NULL ((void *)0)
    void single_list_insert(struct ll *L, int key, int w);

    dfs_time += 1;
    G->V[u].d = dfs_time;
    G->V[u].color = 'g';

    struct node_ll *v = Adj[u].head;
    while (v != NULL) {
        if (G->V[v->key].color == 'w') {
            G->V[v->key].p = u;
            topological_DFS_visit(G, Adj, v->key, order);
        }

        v = v->next;
    }

    G->V[u].color = 'b';
    dfs_time += 1;
    G->V[u].f = dfs_time;

    single_list_insert(order, u, 0);
}