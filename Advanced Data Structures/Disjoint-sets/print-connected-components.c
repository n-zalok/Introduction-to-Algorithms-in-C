#include <stdio.h>

// Note not all members of each structure required
// for every application but we just unify the definition
struct vertex {
    int key;
    int rank;  // to use union by rank in sets
    int p;     // parent
    int d;     // distance in BFS and discovery time in DFS
    int f;     // finish time
    char color;
};

struct edge {
    int from;
    int to;
    int w;  // weight
};

struct graph {
    struct vertex *V;
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
    int find_set(struct vertex *V, int x);
    void single_list_insert(struct ll *L, int k);

    struct ll T[n];
    for (int i=0; i<n; i++) {
        T[i].head = NULL;
    }

    struct ll components;
    components.head = NULL;
    for (int i=0; i<n; i++) {
        int set = find_set(G->V, i);

        if (T[set].head == NULL) {
            single_list_insert(&components, set);
        }
        single_list_insert(&T[set], i);
    }

    printf("Components:\n");
    struct node_ll *component = components.head;
    while (component != NULL) {
        printf("[");

        struct node_ll *u = T[component->key].head;
        while (u != NULL) {
            printf(" %d ", u->key);
            u = u->next;
        }

        printf("]\n");
        component = component->next;
    } 
}