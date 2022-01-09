#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        this->left = NULL;
        this->right = NULL;
    }
    Node(int key){
        this->data = key;
        this->left = NULL;
        this->right = NULL;
    }

};


class BST
{
private:
    Node* root;
public:
    BST(/* args */);
    ~BST();
    Node* getRoot();
    void InsertItr(int key);
    Node* InsertR(Node* ptr, int key);
};

BST::BST()
{
    this->root = NULL;
}

BST::~BST()
{
}

Node* BST::getRoot()
{
    return this->root;
}

// Insert key iterative approach
void BST::InsertItr(int key)
{
    Node* t = NULL;
    Node* ptr = this->root;

    // Iterate down to leaf node
    while (ptr != NULL)
    {
        t = ptr;
        if (key == ptr->data)
        {
            printf("Key found in BST\n");
            return;
        }
        else if (key < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }        
    }

    // Create new node
    Node* newNode = new Node(key);

    // 
    if (key < t->data)
    {
        t->left = newNode;
    }
    else
    {
        t->right = newNode;
    }

}

// Insert new data recursive
Node* BST::InsertR(Node* ptr, int key)
{

}



int main(int argc, char const *argv[])
{

    return 0;
}