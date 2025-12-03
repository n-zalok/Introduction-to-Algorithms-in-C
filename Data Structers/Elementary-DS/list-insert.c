#include <stdlib.h>

struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

void list_insert(struct dll *L, int k) {
    #define NULL ((void *)0)

    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->key = k;

    x->next = L->head;
    if (L->head != NULL) {
        (*(L->head)).prev = x;
    }

    L->head = x;
    x->prev = NULL;
}