#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    #define INF 2147483647

    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    void merge_sort(int arr[], int p, int r);
    void recursive_activity_selector(int *s, int *f, int k, int n, int *A, int *counter);
    int n, max;

    // get number of activities and max finish time
    do {
        printf("Enter number of activities(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    do {
        printf("Enter max finish time(max>0): ");
        scanf("%d", &max);
    }
    while (max <= 0);
    
    // generate finish times
    int f[n+1];
    random_array(f, n+1, 1, max);
    merge_sort(f, 0, n);

    // generate start times
    int s[n+1];
    for (int i=0; i<=n; i++) {
        s[i] = f[i] - ((rand() % (f[i])) + 1);  // [1, f[i]]
    }
    f[0] = -INF;

    // print start and finish times
    printf("Start times:  [");
    for (int i=1; i<=n; i++) {
        printf(" %d ", s[i]);
    }
    printf("]\n");

    printf("Finish times: [");
    for (int i=1; i<=n; i++) {
        printf(" %d ", f[i]);
    }
    printf("]\n");

    // A to hold compatible activities
    int A[n+1];
    // counter to hold number of activities in A
    int counter = 1;

    // get max number of compatible activities
    recursive_activity_selector(s, f, 0, n, A, &counter);
    printf("Maximum number of compatible activities: %d\n", counter-1);
    printf("Compatible activities: [");
    for (int i=1; i<counter; i++) {
        printf(" (%d, %d) ", s[A[i]], f[A[i]]);
    }
    printf("]\n");

    return 0;
}