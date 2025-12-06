#include <stdio.h>

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

int main() {
    void RB_tree_draw(struct tree *T, struct node *x, int m);
    void RB_insert(struct tree *T, int k);
    struct node* RB_iterative_tree_search(struct tree *T, struct node *x, int k);
    void RB_delete(struct tree *T, struct node *z);
    int m;

    // get max drawing level
    do {
        printf("Enter max drawing level(level>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);

    struct node null;
    null.color = 'b';
    struct tree T;
    T.root = &null;
    T.null = &null;
    

    char op;
    int key;
    struct node *z;
    struct node *current;
    while (1) {
        do {
            printf("Choose operation insert(i) or delete(d) or search(s) or print(p): ");
            scanf("%c", &op);
        }
        while (op != 'i' && op != 'd' &&  op != 's' && op != 'p');

        if (op == 'i') {
            printf("Enter key(distinct): ");
            scanf("%d", &key);
            RB_insert(&T, key);
        }
        else if (op == 's') {
            printf("Enter key: ");
            scanf("%d", &key);

            z = RB_iterative_tree_search(&T, T.root, key);
            if ( z != T.null) {
                printf("Found\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'd') {
            printf("Enter key: ");
            scanf("%d", &key);

            z = RB_iterative_tree_search(&T, T.root, key);
            if (z != T.null) {
                RB_delete(&T, z);
                printf("Node deleted\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else {
            RB_tree_draw(&T, T.root, m);
        }
    }

    return 0;
}