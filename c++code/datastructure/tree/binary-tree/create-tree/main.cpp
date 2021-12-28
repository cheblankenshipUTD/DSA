#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

#include "tree_node.h"
#include "circular_queue.h"
#include "binary_tree.h"


int main(int argc, char const *argv[])
{

    // CircularQueue* cq = new CircularQueue(5);

    BinaryTree* bt;
    bt = new BinaryTree();

    bt->createTree();

    printf("Display in-order\n");
    bt->Inorder(bt->getRoot());

    return 0;
}