#include <stdio.h>

struct node {
    int key;
    int satalite;
};

int main() {
    #define NIL -1
    void direct_address_insert(struct node *T, int k);
    struct node* direct_address_search(struct node *T, int k);
    void direct_address_delete(struct node *T, struct node *x);
    int max;

    // get max-key value to determine hash-table's size
    do {
        printf("Enter array max-key(max>=0): ");
        scanf("%d", &max);
    }
    while (max < 0);

    // create hash-table
    struct node T[max+1];
    for (int i=0; i<max+1; i++) {
        T[i].key = NIL;
    }

    // op to hold operation to be performed
    char op;
    // key to hold element value
    int key;
    // x to hold node's address
    struct node *x;
    while (1) {
        do {
            printf("Choose operation insert(i) or search(s) or delete(d) or print(p): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 'd' && op != 's' && op != 'p');

        if (op == 'i') {
            do {
                printf("Enter key(0<key<=%d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            direct_address_insert(T, key);
        }
        else if (op == 's') {
            do {
                printf("Enter key(0<key<=&d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            x = direct_address_search(T, key);
            if (x->key == NIL) {
                printf("Not found\n");
            }
            else {
                printf("Found\n");
            }
        }
        else if (op == 'd') {
            do {
                printf("Enter key(0<key<=%d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            x = direct_address_search(T, key);
            if (x->key == NIL) {
                printf("Not found\n");
            }
            else {
                direct_address_delete(T, x);
                printf("Element deleted\n");
            }
        }
        else {
            printf("Table: [");
            for (int i=0; i<max+1; i++) {
                printf(" %d ", T[i].key);
            }
            printf("]\n");
        }
    }

    return 0;
}