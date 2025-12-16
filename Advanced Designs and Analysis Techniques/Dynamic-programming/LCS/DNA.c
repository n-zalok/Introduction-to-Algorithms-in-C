#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

char* DNA(int n) {
    void random_array(int arr[], int n, int min, int max);

    if (n <= 0) {
        perror("n must be positive");
    }
    
    int x[n+1];
    random_array(x, n+1, 0, 3);

    char *X = (char *)malloc((n+1) * sizeof(char));
    for (int i=1; i<=n; i++) {
        if (x[i] == 0) {
            X[i] = 'A';
        }
        else if (x[i] == 1) {
            X[i] = 'G';
        }
        else if (x[i] == 2) {
            X[i] = 'C';
        }
        else {
            X[i] = 'T';
        }
    }

    return X;
}