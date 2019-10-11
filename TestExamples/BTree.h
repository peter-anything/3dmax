#ifndef __BTREE_H__
#define __BTREE_H__

#define M 2
#define KEY_NUM (2 * M - 1)

#include "Queue.h"

typedef struct BTreeNode
{
    int keyNum;
    int leaf;
    void* keys[KEY_NUM];
    int testKeys[KEY_NUM];
    struct BTreeNode* children[KEY_NUM + 1];
} BTreeNode;

typedef struct BTree {
    struct BTreeNode* root;
    int size;
} BTree;

BTree* BTreeCreate();
BTreeNode* BTreeInsert(BTreeNode* root, void * data, int (*compare)(void*, void*));
BTreeNode* BTreeInsertNotFull(BTreeNode* node, void* key, int (*compare)(void*, void*));
BTreeNode* BTreeSplitChildren(BTreeNode* parent, int pos, BTreeNode* child);
List* BTreeLevelOrderTraverse(BTreeNode* root);
#endif
