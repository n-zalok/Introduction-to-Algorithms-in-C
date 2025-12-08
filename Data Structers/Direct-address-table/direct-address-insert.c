#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
    int key;
    int satalite;
};

void direct_address_insert(struct node *T, int k) {
    #define NIL -1

    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->key = k;

    if (T[x->key].key == NIL) {
        T[x->key] = *x;
    }
    else {
        perror("Element with the same key exists");
    }
}