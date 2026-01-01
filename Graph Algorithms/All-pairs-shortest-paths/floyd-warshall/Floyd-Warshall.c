#include <stdlib.h>
#include <stdio.h>

int*** Floyd_Warshall(int **W, int **P, int n) {
    #define INF 2147483647

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
                if (Dk_1[i][k] != INF && Dk_1[k][j] != INF && Dk_1[i][j] > (Dk_1[i][k] + Dk_1[k][j])) {
                    Dk[i][j] = Dk_1[i][k] + Dk_1[k][j];
                    Pk[i][j] = Pk_1[k][j];
                }
                else {
                    Dk[i][j] = Dk_1[i][j];
                    Pk[i][j] = Pk_1[i][j];

                }
            }
        }

        int **temp = Dk;
        Dk = Dk_1;
        Dk_1 = temp;

        temp = Pk;
        Pk = Pk_1;
        Pk_1 = temp;
    }

    int ***location = malloc(sizeof(int**) * 2);
    location[0] = Dk_1;
    location[1] = Pk_1;

    return location;
}