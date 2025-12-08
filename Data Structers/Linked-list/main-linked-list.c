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
    void list_insert(struct dll *L, int k);
    struct node* list_search(struct dll L, int k);
    void list_delete(struct dll *L, struct node *x);
    
    // create linked list
    struct dll L;
    L.head = NULL;

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
            printf("Enter key: ");
            scanf("%d", &key);
            
            list_insert(&L, key);
        }
        else if (op == 's') {
            printf("Enter key: ");
            scanf("%d", &key);

            if (list_search(L, key) != NULL) {
                printf("Found\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'd') {
            printf("Enter key: ");
            scanf("%d", &key);
            current = list_search(L, key);

            if (current != NULL) {
                list_delete(&L, current);
                printf("Element deleted\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else {
            printf("Linked List:\n");
            current = L.head;
            while (current != NULL) {
                printf(" %d ", current->key);
                current = current->next;
            }
            printf("\n");
        }
    }

    return 0;
}