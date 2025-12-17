void recursive_activity_selector(int *s, int *f, int k, int n, int *A, int *counter) {
    int m = k+1;

    while (m <= n && s[m] < f[k]) {
        m += 1;
    }

    if (m <= n) {
        A[(*counter)++] = m;
        recursive_activity_selector(s, f, m, n, A, counter);
    }
}