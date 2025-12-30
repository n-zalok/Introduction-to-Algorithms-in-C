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

struct node_ll {
    int key;
    int w;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};


int SCCs_time = 0;

void SCCs_DFS(struct graph *G, int n, struct ll *Adj, struct ll *order) {
    #define NULL ((void *)0)
    #define NIL -1
    void SCCs_DFS_visit(struct graph *G, struct ll *Adj, int u);

    for (int i=0; i<n; i++) {
        G->V[i].color = 'w';
        G->V[i].p = NIL;
    }

    printf("SCCs:\n");
    struct node_ll *v = order->head;
    while (v != NULL) {
        if (G->V[v->key].color == 'w') {
            printf("[");
            SCCs_DFS_visit(G, Adj, v->key);
            printf("]\n");
        }

        v = v->next;
    }
}

void SCCs_DFS_visit(struct graph *G, struct ll *Adj, int u) {
    #define NULL ((void *)0)

    printf(" %d ", u);

    SCCs_time += 1;
    G->V[u].d = SCCs_time;
    G->V[u].color = 'g';

    struct node_ll *v = Adj[u].head;
    while (v != NULL) {
        if (G->V[v->key].color == 'w') {
            G->V[v->key].p = u;
            SCCs_DFS_visit(G, Adj, v->key);
        }

        v = v->next;
    }

    G->V[u].color = 'b';
    SCCs_time += 1;
    G->V[u].f = SCCs_time;
}