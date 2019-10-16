#ifndef __STACK_H__
#define __STACK_H__

#define STACK_MAX_SIZE 20

#include "Object.h"
#include <stdbool.h>

typedef struct Stack {
    Object** base;
    int top;
    int bottom;
    int maxSize;
    int size;
} Stack;

Stack* StackCreate();

void PushStack(Stack* stack, Object *obj);

bool IsEmptyStack(Stack* stack);

Object* GetTopStack(Stack* stack);

void PopStack(Stack* stack, Object *data);
#endif