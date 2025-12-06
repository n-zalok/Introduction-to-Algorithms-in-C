#include <stdlib.h>

struct node_ll {
    int key;
    char color;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

void RB_single_list_insert(struct ll *L, int k, char c) {
    #define NULL ((void *)0)

    struct node_ll *x = (struct node_ll *)malloc(sizeof(struct node_ll));
    x->key = k;
    x->color = c;

    x->next = L->head;
    L->head = x;
}