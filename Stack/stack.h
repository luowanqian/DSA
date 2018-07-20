#ifndef _STACK_H
#define _STACK_H

struct Stack;

int is_empty(struct Stack *stack);
int is_full(struct Stack *stack);
struct Stack* create_stack(int capacity);
void dispose_stack(struct Stack **pstack);
void push(struct Stack *stack, int data);
void pop(struct Stack *stack);
int top(struct Stack *stack);

#endif //_STACK_H
