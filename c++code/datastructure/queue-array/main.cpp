#include <cstdio> // printf
#include <stdlib.h> //malloc


struct Queue
{
    int front;
    int rear;
    int size;
    int* Q;
    Queue(int size)
    {
        this->front = this->rear = -1;
        this->size = size;
        this->Q = (int*) malloc(this->size*sizeof(int));
    }
};


// insert data into queue
void enqueue(struct Queue*& q, int newData)
{
    q->rear++;
    q->Q[q->rear] = newData;
}


void dequeue(struct Queue*& q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;    
}


void display(struct Queue* q)
{
    if (q->rear != -1)
    {
        for (int i = q->front+1; i <= q->rear; i++)
        {
            printf("%d ", q->Q[i]);
        }   
        printf("\n");
        return;
    }
    printf("Queue is empty\n");
}




int main(int argc, char const *argv[])
{
    
    struct Queue* q;
    q = new struct Queue(5);

    display(q);
    enqueue(q, 99);
    display(q);
    enqueue(q, 6);
    display(q);
    enqueue(q, 2);
    display(q);
    dequeue(q);
    display(q);

    return 0;
}
