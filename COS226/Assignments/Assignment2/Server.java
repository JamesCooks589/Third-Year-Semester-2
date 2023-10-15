public class Server {
    public static void main(String[] args) {
        MessageQueue queue = new MessageQueue();
        Server server = new Server(queue);

        // Initialize and start Reader and Writer threads
        for (int i = 0; i < Client.NUM_CLIENTS; i++) {
            new Thread(new Reader(queue, "Client " + (i + 1))).start();
            new Thread(new Writer(queue, "Client " + (i + 1))).start();
        }

        server.start();
    }

    private final MessageQueue queue;

    public Server(MessageQueue queue) {
        this.queue = queue;
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
