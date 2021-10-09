#include "IntCell.h"


// Class implementation

// Construct the IntCell
IntCell::IntCell(int initialValue) : storedValue{ initialValue } {};

// Return the stored value
int IntCell::read() const {
    return storedValue;
}

// Store x to storedValue
void IntCell::write(int x) {
    storedValue = x;
}