// s and f are start and finish times
// k is the last added activity
// n is the number of activities
void recursive_activity_selector(int *s, int *f, int k, int n, int *A, int *counter) {
    int m = k+1;

    while (m <= n && s[m] < f[k]) {  // while current activity is not compatible
        m += 1;  // move to the next
    }

    if (m <= n) {  // if compatible
        A[(*counter)++] = m;  // add it
        recursive_activity_selector(s, f, m, n, A, counter);  // find the next compatible one
    }
}