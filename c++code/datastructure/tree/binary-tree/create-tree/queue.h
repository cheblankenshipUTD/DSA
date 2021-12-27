#include <iostream>
#include <stdio.h>


#include "treeNode.h"
#include "queueNode.h"

#ifdef QUEUE_TREE_H
#define QUEUE_TREE_H

class Queue
{
public:
    QueueNode* front;
    QueueNode* rear;
    Queue();
    ~Queue();
    void enqueue(TreeNode* newNode);
    TreeNode* dequeue();
    bool isEmpty();
    void display();
};

#endif