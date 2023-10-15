public class Reader implements Runnable {
    private final MessageQueue queue;
    private final String name;
    private final BakeryLock bakeryLock;

    public Reader(MessageQueue queue, String name, BakeryLock bakeryLock) {
        this.queue = queue;
        this.name = name;
        this.bakeryLock = bakeryLock;
    }

    public void notifyNewMessage() {
        // Implement notification logic here
    }

    public String getName() {
        return name;
    }

    public void run() {
        while (true) {
            bakeryLock.lock(Integer.parseInt(name.substring(7)) - 1);
            try {
                Message message = queue.receiveMessage(name);
                if (message != null && message.getRecipient().equals(name)) {
                    System.out.println("(RECEIVE)[" + Thread.currentThread().getName() + "]:" +
                            "{recipient:" + name + ", sender:" + message.getSender() + "}");
                }
            } finally {
                bakeryLock.unlock(Integer.parseInt(name.substring(7)) - 1);
            }
        }
    }
}
