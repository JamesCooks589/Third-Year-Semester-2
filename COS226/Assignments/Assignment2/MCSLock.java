import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;


public class MCSLock {
    private ThreadLocal<Node> myNode;
    private Queue<Node> queue;
    private volatile Node tail;

    public MCSLock() {
        myNode = ThreadLocal.withInitial(Node::new);
        queue = new ConcurrentLinkedQueue<>();
        tail = null;
    }

    public void lock() {
        Node node = myNode.get();
        Node pred = queue.peek();
        if (pred != null) {
            node.locked = true;
            pred.next = node;
            while (node.locked) {
                // Spin until it's our turn
            }
        } else {
            node.locked = false;
            if (queue.isEmpty()) {
                if (queue.offer(node)) {
                    while (node.locked) {
                        // Spin until it's our turn
                    }
                }
            }
        }
    }

    public void unlock() {
        Node node = myNode.get();
        if (queue.isEmpty() && !node.next.locked) {
            if (queue.isEmpty() && !node.next.locked) {
                myNode.set(null);
                return;
            }
        }
        node.locked = false;
        node.next = null;
    }

    private class Node {
        private volatile boolean locked = false;
        private volatile Node next = null;
    }
}
