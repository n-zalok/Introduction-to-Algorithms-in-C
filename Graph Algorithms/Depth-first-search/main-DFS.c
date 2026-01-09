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
    void directed_graph(struct graph *G, int n, int m);
    struct ll* adjacency_list(struct graph *G, int n, int m, char type);
    void DFS(struct graph *G, int n, struct ll *Adj);
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

    // print vertices and edges
    printf("Vertices: [");
    for (int i=0; i<n; i++) {
        printf(" %d ", G.V[i].key);
    }
    printf("]\n");

    printf("Edges: [");
    for (int i=0; i<m; i++) {
        printf(" (%d, %d) ", G.E[i].from, G.E[i].to);
    }
    printf("]\n");

    // print adjacency list
    struct ll *Adj = adjacency_list(&G, n, m, 'd');
    printf("Adjacency list:\n");
    for (int i=0; i<n; i++) {
        printf("%d :", i);

        struct node_ll *v = Adj[i].head;
        while (v != NULL) {
            printf(" %d ", v->key);
            v = v->next;
        }

        printf("\n");
    }

    // do DFS
    DFS(&G, n, Adj);

    // pick a vertex then print path from it to its root
    int v = rand() % n;
    printf("Path from %d to its root: ", v);
    while (v != NIL) {
        printf(" %d ", v);
        v = G.V[v].p;
    }
    printf("\n");

    return 0;
}