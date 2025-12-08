#include <stdio.h>
#include <errno.h>

struct stack {
    int* arr;
    int size;
    int top;  // last added element
};

void push(struct stack *S, int x) {
    if (S->top == S->size) {
        perror("stack overflow");
    }
    else {
        S->top += 1;
        S->arr[S->top] = x;
    }
}