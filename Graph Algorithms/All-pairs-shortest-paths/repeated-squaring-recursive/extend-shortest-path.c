#include <stdlib.h>

// return pointers to L_new and P_new
// L[i][j] is the current shortest path from i to j
// P[i][j] is the parent of j in the current shortest path from i to j
// W is weight matrix
int*** extend_shortest_path(int **L, int **W, int **P, int n) {
    #define INF 2147483647
    #define NIL -1

    // initialize new shortest paths matrix L_new
    // and new parent matrix P_new
    int **L_new = malloc(sizeof(int*) * n);
    int **P_new = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        L_new[i] = malloc(sizeof(int) * n);
        P_new[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            L_new[i][j] = INF;
            P_new[i][j] = NIL;
            for (int k=0; k<n; k++) {
                // if current shortest path from i to j L[i][j] is larger than shortest path
                // from i to k L[i][k] plus distance from k to j W[k][j] replace it
                if (L[i][k] != INF && W[k][j] != INF && L_new[i][j] > (L[i][k] + W[k][j])) {
                    L_new[i][j] = L[i][k] + W[k][j];

                    // set parent
                    if (k != j) {
                        P_new[i][j] = k;
                    }
                    else {
                        P_new[i][j] = P[i][j];
                    }
                }
            }
        }
    }

    int ***location = malloc(sizeof(int**) * 2);
    location[0] = L_new;
    location[1] = P_new;    

    return location;
}