// s and f are start and finish times
// n is the number of activities
int iterative_activity_selector(int *s, int *f, int n, int *A) {
    A[1] = 1;
    int k = 1;
    int counter = 2;

    for (int m=2; m<=n; m++) {
        if (s[m] >= f[k]) {    // if compatible
            A[counter++] = m;  // add it
            k = m;             // find the next compatible one
        }
    }

    return counter;
}