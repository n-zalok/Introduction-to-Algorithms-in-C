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

    // create the sentenil node
    struct node null;
    null.color = 'b';

    // create RB-tree
    struct tree T;
    T.root = &null;
    T.null = &null;
    
    // op to hold operation to be performed
    char op;
    // key to hold element value
    int key;
    // current to hold node's address
    struct node *current;
    while (1) {
        do {
            printf("Choose operation insert(i) or search(s) or delete(d) or print(p): ");
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

            if ( RB_iterative_tree_search(&T, T.root, key) != T.null) {
                printf("Found\n");
            }
            else {
                printf("Not found\n");
            }
        }
        else if (op == 'd') {
            printf("Enter key: ");
            scanf("%d", &key);

            current = RB_iterative_tree_search(&T, T.root, key);
            if (current != T.null) {
                RB_delete(&T, current);
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