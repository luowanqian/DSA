#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

struct Queue;

int is_empty(struct Queue *queue);
int is_full(struct Queue *queue);
struct Queue* create_queue(int capacity);
void dispose_queue(struct Queue **pQueue);
void enqueue(struct Queue *queue, int data);
void dequeue(struct Queue *queue);
int front(struct Queue *queue);

#ifdef __cplusplus
}
#endif

#endif //_QUEUE_H
