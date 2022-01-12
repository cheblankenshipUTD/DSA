#include <limits.h> // INT_MIN
#include <stdlib.h> // malloc()
#include <stdio.h>  // printf()
#include <algorithm> // std::max()

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
    Node* Delete(Node* ptr, int key);
    int Height(Node* ptr);
    Node* InOrderPred(Node* ptr);
    Node* InOrderSucc(Node* ptr);
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
            printf("\nKey %d found.\n", key);
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
    
    printf("\nKey %d diesn't exist in BST\n", key);
    return NULL;
}


Node* BST::Delete(Node* ptr, int key)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    if (ptr->left == NULL and ptr->right == NULL)
    {
        return NULL;
    }
    
    
    if (ptr->data > key)
    {
        ptr->left = Delete(ptr->left, key);
    }
    else if (ptr->data < key)
    {
        ptr->right = Delete(ptr->right, key);
    }
    else
    {
        // check which sub tree has a larger height
        if (Height(ptr->left) > Height(ptr->right))
        {
            printf("checkkkk");
            // get the in-order predeccesor
            Node* pred = InOrderPred(ptr);
            // update the deleting node data attribute
            ptr->data = pred->data;
            printf("Check: %d", pred->data);
            // recursively call Delete() to remove the duplication
            ptr->left = Delete(ptr->left, pred->data);
        }
        else
        {
            printf("checkkkk2");
            // get the in-order successor
            Node* succ = InOrderSucc(ptr);
            // update the deleting node data attribute
            ptr->data = succ->data;
            printf("Check: %d", succ->data);
            // recursively call Delete() to remove the duplication
            ptr->right = Delete(ptr->right, succ->data);
        }
    }
    return ptr;
    
}


int BST::Height(Node* ptr)
{
    int l = 0;
    int r = 0;
    if (ptr != NULL)
    {
        l = Height(ptr->left);
        r = Height(ptr->right);
        return 1 + std::max(l, r);
    }
    return 0;
}

Node* BST::InOrderPred(Node* ptr)
{
    Node* temp = NULL;
    if (ptr != NULL)
    {
        temp = ptr;
        if (temp->left != NULL)
        {
            temp = temp->left;   
            while (temp != NULL and temp->right != NULL)
            {
                temp = temp->right;
            }
        }
    }
    return temp;
}

Node* BST::InOrderSucc(Node* ptr)
{
    Node* temp = NULL;
    if (ptr != NULL)
    {
        temp = ptr;
        if (temp->right != NULL)
        {
            temp = temp->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
        }
    }
    return temp;
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
    bst->InsertItr(17);

    // display nodes in-order
    bst->InOrderR(bst->getRoot());

    // search 
    bst->Search(13);

    // Delete node
    bst->Delete(bst->getRoot(), 13);


    bst->InOrderR(bst->getRoot());


    

    return 0;
}