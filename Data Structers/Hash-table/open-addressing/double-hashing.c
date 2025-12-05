int double_hashing(int k, int i, int m) {
    int hash(int k, int m);

    int result = hash(k, m) + (i * ((hash(k, (int)(m/2))) + 1));
    while (result >= m) {
        result -= m;
    }
    return result;
}