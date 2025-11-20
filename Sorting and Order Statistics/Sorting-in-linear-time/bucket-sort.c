#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct node {
    double value;           
    struct node *next;
    struct node *prev; 
};

void bucket_sort(double *A, int n) {
    #define NULL ((void *)0)
    void insertion_sort_linked_list(struct node current);

    struct node B[n];
    for (int i=0; i<n; i++) {
        B[i].value = NAN;
        B[i].next = NULL;
        B[i].prev = NULL;
    }

    for (int i=0; i<n; i++) {
        struct node *current = &B[(int)floor(n*A[i])];
        while (current->next != NULL) {
            current = current->next;
        }
        current->value = A[i];

        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = NAN;
        new_node->prev = current;
        new_node->next = NULL;
        current->next = new_node;
    }

    int j = 0;
    for (int i=0; i<n; i++) {
        struct node *current = &B[i];
        if (isnan(current->value)) {
            continue;
        }

        insertion_sort_linked_list(B[i]);

        printf("Bucket %d: ", i);
        while (current->next != NULL) {
            A[j] = current->value;
            printf("%f  ", A[j]);
            j++;
            current = current->next;   
        }
        printf("\n");
    }
}