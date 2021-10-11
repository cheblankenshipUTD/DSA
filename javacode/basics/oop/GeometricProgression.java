package javacode.basics.oop;

public class GeometricProgression extends Progression {
    
    protected long base;

    // default constructor
    public GeometricProgression() {
        this.base = 2;
        this.current = 1;
    }

    //
    public GeometricProgression(long b) {
        this.base = b;
        this.current = 1;
    }

    //
    public GeometricProgression(long b, long start) {
        this.base = b;
        this.current = start;
    }

    // 
    protected void advance() {
        this.current = this.current * base;
    }

    


}
