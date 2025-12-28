#include <stdio.h>

struct node {
    int key;
    int rank;
    struct node *p;
};

struct edge {
    struct node *from;
    struct node *to;
};

struct graph {
    struct node *V;
    struct edge *E;
};

struct node_ll {
    int key;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};


void print_connected_components(struct graph *G, int n) {
    #define NULL ((void *)0)
    struct node* find_set(struct node *x);
    void single_list_insert(struct ll *L, int k);

    struct ll T[n];
    for (int i=0; i<n; i++) {
        T[i].head = NULL;
    }

    struct ll components;
    components.head = NULL;
    for (int i=0; i<n; i++) {
        struct node *v = &(G->V[i]);
        struct node *set = find_set(v);

        if (T[(set->key)-1].head == NULL) {
            single_list_insert(&components, set->key);
        }
        single_list_insert(&T[(set->key)-1], v->key);
    }

    printf("Components:\n");
    struct node_ll *component = components.head;
    while (component != NULL) {
        printf("[");

        struct node_ll *vertex = T[(component->key)-1].head;
        while (vertex != NULL) {
            printf(" %d ", vertex->key);
            vertex = vertex->next;
        }

        printf("]\n");
        component = component->next;
    } 
}