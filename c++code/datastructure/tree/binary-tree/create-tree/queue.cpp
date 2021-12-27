#include <iostream>
#include <stdio.h>

#include "queue.h"


Queue::Queue()
{
    this->front = this->rear = NULL;
}

Queue::~Queue()
{
    // no memory allocation 
}

void Queue::enqueue(TreeNode* newNode)
{
    struct QueueNode* newQNode;
    newQNode->data = newNode;
    if (newQNode == NULL)
    {
        printf("Heap is full\n");
        return;
    }
    if (this->front == NULL)
    {
        printf("Queue is empty. Inserting new node.\n");
        this->front = this->rear = newQNode;
    }
    else
    {
        this->rear->next = newQNode;
        this->rear = newQNode;
    }
}

TreeNode* Queue::dequeue()
{
    TreeNode* x = NULL;
    if (this->front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        x = this->front->data;
        QueueNode* t = this->front;
        this->front = this->front->next;
        free(t);
    }
    return x;
}

bool Queue::isEmpty()
{
    if (this->front == NULL)
    {
        return true;
    }
    return false;
}

void Queue::display()
{
    struct QueueNode* elm;
    elm = front;
    while (elm != NULL)
    {
        printf("%d ", elm->data->data);
        elm = elm->next;
    }
    printf("\n");
};