int linear_probing(int k, int i, int m) {
    int hash(int k, int m);

    int result = hash(k, m) + i;
    while (result >= m) {  // keep index < m
        result -= m;
    }
    return result;
}