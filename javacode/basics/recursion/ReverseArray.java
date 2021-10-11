package javacode.basics.recursion;

import javax.naming.spi.DirStateFactory.Result;

public class ReverseArray {

    public static int[] reverseArr(int[] arr, int i, int j) {
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            return reverseArr(arr, i, j);
        }
        else {
            return arr;
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int[] re = reverseArr(arr, 0, 4);
        
        for (int elm : re) {
            System.out.print(elm);
            System.out.print(" ");
        }
        System.out.println();
    }
    
}
