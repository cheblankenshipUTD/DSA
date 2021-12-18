#ifndef QUICKSORT_H
#define QUICKSORT_H


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        int j = i-1;
        int x = A[i];
        while (j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}


void QuickSort(int A[], int low, int high)
{
    int cutOff = 15;
    if (low + cutOff > high)
    {
        InsertionSort(A, high);
    }
    else
    {
        int mid = low + (high - low) / 2;
        if (A[mid] < A[low])
        {
            swap(&A[mid], &A[low]);
        }
        if (A[high] < A[low])
        {
            swap(&A[high], &A[low]);
        }
        if (A[high] < A[mid])
        {
            swap(&A[high], &A[mid]);
        }
        
        swap(&A[mid], &A[high-1]);
        int pivot = A[high-1];
        int i, j;
        for (i = low, j = high -1;;)
        {
            while (A[i] < pivot)
                i++;
            while (pivot < A[j])
                j--;
            if (i >= j)
                break;
            swap(&A[i], &A[j]);
        }
        swap(&A[i], &A[high-1]);
        QuickSort(A, low, i - 1);
        QuickSort(A, i + 1, high);
    }
    
}


void QuickSort(int A[], int n)
{
    QuickSort(A, 0, n-1);
} 


#endif