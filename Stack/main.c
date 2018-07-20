#include "stack.h"
#include <stdio.h>

int main()
{
    int capacity = 10;
    struct Stack *stack = create_stack(capacity);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    for (int i=0; i<4; i++) {
        printf("%d ", top(stack));
        pop(stack);
    }
    printf("\n");

    dispose_stack(&stack);

    stack = create_stack(capacity);
    for (int i=0; i<capacity; i++)
        push(stack, i*2);

    for (int i=0; i<capacity; i++) {
        printf("%d ", top(stack));
        pop(stack);
    }
    printf("\n");
}
