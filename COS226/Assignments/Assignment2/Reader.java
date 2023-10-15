public class Reader implements Runnable {
    private final MessageQueue queue;
    private final String name;

    public Reader(MessageQueue queue, String name) {
        this.queue = queue;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void notifyNewMessage() {
        // Implement notification logic here
    }

    public void run() {
        while (true) {
            Message message = queue.receiveMessage(name);
            if (message != null && message.getRecipient().equals(name)) {
                System.out.println("(RECEIVE)[" + Thread.currentThread().getName() + "]:" + "{recipient:" + name + ", sender:" + message.getSender() + "}");
            }
        }
    }
}
