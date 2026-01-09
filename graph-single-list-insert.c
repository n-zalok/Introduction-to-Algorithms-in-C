#include <stdlib.h>

struct node_ll {
    int key;
    int w;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

// insert key with weight w into L
void graph_single_list_insert(struct ll *L, int key, int w) {
    #define NULL ((void *)0)

    struct node_ll *x = (struct node_ll *)malloc(sizeof(struct node_ll));
    x->key = key;
    x->w = w;

    x->next = L->head;
    L->head = x;
}