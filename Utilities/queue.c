#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int capacity;
    int head;
    int tail;
    int *array;
};

int is_empty(struct Queue *queue)
{
    if (queue == NULL) {
        fprintf(stderr, "queue is NULL\n");
        exit(1);
    }

    return (queue->head == queue->tail);
}

int is_full(struct Queue *queue)
{
    if (queue == NULL) {
        fprintf(stderr, "queue is NULL\n");
        exit(1);
    }

    int capacity = queue->capacity;

    return ((queue->tail + 1) % (capacity + 1) == queue->head);
}

struct Queue* create_queue(int capacity)
{
    if (capacity < 1) {
        fprintf(stderr, "Queue size is too small.\n");
        exit(1);
    }

    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }

    queue->array = (int *)malloc(sizeof(int) * (capacity + 1));
    if (queue->array == NULL) {
        fprintf(stderr, "Out of space.\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

void dispose_queue(struct Queue **pQueue)
{
    if (pQueue == NULL || *pQueue == NULL)
        return;

    free((*pQueue)->array);
    free(*pQueue);
    *pQueue = NULL;
}

void enqueue(struct Queue *queue, int data)
{
    if (is_full(queue)) {
        fprintf(stderr, "The queue is full.\n");
        exit(1);
    }

    queue->array[queue->tail] = data;
    queue->tail = (queue->tail + 1) % (queue->capacity + 1);
}

void dequeue(struct Queue *queue)
{
    if (queue == NULL) {
        fprintf(stderr, "queue is NULL\n");
        exit(1);
    }

    if (is_empty(queue)) {
        fprintf(stderr, "The queue is empty.\n");
        exit(1);
    }

    queue->head = (queue->head + 1) % (queue->capacity + 1);
}

int front(struct Queue *queue)
{
    if (queue == NULL) {
        fprintf(stderr, "queue is NULL\n");
        exit(1);
    }

    if (is_empty(queue)) {
        fprintf(stderr, "The queue is empty.\n");
        exit(1);
    }

    return queue->array[queue->head];
}
