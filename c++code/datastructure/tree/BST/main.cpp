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
    BST();
    ~BST();
    Node* getRoot();
    void InsertItr(int key);
    Node* InsertR(Node* ptr, int key);
    void InOrderR(Node* ptr);
    Node* Search(int key);
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

    // Check if root is null
    if (this->root == NULL)
    {
        this->root = new Node(key);
        return;
    }

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
    // If root is emoty or hits leaf node
    if (ptr == NULL)
    {
        return new Node(key);
    }

    // Call insert recursivly left or right
    if (ptr->data > key)
    {
        ptr->left = InsertR(ptr->left, key);
    }
    else if(ptr->data < key)
    {
        ptr->right = InsertR(ptr->right, key);
    }
    else
    {
        return ptr;
    }
    
    return NULL;
}


void BST::InOrderR(Node* ptr)
{
    if (ptr != NULL)
    {
        // Call left
        InOrderR(ptr->left);
        // display node data
        printf("%d ", ptr->data);
        // Call right
        InOrderR(ptr->right);
    }
}

Node* BST::Search(int key)
{
    Node* ptr = this->root;

    while (ptr != NULL)
    {
        // Check if key data exist in the tree
        if (ptr->data == key)
        {
            return ptr;
        }

        // Checkif key is smaller or larger
        if (ptr->data > key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    
    return NULL;
}


int main(int argc, char const *argv[])
{

    // Declare BST object
    BST* bst;
    bst = new BST();

    // Insert first node into bst
    bst->InsertItr(10);
    bst->InsertItr(5);
    bst->InsertItr(15);
    bst->InsertItr(13);

    // display nodes in-order
    bst->InOrderR(bst->getRoot());

    // search 
    if (bst->Search(11) != NULL)
    {
        printf("\nKey 11 exists in tree\n");
    }
    else
    {
        printf("\nKey 11 does not exists in tree\n");
    }
    

    return 0;
}