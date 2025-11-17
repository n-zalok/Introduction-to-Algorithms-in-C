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
    int h = floor(log2(A.heap_size));

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
    int spacing = 1;
    int margin = 0;
    for (int j=curr_h; j>0; j--) {
        margin += (spacing+digits)/2;
        spacing = (2*spacing) + digits;
    }

    for (int j=margin; j>0; j--){
        printf(" ");
    }


    int nodes = 0;
    int h;
    do {
        printf("%0*d", digits, A.arr[i]);
        nodes++;

        for (int j=spacing; j>0; j--) {
            printf(" ");
        }

        i++;
        h = floor(log2(A.heap_size)) - floor(log2(i+1));
    } 
    while (h == curr_h && i < A.heap_size);


    if (i >= A.heap_size) {
        printf("\n");
    }
    else {
        for (int j=h; j>=0; j--){
            printf("\n");
        }
        draw_heap_recursive(A, i, h, digits);
    }
}