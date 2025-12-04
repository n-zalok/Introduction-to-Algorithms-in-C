#include <stdio.h>

struct node {
    int key;
    int satalite;
};

int main() {
    void direct_address_insert(struct node *T, struct node x);
    struct node direct_address_search(struct node *T, int k);
    void direct_address_delete(struct node *T, struct node x);
    int max;

    // get max-key value
    do {
        printf("Enter array max-key(max>=0): ");
        scanf("%d", &max);
    }
    while (max < 0);

    struct node T[max+1];
    for (int i=0; i<max+1; i++) {
        T[i].key = -1;
    }

    char op;
    int key;
    struct node x;
    while (1) {
        do {
            printf("Choose operation insert(i) or delete(d) or search(s) print(p): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 'd' && op != 's' && op != 'p');

        if (op == 'i') {
            do {
                printf("Enter key(0<key<=%d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            x.key = key;
            direct_address_insert(T, x);
        }
        else if (op == 'd') {
            do {
                printf("Enter key(0<key<=%d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            x.key = key;
            direct_address_delete(T, x);
        }
        else if (op == 's') {
            do {
                printf("Enter key(0<key<=&d): ", max);
                scanf("%d", &key);
            }
            while (key < 0 || key > max);

            x = direct_address_search(T, key);
            if (x.key == -1) {
                printf("Not found\n");
            }
            else {
                printf("Found\n");
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