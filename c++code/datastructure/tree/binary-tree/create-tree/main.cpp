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

    printf("Display in-order: ");
    bt->Inorder(bt->getRoot());
    printf("\n");

    printf("Display pre-order: ");
    bt->Preorder(bt->getRoot());
    printf("\n");

    printf("Display post-order: ");
    bt->Postorder(bt->getRoot());
    printf("\n");

    bt->PreorderItr();

    bt->InorderItr();

    return 0;
}