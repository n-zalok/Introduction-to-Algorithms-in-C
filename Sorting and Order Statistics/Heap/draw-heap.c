#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

void draw_heap(struct heap A) {
    void draw_heap_recursive(struct heap A, int i, int curr_h, int digits);
    int h = floor(log2(A.heap_size)); // height of the heap

    // determine max number of digits to be printed per element
    // to get a symmetrical tree
    int most_positive = 0;
    int most_negative = 0;
    for (int i=0; i<A.heap_size; i++){
        if (A.arr[i] > most_positive) {
            most_positive = A.arr[i];
        }
        if (A.arr[i] < most_negative) {
            most_negative = A.arr[i];
        }
    }

    int pos_digits = floor(log10(most_positive)) + 1;
    int neg_digits = floor(log10(abs(most_negative))) + 2;
    int digits = (pos_digits > neg_digits) ? pos_digits : neg_digits;


    draw_heap_recursive(A, 0, h, digits);
}

void draw_heap_recursive(struct heap A, int i, int curr_h, int digits) {
    int spacing = 1;  // space between elements
    int margin = 0;   // space between first element in each level and the screen
    for (int j=curr_h; j>0; j--) {
        margin += (spacing+digits)/2;
        spacing = (2*spacing) + digits;
    }

    // print margin
    for (int j=margin; j>0; j--){
        printf(" ");
    }


    int nodes = 0;  // nodes printed this far
    int h;          // height of current node
    do {
        // print node
        printf("%0*d", digits, A.arr[i]);
        nodes++;

        // print spacing
        for (int j=spacing; j>0; j--) {
            printf(" ");
        }

        i++;
        h = floor(log2(A.heap_size)) - floor(log2(i+1));
    } 
    // if current node should be printed on the next level
    // or we reached the end of the heap
    while (h == curr_h && i < A.heap_size);


    if (i >= A.heap_size) {
        printf("\n");
    }
    else {
        for (int j=h; j>=0; j--){
            printf("\n");
        }
        // print on the next level 
        draw_heap_recursive(A, i, h, digits);
    }
}