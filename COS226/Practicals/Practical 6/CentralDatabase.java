public class CentralDatabase<T> {
    //Task 1
    private LockFreeQueue<T> queue;
    //Task 2
    private LockFreeStack<T> stack;

    private boolean useQueue;

    public CentralDatabase(boolean useQueue) {
        this.useQueue = useQueue;
        if (useQueue) {
            queue = new LockFreeQueue<T>();
        } else {
            stack = new LockFreeStack<T>();
        }
    }

    public void add(T item) {
        if (useQueue) {
            queue.enqueue(item);
        } else {
            stack.push(item);
        }
    }

    public T remove() {
        if (useQueue) {
            return queue.dequeue();
        } else {
            return stack.pop();
        }
    }
}
