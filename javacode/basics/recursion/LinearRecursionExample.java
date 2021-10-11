package javacode.basics.recursion;

import javax.naming.spi.DirStateFactory.Result;

public class LinearRecursionExample {
    
    public static int linearSum(int[] data, int size) {
        if (size == 0) {
            return 0;
        } else {
            return linearSum(data, size-1) + data[size-1];
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,5,8};
        int result = linearSum(arr, 4);
        System.out.println("result: " + result);
    }



}
