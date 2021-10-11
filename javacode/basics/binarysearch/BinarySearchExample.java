package javacode.basics.binarysearch;

public class BinarySearchExample {
    

    //
    public static boolean binarySearch(int[] data, int target, int low, int high) {

        //
        if (low > high) {
            return false;  
        } 
        else {

            int mid = (low + high) / 2;

            if (target == data[mid]) {
                System.out.println("Found target value");
                return true;
            }
            else if(target < data[mid]) {
                return binarySearch(data, target, low, mid - 1);
            }
            else {
                return binarySearch(data, target, mid + 1, high);
            }
        }

    }


    public static void main(String[] args) {
        int[] arr = {1,5,8,9,22,45};
        binarySearch(arr, 30, 0, 5);
    }


}
