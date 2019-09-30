# include "List.h"
# include "Queue.h"

#include <stdio.h>
#include <malloc.h>

Queue* QueueCreate()
{
    struct Queue* qList = (Queue*)malloc(sizeof(Queue));
    if (qList == NULL)
    {
        printf("init Queue failed");
        return NULL;
    }

    qList->list = ListCreate();

    return qList;
}

void QueueDestroy(Queue* q)
{
    ListDestroy(q->list);
    delete q;
}

void QueueClear(Queue* q)
{
    ListClear(q->list);
}

bool QueueIsEmpty(Queue* q)
{
    return q->list->len == 0;
}

int QueueLength(Queue* q)
{
    return q->list->len;
}

bool QueueEn(Queue* q, void * data)
{
    ListAdd(q->list, data);

    return true;
}

void* QueueDe(Queue* q)
{
    ListNode * node = ListFirstDelete(q->list);

    return node->value;
}