#include <stdio.h>
#include <iostream>

using namespace std;

int left(int i) { return (2*i); }
int right(int i) { return (2*i+1); }

void Insert(int A[], int n)
{
    int i = n;
    int temp = A[i];

    while (i > 1 && temp < A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
    
}



void PrintLessThan(int A[], int index, int size, int target)
{
    // base
    // cout << "index:" << index << " size:" << size << "  target: " << target;
    if ( target < A[index] || index >= size) {
        // cout << "hit " << endl;
        return;
    }
    // print
    cout << A[index] << " ";
    // 
    PrintLessThan(A, left(index), size, target);
    PrintLessThan(A, right(index), size, target);    
}


void PrintHeap(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}





int main(int argc, char const *argv[])
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    Insert(H, 2);
    Insert(H, 3);
    Insert(H, 4);
    Insert(H, 5);
    Insert(H, 6);
    Insert(H, 7);
    Insert(H, 8);

    int size = sizeof(H) / sizeof(H[0]);
    PrintHeap(H, size);

    PrintLessThan(H, 1, size, 30);

    return 0;
}
