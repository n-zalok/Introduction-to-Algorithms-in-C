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
    int c;   // capacity
    int cf;  // residual capacity
};

// return maximum flow of the network
int Edmonds_Karp(struct graph *G, int n, int m, int s, int t) {
    #define INF 2147483647
    #define NIL -1
    int flow_BFS(struct graph *G, int n, struct node **M, int s, int t);

    // initialize adjacency matrix M
    struct node **M = malloc(sizeof(struct node*) * n);
    for (int i=0; i<n; i++) {
        M[i] = malloc(sizeof(struct node) * n);
    }

    // set base capacity and residual capacity to zero
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            M[i][j].c = 0;
            M[i][j].cf = 0;
        }
    }

    for (int i=0; i<m; i++) {
        int from = G->E[i].from;
        int to = G->E[i].to;

        M[from][to].c = G->E[i].c;
        M[from][to].cf = G->E[i].c;
    }

    // while augmenting path exists
    while (flow_BFS(G, n, M, s, t)) {
        int cf_p = INF;  // minimum residual capacity of the augmenting path
        int j = t;       // start at the sink

        // while there are vertices on the path
        while (G->V[j].p != NIL) {
            int i = G->V[j].p;  // parent of j
            // if the residual capacity from i to j M[i][j]
            // is less than current minimum replace it
            if (M[i][j].cf < cf_p) {
                cf_p = M[i][j].cf;
            }

            // move one step closer to the source
            j = i;
        }

        // modify residual capacities on the augmenting path
        // to accept the minimum cf_p

        j = t;  // return to the sink
        // while there are vertices on the path
        while (G->V[j].p != NIL) {
            int i = G->V[j].p;               // parent of j
            M[i][j].cf = M[i][j].cf - cf_p;  // subtract from the edge on the path
            M[j][i].cf = M[j][i].cf + cf_p;  // add to the reverse edge

            // move one step closer to the source
            j = i;
        }
    }

    // get maximum flow
    int max_flow = 0;
    for (int i=0; i<n; i++) {
        // if (s, i) belongs to E: f(s,i) = c(s,i) - cf(s,i)
        // so summing those we get flow out from the source f_out

        // else if (s, i) does not belong to E:
        // 1- (i, s) belongs to E: f(i, s) = cf(s, i)  [which we get here since c(s, i) = 0]
        // 2- (i, s) does not belong to E: c(s, i) = cf(s, i) = 0
        // so summing those we get minus flow into the source -f_in

        // in total we get f_out - f_in = maximum flow 
        max_flow += M[s][i].c - M[s][i].cf;
    }

    return max_flow;
}