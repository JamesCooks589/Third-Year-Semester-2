public class Main {
    public static void main(String args[]){
        //Make 5 Nodes and a Printer
        Printer p = new Printer();
        Node n1 = new Node(p);
        Node n2 = new Node(p);
        Node n3 = new Node(p);
        Node n4 = new Node(p);
        Node n5 = new Node(p);

        //Start the Nodes
        n1.start();
        n2.start();
        n3.start();
        n4.start();
        n5.start();
    }
}
