#ifndef _SEARCHTREE_H_
#define _SEARCHTREE_H_
#endif // !_SEARCHTREE_H_

#define MAX(a, b) (a > b ? a : b)
#define GET_HEIGHT(T) (T == NULL ? 0 : T->height)

typedef int AVLTreeElementType;

typedef struct AVLTreeNode {
    AVLTreeElementType data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} AVLTreeNode;

typedef struct AVLTree {
    struct AVLTreeNode* root;
} AVLTree;

AVLTree* CreateAVLTree();

int GetBalance(AVLTree* tree);

AVLTreeNode* Insert(AVLTreeNode* tree, AVLTreeElementType data);

void InOrderTraverse(AVLTree* tree);

void PreOrderTraverse(AVLTree* tree);

void PostOrderTraverse(AVLTree* tree);

void LevelOrderTraverse(AVLTree* tree);