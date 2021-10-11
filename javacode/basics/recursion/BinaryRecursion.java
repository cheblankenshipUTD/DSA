package javacode.basics.recursion;

public class BinaryRecursion {
    

    // arr  : array of integers
    // i    : index 
    // n    : size
    public static int binarySum(int[] arr, int i, int n) {
        if (n == 1) {
            return arr[i];
        }
        return binarySum(arr, i, n/2) + binarySum(arr, i+(n/2), n/2);
    }
}
