#include <stdio.h>
#include <CString.h>
#include "BTree.h"
#include "Object.h"
#include "ArrayList.h"
#include "Stack.h"
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Printf.h"
#include "Array.h"

int compare(void * x, void* y)
{
    int* p1 = (int*)x;
    int* p2 = (int*)y;
    return *p1 > *p2;
}


void TestArrayList()
{
    int a[] = { 10, 30, 50, 70, 90, 100, 110, 91, 92 };
    ArrayList* list = ArrayListCreate();
    Object** objArr = ConvertObjectFromIntArr(a, 9);
    for (int i = 0; i < 9; i++)
    {
        Object* obj = objArr[i];
        if (obj->dataType == TYPE_INT)
        {
            printf("%d\t", *((int*)obj->value));
        }
    }
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        ArrayListAdd(list, &a[i], TYPE_INT);
    }
    ArrayListSort(list);
    for (int i = 0; i < 9; i++)
    {
        Object* obj = ArrayListGetAt(list, i);
        if (obj->dataType == TYPE_INT)
        {
            printf("%d\t", *((int*)obj->value));
        }
    }
}

void TestBTree()
{
    /*BTree* tree = BTreeCreate();
    for (int i = 0; i < 8; i++)
    {
        tree->root = BTreeInsert(tree->root, &a[i], &compare);
    }
    tree->root = BTreeInsert(tree->root, &a[8], &compare);
    List* list = BTreeLevelOrderTraverse(tree->root);

    ListIter* listIter = ListIterator(list);
    while (ListIterHasNext(listIter))
    {
        BTreeNode* node = (BTreeNode*)ListNext(listIter)->value;
        for (int i = 0; i < node->keyNum; i++)
        {
            int* val = (int*)node->keys[i];
            printf("%d\t", *val);
        }
    }*/
}

void TestStack()
{
    Stack* stack = StackCreate();
    int a[] = { 10, 30, 50, 70, 90, 100, 110, 91, 92 };
    for (int i = 0; i < 9; i++)
    {
        Object* obj = ConvertObjectFromInt(&a[i]);
        PushStack(stack, obj);
    }

    Object tmp;
    for (int i = 0; i < 9; i++)
    {
        PopStack(stack, &tmp);
        printf("%d\t", ObjectIntValue(&tmp));
    }
}

void TestCString()
{
    char *p = "  hello, world";
    char *q = "ababaaababaa";

    struct timeval start, end;

    gettimeofday(&start, NULL);
    printf("%d\n", CStringKMPMatch(p, q));
    gettimeofday(&end, NULL);
    long duration;
    duration = (end.tv_usec - start.tv_usec);
    printf( "%ld seconds/n", duration );
    gettimeofday(&start, NULL);
    printf("%d\n", CStringViolentMatch(p, q));
    gettimeofday(&end, NULL);
    duration = (end.tv_usec - start.tv_usec) ;
    printf("====\n");
    printf( "%ld seconds/n", duration );
}

int main()
{
    int a[] = { 10, 30, 50, 70, 90, 100, 110, 91, 92 };
    HeapSort(a, 9);
    PrintArray(a, 9);
}

