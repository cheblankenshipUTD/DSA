#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

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
    this->Q = (int*)malloc(size * sizeof(int));
}

CircularQueue::~CircularQueue()
{
    free(this->Q);
}

void CircularQueue::enqueue(int newData)
{   
    printf("Enqueue ");
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    this->rear = (this->rear + 1) % this->size;
    this->Q[this->rear] = newData;
    display();
}

int CircularQueue::dequeue()
{
    printf("Dequeue ");
    int x = INT_MIN;
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return x; // return -1 if dequeue did not happen
    }
    else
    {
        this->front = circularIndex(this->front);
        x = this->Q[this->front];
        display();
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
    if (isEmpty())
        return;
    
    // 
    int index = (this->front + 1) % this->size;
    do
    {
        printf("%d ", this->Q[index]);
        index = (index + 1) % this->size;
    } while (index != (this->rear + 1) % this->size);
    printf("\n");
}

