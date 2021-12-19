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


int Count(struct Node* p)
{
    int count = 0;

    // case 1: Head is initialized but no data/ no linked list
    if (p != NULL && (p->data == INT_MIN && p->next == NULL) )
        return count;
    
    // case 2: Link list exist and hits the tail (NULL value)
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    
    return count;
}


// Display linked list
void Display(struct Node* p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
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
void Create(int A[], int size, struct Node* head)
{
    struct Node* temp;
    struct Node* last;

    head->data = A[0];
    head->next = NULL;
    last = head;

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

int Sum(struct Node* p)
{
    int sum = 0;

    // 1: Head declared but linked list not created
    if (p != NULL && (p->data == INT_MIN && p->next == NULL))
        return 0;
    

    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    
    return sum;
}


int MaxNode(struct Node* p)
{
    int max = INT_MIN;
    if (Count(p) != 0)
    {
        while (p != NULL)
        {
            max = std::max(max, p->data);
            p = p->next;
        }
    }
    return max;
}

bool Search(struct Node* p, int target)
{
    while (p != NULL)
    {
        if (p->data == target)
            return true;
        p = p->next;
    }
    return false;
}


// p: head pointer
// data: new node data
// position: insert to tail if position is not specified
void Insert(struct Node** p, int data, int position)
{
    struct Node* tail = NULL;
    struct Node* newNode = new Node(data);

    // Case 1: insert in head
    if (position == 0 || position == INT_MIN)
    {
        newNode->next = *p;
        *p = newNode;
        return;
    }

    // Case 2: insert after nth node
    tail = *p;
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

void Delete(struct Node** head, int target)
{
    // get the head address as a reference
    struct Node* current = *head;
    struct Node* tail = new Node();

    // delete head node
    if (current->data == target)
    {
        *head = current->next;
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


int main(int argc, char const *argv[])
{
    int A[] = {3, 5, 4, 7, 99};
    struct Node* head = new Node();

    // create
    Create(A, sizeof(A)/sizeof(A[0]), head);

    // display
    DisplayRec(head);

    // count number of nodes
    printf("\n# of nodes: %d \n", Count(head));

    // sum of all node data
    printf("\nSum of all nodes: %d \n", Sum(head));

    // find max node
    printf("\nMax node: %d \n", MaxNode(head));

    // search key
    printf("\nDoes %d exist in the list?: %s \n", 99, Search(head, 99) ? "true" : "false");

    // insert 
    Insert(&head, 100, 0);
    Insert(&head, 54, 2);
    Insert(&head, 32, 1000);
    DisplayRec(head);

    Delete(&head, 100);
    printf("\n");
    DisplayRec(head);

    Delete(&head, 4);
    printf("\n");
    DisplayRec(head);

    return 0;
}
