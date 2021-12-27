#include <iostream>
#include <stdio.h>

#include "treeNode.h"


#ifdef QUEUE_NODE_H
#define QUEUE_NODE_H


////////// QueueNode structure that holds data of TreeNode //////////
struct QueueNode
{
    TreeNode* data; // holds address of tree node
    struct QueueNode* next;

    QueueNode()
    {
        this->data = NULL;
        this->next = NULL;
    }
};

#endif