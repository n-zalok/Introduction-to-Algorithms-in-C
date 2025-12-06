#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void tree_insert(struct tree *T, int k) {
    #define NULL ((void *)0)

    struct node *z = (struct node *)malloc(sizeof(struct node));
    z->key = k;
    struct node *y = NULL;
    struct node *x = T->root;

    while (x != NULL) {
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

    z->p = y;
    if (y == NULL) {
        T->root = z; 
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}