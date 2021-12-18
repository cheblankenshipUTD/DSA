#include <iostream>


struct Node
{
    int data;
    struct Node* next;
    Node()
    {
        data = INT_MIN;
        next = NULL;
    }
};


int Count(struct Node* p)
{
    int count = 0;

    // case 1: Head is initialized but no data/ no linked list
    if (p != NULL && (p->data == INT_MIN && p->next == NULL) )
        return 0;
    
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

    return 0;
}
