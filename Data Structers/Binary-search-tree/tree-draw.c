#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NULL ((void *)0)
#define INF 2147483647

struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node_ll {
    int key;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};


void tree_darw(struct node *x, int m) {
    struct ll* build_map(struct node *x, int *most_negative, int *most_positive, int *h, int m);

    int most_negative, most_positive, h;
    most_negative = 0;
    most_positive = 0;
    h = -1;

    struct ll *T = build_map(x, &most_negative, &most_positive, &h, m);

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

        current = T[i].head;
        while (current != NULL) {
            if (current->key != INF) {
                // print node
                printf("%0*d", digits, current->key);
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

struct ll* build_map(struct node *x, int *most_negative, int *most_positive, int *h, int m) {
    void recursive_build_map(struct node *x, struct ll *T, int *most_negative, int *most_positive, int *h, int m, int depth);
    struct ll *T = malloc(m * sizeof *T);
    for (int i = 0; i < m; i++) {
        T[i].head = NULL;
    }

    recursive_build_map(x, T, most_negative, most_positive, h, m, 0);
    return T;
}


void recursive_build_map(struct node *x, struct ll *T, int *most_negative, int *most_positive, int *h, int m, int depth) {
    void single_list_insert(struct ll *L, int k);

    if (x != NULL && depth < m) {
        if (x->key < *most_negative) {
            *most_negative = x->key;
        }
        else if (x->key > *most_positive) {
            *most_positive = x->key;
        }

        if (depth > *h) {
            *h = depth;
        }

        recursive_build_map(x->right, T, most_negative, most_positive, h, m, depth+1);
        single_list_insert(&T[depth], x->key);
        recursive_build_map(x->left, T, most_negative, most_positive, h, m, depth+1);
    }
    else if (x == NULL && depth < m) {
        recursive_build_map(NULL, T, most_negative, most_positive, h, m, depth+1);
        single_list_insert(&T[depth], INF);
        recursive_build_map(NULL, T, most_negative, most_positive, h, m, depth+1);
    }
}