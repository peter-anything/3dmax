// Tree.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <stdio.h>
#include "AVLTree.h"

#include "Queue.h"
#include "List.h"

int main()
{
    AVLTree* tree = CreateAVLTree();
    int a[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        tree->root = Insert(tree->root, &a[i]);
    }
    
    List* list = LevelOrderTraverse(tree->root);
    
    ListIter *listIter = ListIterator(list);
    while (ListIterHasNext(listIter))
    {
        int value = *((int*)ListNext(listIter)->value);
        printf("%d\t", value);
    }


}

