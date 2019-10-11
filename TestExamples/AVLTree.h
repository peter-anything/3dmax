#ifndef _AVLTree_H_
#define _AVLTree_H_

#include "List.h"

#define MAX(a, b) (a > b ? a : b)
#define GET_HEIGHT(T) (T == NULL ? 0 : T->height)


typedef struct AVLTreeNode {
    void * data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} AVLTreeNode;

typedef struct AVLTree {
    struct AVLTreeNode* root;
} AVLTree;

AVLTree* CreateAVLTree();

AVLTreeNode* Insert(AVLTreeNode* root, void* data, int (*compare)(void *data1, void* data2));

List* LevelOrderTraverse(AVLTreeNode* root);
#endif // !_SEARCHTREE_H_