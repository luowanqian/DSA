#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int capacity;
    int top;
    int *array;
};

int is_empty(struct Stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        return 0;
    }

    return (stack->top == -1);
}

int is_full(struct Stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        return 0;
    }

    return (stack->top >= stack->capacity-1);
}

struct Stack* create_stack(int capacity)
{
    struct Stack *stack;

    if (capacity < 1) {
        fprintf(stderr, "Stack size is too small.\n");
        exit(1);
    }

    stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    if (stack->array == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }

    return stack;
}

void dispose_stack(struct Stack **pstack)
{
    if (pstack == NULL || *pstack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        exit(1);
    }

    free((*pstack)->array);
    free(*pstack);
    *pstack = NULL;
}

void push(struct Stack *stack, int data)
{
    if (stack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        exit(1);
    }

    if (is_full(stack)) {
        fprintf(stderr, "Full stack\n");
        exit(1);
    }

    stack->array[++stack->top] = data;
}

void pop(struct Stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        exit(1);
    }

    if (is_empty(stack)) {
        fprintf(stderr, "Empty stack\n");
        exit(1);
    }

    stack->top--;
}

int top(struct Stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "stack is NULL\n");
        exit(1);
    }

    if (is_empty(stack)) {
        fprintf(stderr, "Empty stack\n");
        exit(1);
    }

    return stack->array[stack->top];
}
