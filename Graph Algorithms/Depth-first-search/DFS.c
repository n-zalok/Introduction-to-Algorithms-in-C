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

// construct a forest containing all vertices of G
// where v.d and v.f are discovery time and finish time of v
void DFS(struct graph *G, int n, struct ll *Adj) {
    #define NIL -1
    void DFS_visit(struct graph *G, struct ll *Adj, int u);

    // initialize vertices
    for (int i=0; i<n; i++) {
        G->V[i].color = 'w';
        G->V[i].p = NIL;
    }

    for (int i=0; i<n; i++) {
        if (G->V[i].color == 'w') {
            DFS_visit(G, Adj, i);
        }
    }
}

void DFS_visit(struct graph *G, struct ll *Adj, int u) {
    #define NULL ((void *)0)

    dfs_time += 1;
    G->V[u].d = dfs_time;  // record discovery time
    G->V[u].color = 'g';

    // visit vertices reachable from u
    struct node_ll *v = Adj[u].head;
    while (v != NULL) {
        if (G->V[v->key].color == 'w') {
            G->V[v->key].p = u;
            DFS_visit(G, Adj, v->key);
        }

        v = v->next;
    }

    G->V[u].color = 'b';   // mark u as finished
    dfs_time += 1;
    G->V[u].f = dfs_time;  // record finish time
}