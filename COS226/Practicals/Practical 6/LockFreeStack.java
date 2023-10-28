import java.util.concurrent.atomic.AtomicReference;

public class LockFreeStack<T> {
    private AtomicReference<Node<T>> top = new AtomicReference<>();

    public void push(T item) {
        Node<T> newNode = new Node<T>(item);
        while (true) {
            Node<T> currentTop = top.get();
            newNode.next = currentTop;
            if (top.compareAndSet(currentTop, newNode)) {
                break;
            }
        }
    }

    public T pop() {
        while (true) {
            Node<T> currentTop = top.get();
            if (currentTop == null) {
                return null;
            }
            Node<T> newTop = currentTop.next;
            if (top.compareAndSet(currentTop, newTop)) {
                return currentTop.item;
            }
        }
    }

    private class Node<T> {
        T item;
        Node<T> next;

        public Node(T item) {
            this.item = item;
        }
    }
}
