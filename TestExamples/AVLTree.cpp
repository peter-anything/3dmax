#include "AVLTree.h"
#include "Queue.h"
#include <malloc.h>
#include <stdio.h>

AVLTree* CreateAVLTree()
{
    AVLTree* tree = (AVLTree*) malloc(sizeof(AVLTree));
    if (tree == NULL)
    {
        printf("Init avl failed");
        return NULL;
    }

    tree->root = NULL;

    return tree;
}

AVLTreeNode* RRoate(AVLTreeNode* root)
{
    AVLTreeNode* avlNode = root->right;
    root->right = avlNode->left;
    avlNode->left = root;

    root->height = root->height - 1;
    return avlNode;
}

AVLTreeNode* LLRotate(AVLTreeNode* root)
{
    AVLTreeNode* avlNode = root->left;
    root->left = avlNode->right;
    avlNode->right = root;

    root->height = root->height - 1;
    return avlNode;
}

AVLTreeNode* RLRoate(AVLTreeNode* root)
{
    root->right = LLRotate(root->right);
    return RRoate(root);
}


AVLTreeNode* LRRotate(AVLTreeNode* root)
{
    root->left = RRoate(root->left);
    return LLRotate(root);
}

AVLTreeNode* Insert(AVLTreeNode* root, void * data)
{
    AVLTreeNode* newData = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));

    if (newData == NULL) {
        return NULL;
    }
    newData->left = newData->right = NULL;
    newData->data = data;
    newData->height = 0;

    bool isLeftInsert = false;
    bool isRightInsert = false;

    if (root == NULL)
    {
        root = newData;
    }
    else
    {
        if (data > root->data)
        {
            isRightInsert = true;
            root->right = Insert(root->right, data);
        }
        else
        {
            isLeftInsert = true;
            root->left = Insert(root->left, data);
        }
    }

    //R
    if (GET_HEIGHT(root->right) - GET_HEIGHT(root->left) == 2)
    {
        // RR
        if (isRightInsert && root->right != NULL)
        {
            if (data > root->right->data)
            {
                root = RRoate(root);
            }
            else
            {
                root = RLRoate(root);
            }
            
        }
    }
    else if (GET_HEIGHT(root->left) - GET_HEIGHT(root->right) == 2)
    {
        // RR
        if (isLeftInsert && root->left != NULL)
        {
            if (data < root->left->data)
            {
                root = LLRotate(root);
            }
            else 
            {
                root = LRRotate(root);
            }
        }
    }

    root->height = MAX(GET_HEIGHT(root->left), GET_HEIGHT(root->right)) + 1;
    return root;
}

List* LevelOrderTraverse(AVLTreeNode* root)
{
    Queue* queue = QueueCreate();
    List* list = ListCreate();
    QueueEn(queue, root);
    while (!QueueIsEmpty(queue))
    {
        AVLTreeNode* cur = (AVLTreeNode*) QueueDe(queue);
        ListAdd(list, cur->data);

        if (cur->left)
        {
            QueueEn(queue, cur->left);
        }
        
        if (cur->right)
        {
            QueueEn(queue, cur->right);
        }
    }

    return list;
}