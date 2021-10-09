#include <iostream>
#include "IntCell.h"


int main(int argc, char const *argv[])
{
    
    IntCell m;
    m.write(5);
    std::cout << "Cell contents: " << m.read() << std::endl;

    return 0;
}
