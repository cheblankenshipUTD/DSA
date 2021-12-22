#include <cstdio> // printf


// 

class Stack
{
private:
    int size = 0;   // size of the array
    int top = -1;   // top element index
    int* s;         // pointer to dynamically allocated array
    

public:
    Stack();
    Stack(int size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int x);
    void pop();
    int peek(int position);

};


Stack::Stack(){}

Stack::Stack(int size)
{
    this->size = size;
    this->s = new int[size];
}

Stack::~Stack()
{
    delete this->s;
}

bool Stack::isEmpty()
{
    if (this->top == -1)
    {
        printf("Stack is empty.\n");
        return 1;
    }
    printf("Stack is not empty.\n");
    return 0;
}

bool Stack::isFull()
{
    if (this->top == this->size-1)
    {
        printf("Stack is full.\n");
        return 1;
    }
    else
    {
        printf("Stack is not full.\n");
        return 0;
    }
}

void Stack::push(int x)
{
    if (!isFull())
    {
        this->top++;
        this->s[this->top] = x;
    }
}


void Stack::pop()
{
    if (!isEmpty())
    {
        this->top--;
    }
}

int Stack::peek(int position)
{
    if (position <= this->size)
    {
        int index = this->top - position + 1;
        return this->s[index];   
    }
    printf("Invalid position.\n");
    return -1;
}



int main(int argc, char const *argv[])
{
    
    Stack* st = new Stack(5);

    st->isEmpty();
    st->isFull();
    st->push(99);
    st->push(3);
    st->push(5);
    st->push(1);
    st->push(66);

    // return element in position 3
    printf("peek: %d", st->peek(5));

    return 0;
}
