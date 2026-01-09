#include <stdlib.h>
#include <stdio.h>

// return pointers to Dk and Pk
// Dk[i][j] is the shortest path from i to j for which all intermediate vertices are drawn from <1, 2, ..., k>
// Pk[i][j] is the parent of j in the shortest path from i to j for which all intermediate vertices are drawn from <1, 2, ..., k>
// W is weight matrix and P is parent matrix
int*** Floyd_Warshall(int **W, int **P, int n) {
    #define INF 2147483647

    // initialize Dk_1, Pk_1, Dk and Pk 
    int **Dk_1 = malloc(sizeof(int*) * n);
    int **Pk_1 = malloc(sizeof(int*) * n);
    int **Dk = malloc(sizeof(int*) * n);
    int **Pk = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        Dk_1[i] = malloc(sizeof(int) * n);
        Pk_1[i] = malloc(sizeof(int) * n);
        Dk[i] = malloc(sizeof(int) * n);
        Pk[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            Dk_1[i][j] = W[i][j];
            Pk_1[i][j] = P[i][j];
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                // if k-1 shortest path from i to j Dk_1[i][j] is larger than k-1 shortest path
                // from i to k Dk_1[i][k] plus k-1 shortest path from k to j Dk_1[k][j] replace it
                if (Dk_1[i][k] != INF && Dk_1[k][j] != INF && Dk_1[i][j] > (Dk_1[i][k] + Dk_1[k][j])) {
                    Dk[i][j] = Dk_1[i][k] + Dk_1[k][j];
                    Pk[i][j] = Pk_1[k][j];
                }
                // else leave it the same
                else {
                    Dk[i][j] = Dk_1[i][j];
                    Pk[i][j] = Pk_1[i][j];

                }
            }
        }

        // exchange Dk_1 and Dk to use new values as Dk_1
        int **temp = Dk;
        Dk = Dk_1;
        Dk_1 = temp;

        // exchange Pk_1 and Pk to use new values as Pk_1
        temp = Pk;
        Pk = Pk_1;
        Pk_1 = temp;
    }

    // since we exchange Dk_1 with Dk and Pk_1 with Pk at the end of each iteration
    // Dk_1 contains latest values of Dk and Pk_1 contains latest values of Pk
    int ***location = malloc(sizeof(int**) * 2);
    location[0] = Dk_1;
    location[1] = Pk_1;

    return location;
}