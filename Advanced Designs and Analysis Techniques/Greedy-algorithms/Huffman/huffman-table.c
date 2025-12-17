#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct node_ll {
    char character;
    char *code;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

struct node_ll* huffman_table(struct node *root) {
    void table_recursive(struct ll *L, struct node *x, char *code, int length);

    struct ll *L = malloc(sizeof(struct ll));
    L->head = NULL;
    char *code_left = malloc(sizeof(char));
    char *code_right = malloc(sizeof(char));

    code_left[0] = '0';
    table_recursive(L, root->left, code_left, 1);
    code_right[0] = '1';
    table_recursive(L, root->right, code_right, 1);
    return L->head;
}


void table_recursive(struct ll *L, struct node *x, char *code, int length) {
    void huffman_single_list_insert(struct ll *L, char character, char *code);

    if (x != NULL) {
        if (x->character == '!') {
            char *code_left = malloc(sizeof(char) * (length+1));
            char *code_right = malloc(sizeof(char) * (length+1));
            for (int i=0; i<length; i++) {
                code_left[i] = code[i];
                code_right[i] = code[i];
            }

            code_left[length] = '0';
            table_recursive(L, x->left, code_left, length+1);

            code_right[length] = '1';
            table_recursive(L, x->right, code_right, length+1);
        }
        else {
            char *code_string = malloc(sizeof(char) * (length+1));
            for (int i=0; i<length; i++) {
                code_string[i] = code[i];
            }
            code_string[length] = '\0';
            huffman_single_list_insert(L, x->character, code_string);
        }
    }
}