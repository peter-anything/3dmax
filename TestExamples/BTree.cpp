#include "BTree.h"
#include <stdio.h>
#include <malloc.h>

BTree* BTreeCreate()
{
    BTree* tree = (BTree*)malloc(sizeof(BTree));
    if (tree == NULL)
    {
        return NULL;
    }

    tree->root = NULL;
    tree->size = 0;

    return tree;
}

BTreeNode* BTreeNodeCreate()
{
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (node == NULL)
    {
        return NULL;
    }
    node->keyNum = 0;
    node->leaf = 1;
    for (int i = 0; i < KEY_NUM + 1; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

BTreeNode* BTreeInsert(BTreeNode* root, void* key, int (*compare)(void*, void*))
{

    if (root == NULL)
    {
        root = BTreeNodeCreate();
    }
    root = BTreeInsertNotFull(root, key, compare);
    if (root->keyNum == KEY_NUM)
    {
        BTreeNode* newData = BTreeNodeCreate();
        newData->children[0] = root;
        newData->leaf = 0;

        root = BTreeSplitChildren(newData, 0, root);
    }

    return root;
}

BTreeNode* BTreeInsertNotFull(BTreeNode* node, void* key, int (*compare)(void*, void*))
{
    int i = node->keyNum - 1;

    if (node->leaf == 1)
    {
        while (i >= 0 && compare(key, node->keys[i]) == 0)
        {
            node->keys[i + 1] = node->keys[i];
            node->testKeys[i + 1] = node->testKeys[i];
            --i;
        }

        node->keys[i + 1] = key;
        node->testKeys[i + 1] = *((int *)key);
        node->keyNum++;
    }
    else
    {
        while (i >= 0 && compare(key, node->keys[i]) == 0)
        {
            --i;
        }
        ++i;
        if (node->children[i]->keyNum == KEY_NUM)
        {
            BTreeSplitChildren(node, i, node->children[i]);
            if (compare(key, node->keys[i]) == 1)
            {
                ++i;
            }
        }
        BTreeInsertNotFull(node->children[i], key, compare);
        if (node->children[i]->keyNum == KEY_NUM)
        {
            BTreeSplitChildren(node, i, node->children[i]);
        }
    }
    return node;
}

BTreeNode* BTreeSplitChildren(BTreeNode* parent, int pos, BTreeNode* child)
{
    BTreeNode* newChild = BTreeNodeCreate();
    newChild->leaf = child->leaf;
    newChild->keyNum = M - 1;

    for (int i =0; i < M-1; i++)
    {
        newChild->keys[i] = child->keys[i+M];
        newChild->testKeys[i] = child->testKeys[i + M];
    }
    child->keyNum = M - 1;
    if (child->leaf == 0)
    {
        for (int i =0; i< M; i++)
        {
            newChild->children[i] = child->children[i+M];
        }
    }
    for (int i = parent->keyNum; i > pos; --i)
    {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[pos + 1] = newChild;
    for (int i = parent->keyNum - 1; i >= pos; --i)
    {
        parent->keys[i + 1] = parent->keys[i];
        parent->testKeys[i + 1] = parent->testKeys[i];
    }
    parent->keys[pos] = child->keys[M-1];
    parent->testKeys[pos] = child->testKeys[M - 1];
    parent->keyNum++;
    return parent;
}

List* BTreeLevelOrderTraverse(BTreeNode* root)
{
    Queue* queue = QueueCreate();
    List* list = ListCreate();
    QueueEn(queue, root);
    while (!QueueIsEmpty(queue))
    {
        BTreeNode* cur = (BTreeNode*)QueueDe(queue);
        ListAdd(list, cur);

        if (cur->leaf == 1)
        {
            continue;
        }
        for (int i = 0; i < cur->keyNum + 1; i++)
        {
            QueueEn(queue, cur->children[i]);

        }
    }

    return list;
}