#include <stdio.h>
#include <errno.h>

struct stack {
    int* arr;
    int size;
    int top;  // last added element
};

int pop(struct stack *S) {
    int stack_empty(struct stack S);

    if (stack_empty(*S)) {
        perror("stack underflow");
    }
    else {
        S->top -= 1;
        return S->arr[S->top+1];
    }
}