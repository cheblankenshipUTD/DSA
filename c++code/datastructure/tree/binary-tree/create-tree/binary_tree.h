// binary_tree.h
#ifndef BINARY_TREE
#define BINARY_TREE

#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()
#include <stack>    // stack library  

#include "tree_node.h"


class BinaryTree
{
private:
    TreeNode* root;
public:
    BinaryTree();
    ~BinaryTree();
    void createTree();
    TreeNode* getRoot();
    void Inorder(TreeNode* p);
    void Preorder(TreeNode* p);
    void Postorder(TreeNode* p);
    void PreorderItr();
    void InorderItr();
    void LevelOrderTraveral();
};

#endif