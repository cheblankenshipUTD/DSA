#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

#include "tree_node.h"
#include "circular_queue.h"


CircularQueue::CircularQueue()
{
    this->front = 0;
    this->rear = 0;
}

CircularQueue::CircularQueue(int size)
{
    this->front = 0;
    this->rear = 0;
    this->size = size;
    this->Q = (TreeNode**)malloc(size * sizeof(TreeNode));
}

CircularQueue::~CircularQueue()
{
    free(this->Q);
}

void CircularQueue::enqueue(TreeNode** newData)
{   
    // printf("Enqueue ");
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    this->rear = (this->rear + 1) % this->size;
    this->Q[this->rear] = *newData;
    display();
}

TreeNode* CircularQueue::dequeue()
{
    // printf("Dequeue ");
    TreeNode* x = NULL;
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return x; // return -1 if dequeue did not happen
    }
    else
    {
        this->front = circularIndex(this->front);
        x = &(*this->Q[this->front]);
    }
    return x;
}

int CircularQueue::circularIndex(int rawIndex)
{
    return (rawIndex + 1) % this->size;
}

bool CircularQueue::isEmpty()
{
    if (this->front == this->rear)
    {
        return true;
    }
    return false;
}

bool CircularQueue::isFull()
{
    if ((this->rear + 1) % this->size == this->front)
    {
        return true;
    }
    return false;
}

void CircularQueue::display()
{
    printf("\nDisplay Queue: ");
    if (isEmpty())
        return;
    
    int index = (this->front + 1) % this->size;
    do
    {
        printf("%p ", (void*)&this->Q[index]);
        index = (index + 1) % this->size;
    } while (index != (this->rear + 1) % this->size);
    printf("\n");
}

