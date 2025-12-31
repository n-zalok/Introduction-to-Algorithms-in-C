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
    srand(time(NULL));
    void DAG(struct graph *G, int n, int m);
    struct ll* adjacency_list(struct graph *G, int n, int m, char type);
    void DAG_shortest_path(struct graph *G, int n, int m, struct ll *Adj, int s);
    int n, m;

    // get number of vertices and edges
    do {
        printf("Enter number of vertices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    int max_edges = ((n*n)-n)/2;
    do {
        printf("Enter number of edges(0<=m<=%d): ", max_edges);
        scanf("%d", &m);
    }
    while (m < 0 || m > max_edges);

    // generate random directed acyclic graph
    struct graph G;
    DAG(&G, n, m);

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

    struct ll *Adj = adjacency_list(&G, n, m, 'd');
    int s = rand() % n;
    printf("source: %d\n", s);
    DAG_shortest_path(&G, n, m, Adj, s);

    printf("(vertex, shortest-path): [");
    for (int i=0; i<n; i++) {
        printf(" (%d, %d) ", G.V[i].key, G.V[i].d);
    }
    printf("]\n");

    return 0;
}