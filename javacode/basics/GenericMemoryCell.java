package basics;

import java.util.*;

public class GenericMemoryCell<AnyType> {
    
    private AnyType storedValue;

    public AnyType read() {
        return storedValue;
    }

    public void write(AnyType x) {
        storedValue = x;
    }

    public interface Comparable<AnyType> {
        public int compareTo(AnyType other);
    }

}

