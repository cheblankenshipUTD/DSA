#include <iostream>
#include <stdio.h>

#include "treeNode.h"
#include "queueNode.h"

#ifdef BI_TREE_H
#define BI_TREE_H


////////// Tree to generate binary-tree. Holds TreeNodes. //////////
class Tree
{
public:
    TreeNode* root;

    Tree(/* args */);
    ~Tree();
    void createTree();
};

Tree::Tree()
{
}

Tree::~Tree()
{
    // free(this->root);
}

void Tree::createTree()
{
    // Declare / initialize a queue to hold the tree nodes
    Queue* q = new Queue();
    // Define necessary pointers for generating a tree
    TreeNode* p; // parent node
    TreeNode* t; // temporary node

    // define root node data
    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    this->root = new TreeNode();
    this->root->data = x;
    q->enqueue(root);

    // 
    while (!q->isEmpty())
    {
        // get the parent node from queue by dequeuing the front
        p = q->dequeue();
        q->display();

        // left child
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new TreeNode();
            t->data = x;
            p->left = t;
            // enqueue the node into the queue
            q->enqueue(t);
            q->display();
        }
        
        // right child
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new TreeNode();
            t->data = x;
            p->right = t;
            // enqueue the node into the queue
            q->enqueue(t);
            q->display();
        }
        //
    }
    
}


#endif