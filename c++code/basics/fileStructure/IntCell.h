#ifndef IntCell_H
#define IntCell_H

// Class interface 

class IntCell {
private:
    int storedValue;
public:
    explicit IntCell( int initialValue = 0);
    int read() const;
    void write(int x);
};

