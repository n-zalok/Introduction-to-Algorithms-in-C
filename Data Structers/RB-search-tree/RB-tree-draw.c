#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NULL ((void *)0)
#define INF 2147483647  // represent skipped virtual nodes

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

struct node_ll {
    int key;
    char color;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};


void RB_tree_draw(struct tree *T, struct node *x, int m) {  // m is maximum depth to draw
    struct ll* build_map(struct tree *T, struct node *x, int *most_negative, int *most_positive, int *h, int m);

    // h is tree's height/depth
    int most_negative, most_positive, h;
    most_negative = 0;
    most_positive = 0;
    h = -1;

    struct ll *HT = build_map(T, x, &most_negative, &most_positive, &h, m);

    // determine max number of digits to be printed per element
    // to get a symmetrical tree
    int neg_digits = (most_negative < 0) ? ((log10(abs(most_negative))) + 2) : 1;
    int pos_digits = (most_positive > 0) ? ((log10(most_positive)) + 1) : 1;
    int digits = (pos_digits > neg_digits) ? pos_digits : neg_digits;


    struct node_ll *current;
    for (int i=0; i<=h; i++) {
        int spacing = 1;  // space between elements
        int margin = 0;   // space between first element in each level and the screen
        for (int j=h-i; j>0; j--) {
            margin += (spacing+digits)/2;
            spacing = (2*spacing) + digits;
        }

        // print margin
        for (int j=margin; j>0; j--){
            printf(" ");
        }

        // print nodes at ith depth
        current = HT[i].head;
        while (current != NULL) {
            if (current->key != INF) {
                // print node
                if (current->color == 'r') {
                    printf("\033[0;31m");
                    printf("%0*d", digits, current->key);
                    printf("\033[0m"); 
                }
                else {
                    printf("%0*d", digits, current->key);
                }
            }
            else {  // skip placeholders
                for (int k=0; k<digits; k++) {
                    printf(" ");
                }
            }

            // print spacing
            for (int j=spacing; j>0; j--) {
                printf(" ");
            }
            current = current->next;
        }
        printf("\n");
    }

    printf("\n");
}


// build a chained hash-table of the nodes where T[i] is the list of nodes of ith depth 
struct ll* build_map(struct tree *T, struct node *x, int *most_negative, int *most_positive, int *h, int m) {
    void recursive_build_map(struct tree *T, struct node *x, struct ll *HT, int *most_negative, int *most_positive, int *h, int m, int depth);

    // create hash-table
    struct ll *HT = malloc(m * sizeof *HT);
    for (int i = 0; i < m; i++) {
        HT[i].head = NULL;
    }

    recursive_build_map(T, x, HT, most_negative, most_positive, h, m, 0);
    return HT;
}


void recursive_build_map(struct tree *T, struct node *x, struct ll *HT, int *most_negative, int *most_positive, int *h, int m, int depth) {
    void RB_single_list_insert(struct ll *L, int k, char c);

    if (x != T->null && depth < m) {  // if node exists add it
        if (x->key < *most_negative) {
            *most_negative = x->key;
        }
        else if (x->key > *most_positive) {
            *most_positive = x->key;
        }

        if (depth > *h) {
            *h = depth;
        }

        recursive_build_map(T, x->right, HT, most_negative, most_positive, h, m, depth+1);
        RB_single_list_insert(&HT[depth], x->key, x->color);
        recursive_build_map(T, x->left, HT, most_negative, most_positive, h, m, depth+1);
    }
    else if (x == T->null && depth < m) {  // else add a placeholder
        recursive_build_map(T, T->null, HT, most_negative, most_positive, h, m, depth+1);
        RB_single_list_insert(&HT[depth], INF, 'b');
        recursive_build_map(T, T->null, HT, most_negative, most_positive, h, m, depth+1);
    }
}