#include "static_global_recursion.h"


int statGlobRec(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return statGlobRec(n-1) + x;
    }
    return 0;
};