#include <stdio.h>

struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

int main() {
    #define NULL ((void *)0)
    void chained_hash_insert(struct dll *T, int k, int m);
    struct node* chained_hash_search(struct dll *T, int k, int m);
    void chained_hash_delete(struct dll *T, struct node *x, int m);
    int m;

    // get hash-table's size
    do {
        printf("Enter hash table size(size>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);

    // create hash-table
    struct dll T[m];
    for (int i=0; i<m; i++) {
        T[i].head = NULL;
    }

    // op to hold operation to be performed
    char op;
    // key to hold element value
    int key;
    // current to hold node's address
    struct node *current;
    while (1) {
        do {
            printf("Choose operation insert(i) or search(s) or delete(d) or print(p): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 'd' && op != 's' && op != 'p');

        if (op == 'i') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            chained_hash_insert(T, key, m);
        }
        else if (op == 's') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            if (chained_hash_search(T, key, m) != NULL) {
                printf("Found\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'd') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            current = chained_hash_search(T, key, m);

            if (current != NULL) {
                chained_hash_delete(T, current, m);
                printf("Element deleted\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else {
            printf("Hash Table:\n");
            for (int i=0; i<m; i++) {
                printf("%d |", i);
                current = T[i].head;
                while (current != NULL) {
                    printf(" %d ", current->key);
                    current = current->next;
                }
                printf("\n");
            }
        }
    }

    return 0;
}