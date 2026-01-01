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

struct node_ll {
    int key;
    int w;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

int** Johnson(struct graph *G, int n, int m) {
    #define NULL ((void *)0)
    #define INF 2147483647
    int bellman_ford(struct graph *G, int n, int m, int s);
    struct ll* adjacency_list(struct graph *G, int n, int m, char type);
    void Dijkstra(struct graph *G, int n, struct ll *Adj, int s);

    struct graph G_;
    struct vertex V[n+1];
    struct edge E[m+n];

    for (int i=0; i<n; i++) {
        V[i] = G->V[i];
    }
    V[n].key = n;
    G_.V = V;

    for (int i=0; i<m; i++) {
        E[i] = G->E[i];
    }
    for (int i=m; i<(m+n); i++) {
        E[i].from = n;
        E[i].to = i - m;
        E[i].w = 0;
    }
    G_.E = E;

    if (bellman_ford(&G_, n+1, m+n, n)) {
        int h[n+1];
        for (int i=0; i<=n; i++) {
            h[i] = G_.V[i].d;
        }
        for (int i=0; i<(m+n); i++) {
            if (G_.E[i].w != INF) {
                G_.E[i].w = G_.E[i].w + h[G_.E[i].from] - h[G_.E[i].to];
            }
        }

        struct ll *Adj = adjacency_list(&G_, n+1, m+n, 'd');
        int **D = malloc(sizeof(int*) * n);
        for (int i=0; i<n; i++) {
            D[i] = malloc(sizeof(int) * n);
        }

        for (int i=0; i<n; i++) {
            Dijkstra(G, n, Adj, i);
            for (int j=0; j<n; j++) {
                if (G->V[j].d != INF) {
                    D[i][j] = G->V[j].d + h[j] - h[i];
                }
                else {
                    D[i][j] = INF;
                }
            }
        }

        return D;
    }
    else {
        printf("A negative cycle exists\n");
        return NULL;
    }
}