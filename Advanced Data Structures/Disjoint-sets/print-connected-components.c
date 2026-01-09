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
    void graph_single_list_insert(struct ll *L, int key, int w);

    // T[i] contains vertices of set with ith vertex as root
    struct ll T[n];
    for (int i=0; i<n; i++) {
        T[i].head = NULL;
    }

    // roots is a ll of roots
    struct ll roots;
    roots.head = NULL;
    for (int i=0; i<n; i++) {
        int set = find_set(G->V, i);

        // if a new root was found
        // insert it into roots
        if (T[set].head == NULL) {
            graph_single_list_insert(&roots, set, 0);
        }

        // insert vertex in its list
        graph_single_list_insert(&T[set], i, 0);
    }

    // for root in roots
    printf("Connected components:\n");
    struct node_ll *u = roots.head;
    while (u != NULL) {
        printf("[");

        // print vertices that belong to that root
        struct node_ll *v = T[u->key].head;
        while (v != NULL) {
            printf(" %d ", v->key);
            v = v->next;
        }

        printf("]\n");
        u = u->next;
    } 
}