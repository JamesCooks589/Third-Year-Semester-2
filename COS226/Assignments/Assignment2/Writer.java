import java.util.Random;
import java.util.UUID;

public class Writer implements Runnable {
    private final MessageQueue queue;
    private final String name;
    private final BakeryLock bakeryLock;
    private static final Random random = new Random();

    public Writer(MessageQueue queue, String name, BakeryLock bakeryLock) {
        this.queue = queue;
        this.name = name;
        this.bakeryLock = bakeryLock;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            String message = Client.messages[random.nextInt(Client.messages.length)];

            bakeryLock.lock(Integer.parseInt(name.substring(7)) - 1);
            try {
                String recipient = "Client " + (random.nextInt(Client.NUM_CLIENTS) + 1);
                while (recipient.equals(name)) {
                    recipient = "Client " + (random.nextInt(Client.NUM_CLIENTS) + 1);
                }

                String messageId = UUID.randomUUID().toString();
                Message newMessage = new Message(message, recipient, name, messageId);

                System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:" +
                        "{sender:" + name + ", recipient:" + recipient + "}");

                queue.sendMessage(newMessage);
                System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:SUCCESSFUL");
            } finally {
                bakeryLock.unlock(Integer.parseInt(name.substring(7)) - 1);
            }

            try {
                Thread.sleep(random.nextInt(Client.MAX_DELAY));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
