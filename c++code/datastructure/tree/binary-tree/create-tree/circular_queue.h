// circular_queue.h
#ifndef CIRCULAR_Q_H
#define CIRCULAR_Q_H

#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

#include "tree_node.h"


class CircularQueue
{
private:
    int front;
    int rear;
    int size;
    TreeNode** Q;
public:
    CircularQueue();
    CircularQueue(int size);
    ~CircularQueue();
    void enqueue(TreeNode** newData);
    TreeNode* dequeue();
    int circularIndex(int rawIndex);
    bool isEmpty();
    bool isFull();
    void display();
};

#endif