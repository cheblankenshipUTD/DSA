#include <iostream>
#include <chrono>
#include <cstdlib>  // for rand
#include "quickSort.h"

using namespace std;
using namespace std::chrono;


void Print(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void execute(int A[], int n) {
    // Print(A, n);
    auto start = high_resolution_clock::now();
    QuickSort(A, n);
    auto end = high_resolution_clock::now();
    // Print(A, n);
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Runtime: " << duration.count() << " nanoseconds" << endl;
}


int main() {
    
    int n;

    // Test case 0: 1000 array sorting random
    int G[150];
    for (int i = 0; i < 150; i++)
    {
        // to get a random number between [0-999]
        int num = rand() % 1000;
        num = (rand() % 1000) + 1; // or if you want [1-1000] instead:
        G[i] = num;
    }
    cout << "-- Test case 0: 150 array sorting random --" << endl;
    execute(G, 150);


    // Test case 1: Random and larger than 15
    int A[] = {11, 5, 14, 88, 6, 3, 54, 55, 60, 21, 46, 23, 35, 34, 57, 234, 4577, 257, 896, 215, 900, 456, 468, 823, 246, 567, 367, 456, 245, 900, 910, 911, 80, 53, 37, 45, 33, 29, 1};
    n = sizeof(A)/sizeof(A[0]);
    cout << "-- Test case 1: Random and larger than 15 --" << endl;
    execute(A, n);
    

    // Test case 2: Random and less than 15
    int B[] = {11, 5, 14, 88, 6, 3, 54, 55, 60, 21};
    n = sizeof(B)/sizeof(B[0]);
    cout << "-- Test case 2: Random and less than 15 --" << endl;
    execute(B, n);

    // Test case 3: Almost sorted and larger than 15
    int C[] = {2, 5, 8, 9, 4, 67, 88, 120, 132, 140, 143, 149, 151, 160, 163, 166, 164, 170, 199};
    n = sizeof(C)/sizeof(C[0]);
    cout << "-- Test case 3: Almost sorted and larger than 15 --" << endl;
    execute(C, n);

    // Test case 4: Almost sorted and larger than 15
    int D[] = {2, 5, 4, 9, 8, 67, 88, 132, 120, 140};
    n = sizeof(D)/sizeof(D[0]);
    cout << "-- Test case 4: Almost sorted and less than 15 --" << endl;
    execute(D, n);

    // Test case 5: 4 elements random order
    int E[] = {87, 3, 45, 7};
    n = sizeof(E)/sizeof(E[0]);
    cout << "-- Test case 5: 4 elements random order --" << endl;
    execute(E, n);

    return 0;
}