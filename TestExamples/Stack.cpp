#include "Stack.h"

#include <stdio.h>
#include <malloc.h>

Stack* CreateStack()
{
    struct Stack* sList = (Stack*)malloc(sizeof(Stack));
    if (sList == NULL)
    {
        printf("init stack failed!");
        return NULL;
    }

    sList->base = (StackElementType *)malloc(sizeof(StackElementType) * STACK_MAX_SIZE);
    sList->maxSize = STACK_MAX_SIZE;
    sList->size = 0;
    sList->top = sList->bottom = 0;

    return sList;

}

void PushStack(Stack* stack, StackElementType data)
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

StackElementType GetTopStack(Stack* stack)
{
    return stack->base[stack->top];
}

void PopStack(Stack* stack, StackElementType* data)
{
    if (IsEmptyStack(stack))
    {
        printf("Empty Stack");
        return;
    }
    StackElementType top = stack->base[stack->top - 1];
    stack->top--;
    stack->size--;

    *data = top;
}
