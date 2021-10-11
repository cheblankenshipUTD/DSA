package javacode.basics.oop;

class Progression {

    // instance variable
    protected long current;

    // Constructor starting at zero
    public Progression() { this(0); }

    // Constructor starting with given value
    public Progression(long start) { this.current = start; }

    // Return the next value of the progression
    public long nextValue() {
        long ans = this.current;
        advance();
        return ans;
    }

    // advances the current value to the next value of the progression
    protected void advance() {
        this.current++;
    }

    // Prints the next n values of the progression
    public void printProgression(int n) {
        System.out.print(nextValue());
        for (int j = 1; j < n; j++) {
            System.out.print(" " + nextValue());
        }
        System.out.println();
    }


}

