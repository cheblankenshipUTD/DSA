#ifndef MERGESORT_H
#define MERGESORT_H


void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high]; // same size of array A
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= high)
        B[k++] = A[j++];
    for (int i=low; i<=high; i++)
        A[i] = B[i];
}
 
void RecursiveMergeSort(int A[], int low, int high) {
    int mid;
    // Base case
    if (low < high)
    {
        // get the middle index
        mid = low + (high - low) / 2;
        // sort left side
        RecursiveMergeSort(A, low, mid);
        // sort right side
        RecursiveMergeSort(A, mid+1, high);
        // merge the sorted left and right array
        Merge(A, low, mid, high);
    }
}

#endif