int linear_probing(int k, int i, int m) {
    int hash(int k, int m);

    int result = hash(k, m) + i;
    if (result < m) {
        return result;
    }
    else {
        return result - m;
    }
}