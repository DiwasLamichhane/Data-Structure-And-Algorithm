// WAP to convert a given infix expression ((a+(b*c))-d) to a postfix function.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack operations
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get precedence of an operator
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; ++i) {
        // If the scanned character is an operand, add it to the output
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix[j++] = infix[i];

        // If the scanned character is an opening parenthesis, push it to the stack
        else if (infix[i] == '(')
            push(stack, infix[i]);

        // If the scanned character is a closing parenthesis, pop and output from the stack until an opening parenthesis is encountered
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                printf("Invalid infix expression!\n");
            else
                pop(stack); // Discard the opening parenthesis
        }

        // If the scanned character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(peek(stack)))
                postfix[j++] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack))
        postfix[j++] = pop(stack);

    postfix[j] = '\0'; // Append null character to the postfix expression
}

int main() {
    char infix[50];
    char postfix[50];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
