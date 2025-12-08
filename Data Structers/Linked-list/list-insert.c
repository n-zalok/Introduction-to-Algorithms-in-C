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

    x->next = L->head;  // make x's next point to first element in list
    if (L->head != NULL) {
        (*(L->head)).prev = x;  // make first element's prev point to x
    }

    L->head = x;
    x->prev = NULL;
}