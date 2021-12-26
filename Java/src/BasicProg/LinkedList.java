package BasicProg;

public class LinkedList <T> {
    private class Node {
        T item;
        Node next;
        Node back;

        /**constructor for the objects */
        Node(T t){
            item = t;
            next = null;
            back = null;
        }
    }    
    Node head = null, tail = null;
    public void addNode(T item) {
        Node newNode = new Node(item);
        if (head == null) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail.next = newNode;
            newNode.back = tail;
            tail = newNode;
        }
    }

    /**Removes a node from the linked list 
     * Returns true if object deleted;
    */
    public boolean delNode(T item) {
        Node node = head;
        while (node != null) {
            if(node.item == item) {
                // Node with the item has been found
                node.next.back = node.back;
                node.back.next = node.next;
                if (head == tail) {
                    head = null;
                    tail = null;
                }
                System.out.println("Deleting item: " + item);
                return true;
            }
            node = node.next;
        }
        return false;
    }

    /**Returns true if the Linked List contains the item */
    public boolean findNode(T item) {
        Node node = head;
        while (node != null){
            if (node.item == item){
                return true;
            }
            node = node.next;
        }
        return false;
    }

    /**Prints out the contents of the list */
    public String display() {
        String myStr = "";
        Node node = head;
        while(node != null){
            System.out.print(node.item + " ");
            myStr += node.item + " ";
            node = node.next;
        }
        System.out.println();
        return myStr;
    }

    @Override
    public String toString() {
        // displays the entire content of the string
        return(display());
    }

    public static void main(String[] args) {
        // Checks the implementation of the linked list
        LinkedList<Integer> myList = new LinkedList<>();
        // add a couple of elements
        myList.addNode(1);
        myList.addNode(2);
        myList.addNode(3);
        myList.addNode(3);
        myList.display();
        myList.delNode(2);
        myList.display();
    }
}
