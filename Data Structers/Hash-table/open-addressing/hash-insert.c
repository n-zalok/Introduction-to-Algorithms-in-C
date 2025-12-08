#include <errno.h>
#include <stdio.h>

struct node {
    int key;
    int satalite;
};

int hash_insert(struct node *T, int k, int m, char p) {
    #define NIL -1
    int linear_probing(int k, int i, int m);
    int quadratic_probing(int k, int i, int m);
    int double_hashing(int k, int i, int m);

    int i = 0;
    int j;
    while (i < m) {
        if (p == 'L') {
            j = linear_probing(k, i, m);
        }
        else if (p == 'Q') {
            j = quadratic_probing(k, i, m);
        }
        else {
            j = double_hashing(k, i, m);
        }

        if (T[j].key == NIL) {
            T[j].key = k;
            return j;
        }
        else {
            i += 1;
        }
    }

    perror("hash table overflow");
}