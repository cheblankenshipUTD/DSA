#include <iostream>
#include <stdio.h>


#ifdef TREE_NODE_H
#define TREE_NODE_H

////////// Tree node that holds integer data, left/right child. //////////
struct TreeNode
{
    TreeNode* left;
    int data;
    TreeNode* right;

    TreeNode()
    {
        this->left = NULL;
        this->data = INT_MIN; // minimum integer
        this->right = NULL;
    }
    TreeNode(int data)
    {
        this->left = NULL;
        this->data = data;
        this->right = NULL;
    }
};

#endif