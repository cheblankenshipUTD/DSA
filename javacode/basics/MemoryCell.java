package javacode.basics;

public class MemoryCell{

    // Private variables
    private Object storedValue;

    // Public methods
    public Object read() {
        return storedValue;
    }

    public void write(Object x) {
        storedValue = x;
    }

}
