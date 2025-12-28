#include <stdlib.h>

struct node_ll {
    int key;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

void single_list_insert(struct ll *L, int k) {
    #define NULL ((void *)0)

    struct node_ll *x = (struct node_ll *)malloc(sizeof(struct node_ll));
    x->key = k;

    x->next = L->head;
    L->head = x;
}