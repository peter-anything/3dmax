#include "Stack.h"

#include <stdio.h>
#include <malloc.h>

Stack* StackCreate()
{
    struct Stack* sList = (Stack*)malloc(sizeof(Stack));
    if (sList == NULL)
    {
        printf("init stack failed!");
        return NULL;
    }

    Object* obj;
    sList->base = (Object**)malloc(sizeof(obj) * STACK_MAX_SIZE);
    sList->maxSize = STACK_MAX_SIZE;
    sList->size = 0;
    sList->top = sList->bottom = 0;

    return sList;

}

void PushStack(Stack* stack, Object* data)
{
    stack->base[stack->top++] = data;
    stack->size++;

    stack->top %= stack->maxSize;
}

bool IsEmptyStack(Stack* stack)
{
    return stack->size == 0;
}

bool IsFullStack(Stack* stack)
{
    return stack->size == stack->maxSize;
}

Object* GetTopStack(Stack* stack)
{
    return stack->base[stack->top];
}

void PopStack(Stack* stack, Object* data)
{
    if (IsEmptyStack(stack))
    {
        printf("Empty Stack");
        return;
    }
    Object* top = stack->base[stack->top - 1];
    stack->top--;
    stack->size--;

    *data = *top;
}
