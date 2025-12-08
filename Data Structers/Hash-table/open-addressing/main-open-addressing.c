#include <stdio.h>

struct node {
    int key;
    int satalite;
};

int main() {
    #define NIL -1
    int hash_insert(struct node *T, int k, int m, char p);
    int hash_search(struct node *T, int k, int m, char p);
    int m;
    char p;

    // get hash-table's size
    do {
        printf("Enter hash table size(size>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);
    // get probing type
    do {
        printf("Enter probing type linear(L) or quadratic(Q) or double(D): ");
        scanf("%c", &p);
    }
    while (p != 'L' && p != 'Q' && p != 'D');

    // create hash-table
    struct node T[m];
    for (int i=0; i<m; i++) {
        T[i].key = NIL;
    }

    // op to hold operation to be performed
    char op;
    // key to hold element value
    // index to hold element's address
    int key, index;
    while (1) {
        do {
            printf("Choose operation insert(i) or search(s) or print(p): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 's' && op != 'p');

        if (op == 'i') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            hash_insert(T, key, m, p);
        }
        else if (op == 's') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            index = hash_search(T, key, m, p);
            if (index != NIL) {
                printf("Found at %d\n", index);
            }
            else {
                printf("Not found\n");
            }
        }
        else {
            printf("Hash Table: [");
            for (int i=0; i<m; i++) {
                printf(" %d ", T[i].key);
            }
            printf("]\n");
        }
    }

    return 0;
}