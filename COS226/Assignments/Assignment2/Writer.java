import java.util.UUID;
import java.util.Random;

public class Writer implements Runnable {
    private final MessageQueue queue;
    private final String name;
    private static final Random random = new Random();

    public Writer(MessageQueue queue, String name) {
        this.queue = queue;
        this.name = name;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            String message = Client.messages[random.nextInt(Client.messages.length)];
            
            String recipient = "Client " + (random.nextInt(Client.NUM_CLIENTS) + 1);
            //Make sure I don't send a message to myself
            while (recipient.equals(name)) {
                recipient = "Client " + (random.nextInt(Client.NUM_CLIENTS) + 1);
            }

            String messageId = UUID.randomUUID().toString();
            Message newMessage = new Message(message, recipient, name, messageId);
            
            System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:" +
                    "{sender:" + name + ", recipient:" + recipient + "}");

            queue.sendMessage(newMessage);
            System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:SUCCESSFUL");

            try {
                Thread.sleep(random.nextInt(Client.MAX_DELAY));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
