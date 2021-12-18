#include <iostream>



void treeRec(int n)
{
    if(n > 0)
    {
        printf("%d \n", n); // step 1
        treeRec(n-1);       // step 2
        treeRec(n-1);       // step 3
    }
}

int main(int argc, char const *argv[])
{
    treeRec(3);
    return 0;
}
