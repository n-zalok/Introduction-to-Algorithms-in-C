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
    void chained_hash_delete(struct dll *T, struct node x, int m);
    int m;

    // get hash table size
    do {
        printf("Enter hash table size(size>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);

    struct dll T[m];
    for (int i=0; i<m; i++) {
        T[i].head = NULL;
    }

    char op;
    int key;
    struct node *x;
    struct node *current;
    while (1) {
        do {
            printf("Choose operation insert(i) or delete(d) or search(s) print(p): ");
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
        else if (op == 'd') {
            do {
                printf("Enter key(key>=0): ");
                scanf("%d", &key);
            }
            while (key < 0);

            x = chained_hash_search(T, key, m);

            if (x != NULL) {
                chained_hash_delete(T, *x, m);
                printf("Element deleted\n");
            }
            else {
                printf("Not found\n");
            }
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