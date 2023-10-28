import java.util.concurrent.atomic.AtomicReference;

public class LockFreeQueue<T> {
    //Head and tail of the queue
    private AtomicReference<Node<T>> head;
    private AtomicReference<Node<T>> tail;

    //Constructor
    public LockFreeQueue() {
        Node<T> dummy = new Node<T>(null);
        head = new AtomicReference<Node<T>>(dummy);
        tail = new AtomicReference<Node<T>>(dummy);
    }

    //Enqueue
    public void enqueue(T item) {
        Node<T> newNode = new Node<T>(item);
        while (true) {
            Node<T> currentTail = tail.get();
            Node<T> tailNext = currentTail.next.get();
            if (currentTail == tail.get()) {
                if (tailNext != null) {
                    tail.compareAndSet(currentTail, tailNext);
                } else {
                    if (currentTail.next.compareAndSet(null, newNode)) {
                        tail.compareAndSet(currentTail, newNode);
                        break;
                    }
                }
            }
        }
    }

    //Dequeue
    public T dequeue() {
        while (true) {
            Node<T> currentHead = head.get();
            Node<T> currentTail = tail.get();
            Node<T> headNext = currentHead.next.get();
            if (currentHead == head.get()) {
                if (currentHead == currentTail) {
                    if (headNext == null) {
                        return null;
                    }
                    tail.compareAndSet(currentTail, headNext);
                } else {
                    T item = headNext.item;
                    if (head.compareAndSet(currentHead, headNext)) {
                        return item;
                    }
                }
            }
        }
    }

    //Node class
    private class Node<T> {
        T item;
        AtomicReference<Node<T>> next;

        public Node(T item) {
            this.item = item;
            this.next = new AtomicReference<Node<T>>(null);
        }
    }
}
