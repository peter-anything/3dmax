// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include "BTree.h"

int compare(void * x, void* y)
{
    int* p1 = (int*)x;
    int* p2 = (int*)y;
    return *p1 > *p2;
}

int main()
{
    BTree* tree = BTreeCreate();
    int a[] = {10, 30, 50, 70, 90, 100, 110, 91, 92};

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
    }
}

