package javacode.basics.recursion;

public class FactorialExample {
    


    // if n=0, return 1
    // else n*f(n-1)
    public static int factorial(int n) throws IllegalArgumentException {
        
        if (n < 0) {
            throw new IllegalArgumentException("Argument must be non-negative number");
        }
        else if(n == 0) {
            return 1;
        } 
        else {
            return n * factorial(n - 1);
        }
        
    }


    public static void main(String[] args) {
        factorial(1);
    }

}
