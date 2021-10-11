package javacode.basics.recursion;

public class RecursiveSquaring {
    
    // base^n
    public static int powRec(int base, int n) {
        if (n == 0) {
            return 1;
        }
        else if(n % 2 != 0) { // odd
            return powRec(base, (n-1)/2);
        }
        else { // even
            return powRec(base, n/2);
        }
    }

    public static void main(String[] args) {
        int re = powRec(2, 5);
        System.out.println("Result: " + re);
    }

}
