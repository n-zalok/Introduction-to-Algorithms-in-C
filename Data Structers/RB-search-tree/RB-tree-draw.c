#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 2147483647
#define NULL ((void *)0)

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


void RB_tree_draw(struct tree *T, struct node *x, int m) {
    struct ll* build_map(struct tree *T, struct node *x, int *most_negative, int *most_positive, int *h, int m);

    int most_negative, most_positive, h;
    most_negative = 0;
    most_positive = 0;
    h = -1;

    struct ll *HT = build_map(T, x, &most_negative, &most_positive, &h, m);

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
            else {
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

struct ll* build_map(struct tree *T, struct node *x, int *most_negative, int *most_positive, int *h, int m) {
    void recursive_build_map(struct tree *T, struct node *x, struct ll *HT, int *most_negative, int *most_positive, int *h, int m, int depth);
    struct ll *HT = malloc(m * sizeof *HT);
    for (int i = 0; i < m; i++) {
        HT[i].head = NULL;
    }

    recursive_build_map(T, x, HT, most_negative, most_positive, h, m, 0);
    return HT;
}


void recursive_build_map(struct tree *T, struct node *x, struct ll *HT, int *most_negative, int *most_positive, int *h, int m, int depth) {
    void RB_single_list_insert(struct ll *L, int k, char c);

    if (x != T->null && depth < m) {
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
    else if (x == T->null && depth < m) {
        recursive_build_map(T, T->null, HT, most_negative, most_positive, h, m, depth+1);
        RB_single_list_insert(&HT[depth], INF, 'b');
        recursive_build_map(T, T->null, HT, most_negative, most_positive, h, m, depth+1);
    }
}