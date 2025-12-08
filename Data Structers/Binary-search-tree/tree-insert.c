#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
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

    struct node *z = (struct node *)malloc(sizeof(struct node));  // new node to be inserted
    z->key = k;
    struct node *y = NULL;  // z's parent
    struct node *x = T->root;  // placeholder

    while (x != NULL) { // find correct place for z
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