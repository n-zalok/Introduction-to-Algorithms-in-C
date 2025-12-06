#include <stdio.h>

struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

int main() {
    #define NULL ((void *)0)
    void draw_tree(struct node *x, int m);
    void tree_insert(struct tree *T, int k);
    struct node* iterative_tree_search(struct node *x, int k);
    void transplant(struct tree *T, struct node *u, struct node *v);
    void tree_delete(struct tree *T, struct node *z);
    void inorder_tree_walk(struct node *x);
    int m;

    // get max drawing level
    do {
        printf("Enter max drawing level(level>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);

    struct tree T;
    T.root = NULL;

    char op;
    int key;
    struct node *z;
    struct node *current;
    while (1) {
        do {
            printf("Choose operation insert(i) or delete(d) or search(s) or print(p) or walk(w): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 'd' && op != 's' && op != 'p' && op != 'w');

        if (op == 'i') {
            printf("Enter key(distinct): ");
            scanf("%d", &key);
            tree_insert(&T, key);
        }
        else if (op == 's') {
            printf("Enter key: ");
            scanf("%d", &key);

            z = iterative_tree_search(T.root, key);
            if ( z != NULL) {
                printf("Found\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'd') {
            printf("Enter key: ");
            scanf("%d", &key);

            z = iterative_tree_search(T.root, key);
            if (z != NULL) {
                tree_delete(&T, z);
                printf("Node deleted\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'w') {
            printf("[");
            inorder_tree_walk(T.root);
            printf("]\n");
        }
        else {
            draw_tree(T.root, m);
        }
    }

    return 0;
}