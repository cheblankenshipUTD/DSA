package javacode.basics.oop;

public class ArithmeticProgression extends Progression {
    
    protected long increment;

    // Start at zero and increment of 1
    public ArithmeticProgression() {
        this.increment = 1;
        this.current = 0;
    }

    // start at zero and increment of 
    public ArithmeticProgression(long stepSize) {
        this.increment = stepSize;
        this.current = 0;
    }

    //
    public ArithmeticProgression(long stepSize, long start) { 
        this.increment = stepSize; 
        this.current = start;
    }

    // adds the arithmetic increment the the current value
    protected void advance() {
        current = current + increment;
    }
    


}
