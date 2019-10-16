#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef enum DATA_TYPE
{
    TYPE_INT,
    TYPE_CHAR,
} workday;

typedef struct Object
{
    void* value;
    enum DATA_TYPE dataType;
} Object;

Object* ObjectCreate(void* val, enum DATA_TYPE type);
Object* ConvertObjectFromInt(int* val);
Object* ConvertObjectFromInt(int *);
Object** ConvertObjectFromIntArr(int arr[], int length);

int ObjectIntValue(Object*);
#endif