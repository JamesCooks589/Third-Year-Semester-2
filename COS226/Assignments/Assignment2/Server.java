public class Server {
    public static void main(String[] args) {
        MessageQueue queue = new MessageQueue();
        BakeryLock bakeryLock = new BakeryLock(Client.NUM_CLIENTS); // Create the BakeryLock

        Server server = new Server(queue, bakeryLock);

        // Initialize and start Reader and Writer threads
        for (int i = 0; i < Client.NUM_CLIENTS; i++) {
            new Thread(new Reader(queue, "Client " + (i + 1), bakeryLock)).start(); // Pass bakeryLock
            new Thread(new Writer(queue, "Client " + (i + 1), bakeryLock)).start(); // Pass bakeryLock
        }

        server.start();
    }

    private final MessageQueue queue;
    private final BakeryLock bakeryLock;

    public Server(MessageQueue queue, BakeryLock bakeryLock) {
        this.queue = queue;
        this.bakeryLock = bakeryLock;
    }

    public void start() {
        while (true) {
            Message message = queue.receiveMessage("Server");
            if (message != null) {
                System.out.println("(RECEIVE)[" + Thread.currentThread().getName() + "]:" + "{recipient:Server, sender:" + message.getSender() + "}");
            }
        }
    }
}
