#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

#include "tree_node.h"

TreeNode::TreeNode()
{
    this->left = NULL;
    this->data = INT_MIN;
    this->right = NULL;
};

TreeNode::TreeNode(int data){
    this->left = NULL;
    this->data = data;
    this->right = NULL;
}