// Q. WAP to Implement Stack with an example through Push, Pop and Display elements {3,6,7,8} in stack.

#include <stdio.h>
#define MAX_SIZE 100

// Stack implementation using an array
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", element);
    } else {
        stack->data[++stack->top] = element;
        printf("Element %d pushed to the stack.\n", element);
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1;
    } else {
        return stack->data[stack->top--];
    }
}

// Display the elements in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->data[i]);
        }
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Pushing elements onto the stack
    push(&stack, 3);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);

    // Displaying elements in the stack
    display(&stack);

    // Popping elements from the stack
    int poppedElement = pop(&stack);
    if (poppedElement != -1) {
        printf("Popped element: %d\n", poppedElement);
    }

    return 0;
}
