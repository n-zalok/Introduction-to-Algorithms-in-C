#include <stdlib.h>

// return pointers to L and P_
// L_current[i][j] is the current shortest path from i to j
// P_current[i][j] is the parent of j in the current shortest path from i to j
// W is weight matrix and P is parent matrix
int*** repeated_squaring_recursive(int **W, int **P, int n) {
    int*** extend_shortest_path(int **L, int **W, int **P, int n);
    
    // initialize shortest paths matrix L_current
    // and new parent matrix P_current
    int **L_current = malloc(sizeof(int*) * n);
    int **P_current = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        L_current[i] = malloc(sizeof(int) * n);
        P_current[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            L_current[i][j] = W[i][j];
            P_current[i][j] = P[i][j];
        }
    }

    // initialize pointers array
    int ***location = malloc(sizeof(int**) * 2);
    int m = 1;
    while (m < (n-1)) {
        location = extend_shortest_path(L_current, L_current, P_current, n);
        // make location point to latest matrices
        L_current = location[0];
        P_current = location[1];
        m = 2 * m;
    }

    return location;
}