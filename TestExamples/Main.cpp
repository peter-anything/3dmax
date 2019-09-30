// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include "AVLTree.h"

int main()
{
    AVLTree* tree = CreateAVLTree();
    int a[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        tree->root = Insert(tree->root, &a[i]);
    }
    
    List* list = LevelOrderTraverse(tree->root);
}

