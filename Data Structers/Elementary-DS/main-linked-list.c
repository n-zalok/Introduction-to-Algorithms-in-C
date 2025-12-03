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
    void list_delete(struct dll *L, struct node x);
    
    struct dll L;
    L.head = NULL;

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
            printf("Enter key: ");
            scanf("%d", &key);
            
            list_insert(&L, key);
        }
        else if (op == 'd') {
            printf("Enter key: ");
            scanf("%d", &key);
            x = list_search(L, key);

            if (x != NULL) {
                list_delete(&L, *x);
                printf("Element deleted\n");
            }
            else {
                printf("Not found\n");
            }
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