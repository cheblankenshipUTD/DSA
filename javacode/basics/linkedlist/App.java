package javacode.basics.linkedlist;

public class App {


    public static void main(String[] args) {
        
        SinglyLinkedList<Integer> sl = new SinglyLinkedList<>();

        sl.addFront(5);
        sl.addFront(4);
        sl.addFront(3);
        sl.addFront(2);
        sl.addFront(1);

        sl.printList();

        sl.removeLast();

        sl.printList();

        // sl.getTail();

        // sl.printList();


    }
    
}
