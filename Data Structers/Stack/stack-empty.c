struct stack {
    int* arr;
    int size;
    int top;  // last added element
};

int stack_empty(struct stack S) {
    if (S.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}