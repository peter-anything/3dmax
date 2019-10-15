#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include "Object.h"

typedef struct ArrayList
{
    int size;
    int maxSize;
    Object** arr;

}ArrayList;

ArrayList* ArrayListCreate();
void ArrayListAdd(ArrayList* list, void* val, enum DATA_TYPE type);
Object* ArrayListGetAt(ArrayList*, int);
void ArrayListSort(ArrayList*);
#endif