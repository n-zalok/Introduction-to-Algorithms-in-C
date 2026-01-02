#include <stdlib.h>
#include <stdio.h>

struct vertex {
    int key;
    int p;     // parent
    char color;
};

struct edge {
    int from;
    int to;
    int c;  // capacity
};

struct graph {
    struct vertex *V;
    struct edge *E;
};

struct node {
    int c;  // capacity
    int cf;  // residual_capacity
};

int Edmonds_Karp(struct graph *G, int n, int m, int s, int t) {
    #define INF 2147483647
    #define NIL -1
    int flow_BFS(struct graph *G, int n, struct node **M, int s, int t);

    // initialize M
    struct node **M = malloc(sizeof(struct node*) * n);
    for (int i=0; i<n; i++) {
        M[i] = malloc(sizeof(struct node) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            M[i][j].c = 0;
            M[i][j].cf = 0;
        }
    }

    // set existent edges and their reverse
    for (int i=0; i<m; i++) {
        int from = G->E[i].from;
        int to = G->E[i].to;

        M[from][to].c = G->E[i].c;
        M[from][to].cf = G->E[i].c;
    }

    // get augmenting path
    while (flow_BFS(G, n, M, s, t)) {
        int cf_p = INF;
        int j = t;

        while (G->V[j].p != NIL) {
            int i = G->V[j].p;
            if (M[i][j].cf < cf_p) {
                cf_p = M[i][j].cf;
            }

            j = i;
        }

        j = t;
        while (G->V[j].p != NIL) {
            int i = G->V[j].p;
            M[i][j].cf = M[i][j].cf - cf_p;
            M[j][i].cf = M[j][i].cf + cf_p;

            j = i;
        }
    }

    // get maximum flow
    int max_flow = 0;
    for (int i=0; i<n; i++) {
        max_flow += M[s][i].c - M[s][i].cf;
    }

    return max_flow;
}