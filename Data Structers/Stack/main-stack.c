#include <stdio.h>

struct stack {
    int* arr;
    int size;
    int top;
};

int main() {
    int stack_empty(struct stack S);
    void push(struct stack *S, int x);
    int pop(struct stack *S);
    int n;

    // get array size
    do {
        printf("Enter array size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    int arr[n];
    
    struct stack S;
    S.arr = arr;
    S.size = n;
    S.top = -1; 

    int op, x;
    while (1) {
        do {
            printf("Choose operation push(1) or pop(-1) or print(0): ");
            scanf("%d", &op);
        }
        while (op != 1 && op != -1 && op != 0);

        if (op == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            push(&S, x);
        }
        else if (op == -1) {
            x = pop(&S);
            if (x) {
                printf("Value: %d\n", x);
            }
        }
        else {
            printf("Stack:\n");
            for (int i=S.top; i>=0; i--) {
                printf("%d\n", S.arr[i]);
            }
        }
    }

    return 0;
}