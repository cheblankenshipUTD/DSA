// tree_node.h
#ifndef TREE_NODE
#define TREE_NODE

#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

struct TreeNode
{
    TreeNode* left;
    int data;
    TreeNode* right;
    TreeNode();
    TreeNode(int data);
};

#endif