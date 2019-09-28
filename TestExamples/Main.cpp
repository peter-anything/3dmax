// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include "List.h"

int main()
{
    List* list = ListCreate();

    int a[] = {24, 13, 53, 37, 90, 48};
    
    for (int i =0; i < 6; i++)
    {
        ListAdd(list, &a[i]);
    }

    ListNode* node =

    ListIter* listIter = ListIterator(list);

    while (ListIterHasNext(listIter))
    {
        ListNode* node = ListNext(listIter);
        int* value = (int*)node->value;
        printf("%d\t", *value);
    }
}

