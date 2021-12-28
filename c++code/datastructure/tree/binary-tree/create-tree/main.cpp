#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()


#include "circular_queue.h"


int main(int argc, char const *argv[])
{

    CircularQueue* cq = new CircularQueue(5);

    //
    cq->enqueue(4);
    cq->enqueue(2);
    cq->enqueue(3);
    cq->enqueue(8);
    cq->enqueue(0);
    
    cq->dequeue();
    cq->dequeue();
    cq->dequeue();
    cq->dequeue();
    cq->dequeue();



    return 0;
}