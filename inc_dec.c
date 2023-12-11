#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to print the minimum sequence based on the pattern
void printMinimumSequence(char* pattern, int n) {
    if (n < 1) {
        printf("Invalid input\n");
        return;
    }

    struct Stack* stack = createStack(n + 1); // Initialize a stack with capacity n+1

    for (int i = 1; i <= n + 1; i++) {
        push(stack, i);

        if (i == n + 1 || pattern[i - 1] == 'I') {
            while (!isEmpty(stack)) {
                printf("%d", pop(stack));
            }
        }
    }
}

int main() {
    char pattern[] = "IDID"; // Example pattern
    int n = sizeof(pattern) - 1; // Calculate the length of the pattern

    printf("Minimum sequence for the pattern \"%s\":\n", pattern);
    printMinimumSequence(pattern, n);
    printf("\n");

    return 0;
}
