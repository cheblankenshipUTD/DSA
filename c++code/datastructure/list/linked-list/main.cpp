#include <iostream>     // cout
#include <algorithm>    // max()


struct Node
{
    int data;
    struct Node* next;
    Node()
    {
        data = INT_MIN;
        next = NULL;
    }
    Node(int num, struct Node* nextNode = NULL)
    {
        data = num;
        next = nextNode;
    }
};


class LinkedList
{

private:
    struct Node* head = new Node();

public:
    LinkedList(){};
    ~LinkedList(){};


    struct Node* getHead()
    {
        return head;
    }

    int Count()
    {
        int count = 0;
        struct Node* hPtr = head;

        // case 1: Head is initialized but no data/ no linked list
        if (hPtr != NULL && (hPtr->data == INT_MIN && hPtr->next == NULL) )
            return count;
        
        // case 2: Link list exist and hits the tail (NULL value)
        while (hPtr != NULL)
        {
            count++;
            hPtr = hPtr->next;
        }
        
        return count;
    }


    // Display linked list
    void Display()
    {
        struct Node* hPtr = head;
        while (hPtr != NULL)
        {
            printf("%d ", hPtr->data);
            hPtr = hPtr->next;
        }
        printf("\n");
    }


    void DisplayRec(struct Node* p)
    {
        // Case 1: if head is initialized but not a linked list
        if (p != NULL && p->data == INT_MIN)
            return;
        
        // Case 2: check if node reached the tail
        if (p == NULL)
            return;
        
        printf("%d ", p->data);
        return DisplayRec(p->next);
    }

    // Create linked list from array
    void Create(int A[], int size)
    {
        struct Node* hPtr = head;
        struct Node* temp;
        struct Node* last;

        hPtr->data = A[0];
        hPtr->next = NULL;
        last = hPtr;

        // create link list
        for (int i = 1; i < size; i++)
        {
            temp = new Node();
            temp->data = A[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }

    }

    int Sum()
    {
        struct Node* hPtr = head;
        int sum = 0;

        // 1: Head declared but linked list not created
        if (hPtr != NULL && (hPtr->data == INT_MIN && hPtr->next == NULL))
            return 0;
        

        while (hPtr != NULL)
        {
            sum = sum + hPtr->data;
            hPtr = hPtr->next;
        }
        
        return sum;
    }


    int MaxNode()
    {
        struct Node* hPtr = head;
        int max = INT_MIN;
        if (Count() != 0)
        {
            while (hPtr != NULL)
            {
                max = std::max(max, hPtr->data);
                hPtr = hPtr->next;
            }
        }
        return max;
    }

    bool Search(int target)
    {
        struct Node* hPtr = head; 
        while (hPtr != NULL)
        {
            if (hPtr->data == target)
                return true;
            hPtr = hPtr->next;
        }
        return false;
    }


    // p: head pointer
    // data: new node data
    // position: insert to tail if position is not specified
    void Insert(int data, int position)
    {
        struct Node** pp = &head;
        struct Node* tail = NULL;
        struct Node* newNode = new Node(data);

        // Case 1: insert in head
        if (position <= 0)
        {
            newNode->next = *pp;
            *pp = newNode;
            return;
        }

        // Case 2: insert after nth node
        tail = *pp;
        for (int i = 1; i < position; i++)
        {
            if (tail->next == NULL)
            {
                printf("Out of range. Inserting to tail.\n");
                tail->next = newNode;
                return;
            }
            tail = tail->next;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void Delete(int target)
    {
        // get the head address as a reference
        struct Node** pp = &head;
        struct Node* current = *pp;
        struct Node* tail = new Node();

        // delete head node
        if (current->data == target)
        {
            *pp = current->next;
            free(current);
            return;
        }
        
        // iterate up to the node we want to delete
        while (current->next != NULL)
        {
            if (current->data == target)
            {
                tail->next = current->next;
                free(current);
                return;
            }
            // move tail ptr to current ptr node
            tail = current;
            // move current ptr to next ptr node
            current = current->next;
        }

        printf("Target not found.\n");
        
    }
};

// LinkedList::LinkedList(/* args */)
// {
// }

// LinkedList::~LinkedList()
// {
// }






int main(int argc, char const *argv[])
{
    int A[] = {3, 5, 4, 7, 99};

    LinkedList* ll = new LinkedList();
    
    // create
    ll->Create(A, sizeof(A)/sizeof(A[0]));

    // display
    ll->Display();
    ll->DisplayRec(ll->getHead());

    // count number of nodes
    printf("\n# of nodes: %d \n", ll->Count());

    // // sum of all node data
    printf("\nSum of all nodes: %d \n", ll->Sum());

    // // find max node
    printf("\nMax node: %d \n", ll->MaxNode());

    // // search key
    printf("\nDoes %d exist in the list?: %s \n", 99, ll->Search(99) ? "true" : "false");

    // insert 
    ll->Insert(100, 0);
    ll->Insert(54, 2);
    ll->Insert(32, 1000);
    ll->DisplayRec(ll->getHead());

    ll->Delete(100);
    printf("\n");
    ll->DisplayRec(ll->getHead());

    ll->Delete(4);
    printf("\n");
    ll->DisplayRec(ll->getHead());

    return 0;
}
