#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

#define MAX_SIZE 20

typedef struct Queue
{
    List* list;
} Queue;

Queue* QueueCreate();
void QueueDestroy(Queue* q);
void QueueClear(Queue* q);
bool QueueIsEmpty(Queue* q);
int QueueLength(Queue* q);
bool QueueEn(Queue* q, void * data);
void* QueueDe(Queue* q);
#endif // !QUEUEARRAY_H