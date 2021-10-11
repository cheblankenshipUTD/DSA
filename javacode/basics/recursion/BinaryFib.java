package javacode.basics.recursion;

public class BinaryFib {
    

    public static int recursiveFib(int k) {

        // if k == 0 or k == 1 or k < 0, return the value
        if(k <= 1) {
            return k;
        }
        return recursiveFib(k-1) + recursiveFib(k-2);
    }
}
