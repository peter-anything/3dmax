#include "Object.h"
#include <malloc.h>

Object* ObjectCreate(void * val, enum DATA_TYPE type)
{
    Object* obj = (Object *)malloc(sizeof(Object));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->value = val;
    obj->dataType = type;

    return obj;
}

int ObjectIntValue(Object* obj)
{
    if (obj->dataType == TYPE_INT)
    {
        int* val = (int*)obj->value;
        return *((int*)obj->value);
    }

    return -1;
}

Object* ConvertObjectFromInt(int * val)
{
    Object* obj = ObjectCreate(val, TYPE_INT);
    return obj;
}