#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
    int key;
    char color;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
    struct node *null;
};

void RB_insert(struct tree *T, int k) {
    void RB_insert_fixup(struct tree *T, struct node *z);

    struct node *z = (struct node *)malloc(sizeof(struct node));  // new node to be inserted
    z->key = k;
    struct node *y = T->null;  // z's parent
    struct node *x = T->root;  // placeholder

    while (x != T->null) {  // find correct place for z
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else if (z->key > x->key) {
            x = x->right;
        }
        else {
            perror("duplicate key");
            return;
        }
    }

    // insert z
    z->p = y;
    if (y == T->null) {
        T->root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }

    z->left = T->null;
    z->right = T->null;
    z->color = 'r';

    // fix what insertion messed up
    RB_insert_fixup(T, z);
}