# include "QueueArray.h"
#include <stdio.h>
#include <malloc.h>

Queue* CreateQueue(int queenCapacity)
{
    struct Queue* qList = (Queue*)malloc(sizeof(Queue));
    if (qList == NULL)
    {
        printf("init Queue failed");
        return NULL;
    }
    ElementType* base = (ElementType*)malloc(sizeof(ElementType) * queenCapacity);
    if (qList->base == NULL)
    {
        printf("init base failed");
        return NULL;
    }
    qList->base = base;
    qList->front = qList->rear = 0;
    qList->maxSize = queenCapacity;
    qList->size = 0;
    return qList;
}

void DestroyQueue(Queue* q)
{
    delete q;
}

void ClearQueue(Queue* q)
{
    q->size = 0;
}

bool IsEmptyQueue(Queue* q)
{
    return q->size == 0;
}

bool IsFullQueue(Queue* q)
{
    return q->size == q->maxSize;
}

int QueueLength(Queue* q)
{
    return q->size;
}

bool EnQueue(Queue* q, ElementType data)
{
    if (IsFullQueue(q))
    {
        printf("Queue is full");
        return false;
    }

    q->base[q->rear] = data;
    q->rear = (q->rear + 1) % q->maxSize;
    q->size++;

    return true;
}

void DeQueue(Queue* q, ElementType * data)
{
    if (IsEmptyQueue(q))
    {
        printf("Queue is empty");
        return ;
    }

    ElementType first = q->base[q->front];
    q->front += 1;
    *data = first;
}