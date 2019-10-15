#include "ArrayList.h"
#include "Object.h"
#include "Array.h"

#include <malloc.h>

ArrayList* ArrayListCreate()
{
    ArrayList* list = (ArrayList *)malloc(sizeof(ArrayList));
    if (list == NULL)
    {
        return NULL;
    }
    Object* obj;
    list->arr = (Object **)malloc(sizeof(obj) * 10);
    list->size = 0;
    list->maxSize = 10;

    return list;
}

void ArrayListAdd(ArrayList* list, void* val, enum DATA_TYPE type)
{
    Object* obj = ObjectCreate(val, type);
    if (list->size < list->maxSize)
    {
        list->arr[list->size++] = obj;
    }
}

Object* ArrayListGetAt(ArrayList* list, int index)
{
    return list->arr[index];
}

void ArrayListSort(ArrayList* list)
{
    ArrayQuickSort(list->arr, 0, list->size - 1);
}