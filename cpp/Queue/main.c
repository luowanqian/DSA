#include "queue.h"
#include <stdio.h>

int main()
{
    int capacity = 10;
    struct Queue *queue = create_queue(capacity);

    for (int i=0; i<capacity; i++)
        enqueue(queue, i);

    for (int i=0; i<capacity; i++) {
        printf("%d ", front(queue));
        dequeue(queue);
    }
    printf("\n");

    return 0;
}
