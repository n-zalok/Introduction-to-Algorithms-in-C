#include <stdio.h>
#include <math.h>

struct node {
    double value;           
    struct node *next;
    struct node *prev; 
};

void insertion_sort_linked_list(struct node start) {
    #define NULL ((void *)0)

    struct node *current = &start;  // current element
    struct node *head;              // comparison head
    double key;                     // current value

    // insertion sort
    while ((current->next)->next != NULL) {
        current = current->next;
        head = current;
        key = current->value;

        do {
            head = head->prev;
            if (head->value > key) {
                (head->next)->value = head->value;
            }
            else {
                break;
            }
        }
        while (head->prev != NULL);

        head->value = key;
    }
}
