#include <stdio.h>
#include <errno.h>

struct node {
    int key;
    int satalite;
};

void direct_address_insert(struct node *T, struct node x) {
    if (T[x.key].key == -1) {
        T[x.key] = x;
    }
    else {
        perror("Element with the same key exists");
    }
}