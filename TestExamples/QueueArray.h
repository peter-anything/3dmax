#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#endif // !QUEUEARRAY_H

typedef int ElementType;

#define MAX_SIZE 20

typedef struct Queue
{
    ElementType* base;
    int front;
    int rear;
    int maxSize;
    int size;
} Queue;

Queue* CreateQueue(int queenCapacity);
void DestroyQueue(Queue* q);
void ClearQueue(Queue* q);
bool IsEmptyQueue(Queue* q);
bool IsFullQueue(Queue* q);
int QueueLength(Queue* q);
bool EnQueue(Queue* q, ElementType data);
void DeQueue(Queue* q, ElementType* data);
void Traverse(Queue* q);