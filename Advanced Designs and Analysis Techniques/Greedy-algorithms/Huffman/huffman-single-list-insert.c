#include <stdlib.h>

struct node_ll {
    char character;
    char *code;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

void huffman_single_list_insert(struct ll *L, char character, char *code) {
    #define NULL ((void *)0)

    struct node_ll *x = (struct node_ll *)malloc(sizeof(struct node_ll));
    x->character = character;
    x->code = code;

    x->next = L->head;
    L->head = x;
}