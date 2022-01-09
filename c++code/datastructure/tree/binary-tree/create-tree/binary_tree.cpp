#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()
#include <stack>    // stack stl
#include <queue>    // Q used for level order traversal
#include <algorithm>// max()

#include "tree_node.h"
#include "circular_queue.h"
#include "binary_tree.h"


BinaryTree::BinaryTree()
{
    this->root = NULL;
}

BinaryTree::~BinaryTree()
{
    delete this->root;
}

void BinaryTree::createTree()
{
    // Declare variables
    TreeNode* p;    // node to point to a deququed tree node.
    TreeNode* t;    // temporary node to create l/r child nodes for p
    int x = INT_MIN;// temp int variable to hold user input
    
    // Create queue that holds TreeNode address as pointers
    CircularQueue* q;
    q = new CircularQueue(200); // hold 200 type TreeNode elements

    // Setup root data and store root pointer into queue
    printf("Enter value for root: ");
    scanf("%d", &x); // store input into temp x
    t = new TreeNode(x);
    this->root = t;
    q->enqueue(&this->root);

    // loop: continue until queue is empty
    while (!(q->isEmpty()))
    {
        p = q->dequeue();
        printf("Check current pointing node:\n");
        printf("Left    : %p\n", (void*)&p->left);
        printf("data    : %d\n", p->data);
        printf("Right   : %p\n", (void*)&p->right);
        // check if p is leaf node
        if (p->data != INT_MIN && p->left == NULL && p->right == NULL)
        {
            // left
            printf("Enter left child value for %d: ", p->data);
            scanf("%d", &x); // store input into temp x
            if (x != -1)
            {
                t = new TreeNode(x);
                p->left = t;
                q->enqueue(&t);
            }
            // right
            printf("Enter right child value for %d: ", p->data);
            scanf("%d", &x); // store input into temp x
            if (x != -1)
            {
                t = new TreeNode(x);
                p->right = t;
                q->enqueue(&t);
            }
        }
    }
    
}

TreeNode* BinaryTree::getRoot()
{
    return this->root;
};

void BinaryTree::Inorder(TreeNode* p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        if (p->data != INT_MIN) printf("%d ", p->data);
        Inorder(p->right);
    }
};

void BinaryTree::Preorder(TreeNode* p)
{
    if (p != NULL)
    {
        if (p->data != INT_MIN) printf("%d ", p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}

void BinaryTree::Postorder(TreeNode* p)
{
    if (p != NULL)
    {
        Preorder(p->left);
        Preorder(p->right);
        if (p->data != INT_MIN) printf("%d ", p->data);
    }
}

void BinaryTree::PreorderItr()
{
    printf("Preorder (iterative): ");
    TreeNode* ptr = this->root;
    std::stack<TreeNode*> stk;
    stk.push(ptr);

    while (!stk.empty())
    {
        ptr = stk.top();
        stk.pop();
        printf("%d ", ptr->data);
        if (ptr->right != NULL)
        {
            stk.push(ptr->right);   
        }
        if (ptr->left != NULL)
        {
            stk.push(ptr->left);   
        }
    }
    printf("\n");
}


void BinaryTree::InorderItr()
{
    printf("Inorder (iterative): ");
    TreeNode* ptr = this->root;
    std::stack<TreeNode*> stk;
    // stk.push(ptr);

    while ( !(stk.empty()) or ptr != NULL )
    {
        if (ptr == NULL)
        {
            ptr = stk.top();
            stk.pop();
            printf(" %d", ptr->data);
            ptr = ptr->right;
        }
        else {
            stk.push(ptr);
            ptr = ptr->left;
        }
    }

    printf("\n");
}


void BinaryTree::LevelOrderTraveral()
{
    printf("Level order: ");
    TreeNode* ptr = NULL;
    std::queue<TreeNode*> q;
    q.push(this->root);

    while (ptr != NULL || !(q.empty()))
    {
        ptr = q.front();
        q.pop();
        if (ptr != NULL)
        {
            printf("%d ", ptr->data);
            q.push(ptr->left);
            q.push(ptr->right);
        }
    }
    printf("\n");
}


int BinaryTree::CountNode(TreeNode* p = NULL)
{
    if (p != NULL)
    {
        // 1. Count the number of nodes in left child
        int l = CountNode(p->left);
        // 2. Count the number of nodes in right child
        int r = CountNode(p->right);
        // 3. return the total number of nodes
        return 1 + l + r;
    }
    return 0;
}


int BinaryTree::Height(TreeNode* p = NULL)
{
    int l = 0;
    int r = 0;
    if (p != NULL)
    {
        l = Height(p->left);
        r = Height(p->right);
        return 1 + std::max(l, r);
    }
    return 0;
}