#include <iostream>

using namespace std;


void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    
}


int main()
{
    int x = 10;
    int y = 20;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swap(x, y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    return 0;
}
