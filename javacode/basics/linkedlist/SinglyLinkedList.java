package javacode.basics.linkedlist;

public class SinglyLinkedList<E> {
    
    // Nested Node class
    private static class Node<E> {
        private E element;
        private Node<E> next;
        public Node(E e, Node<E> n) {
            this.element = e;
            this.next = n;
        }
        public E getElement() { return this.element; }
        public Node<E> getNext() { return this.next; }
        public void setNext(Node<E> newNode) { this.next = newNode; }
    }

    //
    private Node<E> head = null;
    private Node<E> tail = null;
    private int size = 0;
    public SinglyLinkedList() {} // Construct an empty linked-list

    // getter
    public int getSize() { return this.size; }
    public boolean isEmpty() { return size == 0; }
    public E getHead() {
        if (isEmpty()) {
            return null;
        }
        return this.head.getElement();
    }
    public E getTail() {
        if (isEmpty()) {
            return null;
        }
        return this.tail.getElement();
    }

    // setter
    public void addFront(E e) {
        Node<E> newNode = new Node<>(e, this.head);
        this.head = newNode;
        if (isEmpty()) {
            this.tail = this.head;
        }
        size++;
    }
    public void addLast(E e) {
        Node<E> newNode = new Node<>(e, null);
        if (isEmpty()) {
            this.tail = this.head;
        }
        else {
            this.tail.setNext(newNode);
            this.tail = newNode;
        }
        size++;
    }

    public E removeFirst() {
        if (isEmpty()) return null;
        E removeE = head.getElement();
        head = head.getNext(); // move the head to the next node
        size--;
        if (size == 0) {
            return null;
        }
        return removeE;
    }

    public E removeLast() {
        if (isEmpty()) return null;
        if (this.head.getNext() == null) return null;
        E removeE = tail.getElement();
        Node<E> cur = this.head;
        while(cur.next != this.tail) {
            cur = cur.next;
        }
        this.tail = cur;
        cur.setNext(null);
        size--;
        return removeE;
    }


    public void printList() {
        Node<E> cur = this.head;
        while(cur != null) {
            System.out.print(cur.getElement() + " ");
            cur = cur.next;
        }
        System.out.println("");
    }


}
