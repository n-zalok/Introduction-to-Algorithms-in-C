struct node {
    int key;
    int rank;
    struct node *p;
};

struct edge {
    struct node *from;
    struct node *to;
};

struct graph {
    struct node *V;
    struct edge *E;
};


void connected_components(struct graph *G, int n, int m) {
    void make_set(struct node *x);
    struct node* find_set(struct node *x);
    void union_sets(struct node *x, struct node *y);

    for (int i=0; i<n; i++) {
        make_set(&(G->V[i]));
    }

    for (int i=0; i<m; i++) {
        struct node *u = G->E[i].from;
        struct node *v = G->E[i].to;

        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
        }
    }
}
