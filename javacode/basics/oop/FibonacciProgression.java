package javacode.basics.oop;

public class FibonacciProgression extends Progression {
    
    protected long prev;

    // Constructs traditional Fibonacci, starting 0, 1, 1, 2, 3, ...
    public FibonacciProgression() {
        this.prev = 0;
        this.current = 1;
    }

    // Constructs generalized Fibonacci with first and second values
    public FibonacciProgression(long first, long second) {
        super(first);
        this.prev = second - first;
    }

    protected void advance() {
        long temp = prev;
        prev = current;
        current += temp;
    }

}
