import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        MessageQueue server = new MessageQueue();
        Client[] clients = new Client[Client.NUM_CLIENTS];

        for (int i = 0; i < Client.NUM_CLIENTS; i++) {
            clients[i] = new Client("Client " + (i + 1), server);
            clients[i].start();
        }

        for (int i = 0; i < Client.NUM_MESSAGES; i++) {
            int clientIndex = Client.random.nextInt(Client.NUM_CLIENTS);
            Client sender = clients[clientIndex];

            if (sender.messagesSent < 10) {
                String message = Client.messages[Client.random.nextInt(Client.messages.length)];
                String recipient = "Client " + (Client.random.nextInt(Client.NUM_CLIENTS) + 1);
                String messageId = UUID.randomUUID().toString();
                Message newMessage = new Message(message, recipient, sender.getName(), messageId);

                System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:" +
                        "{sender:" + sender.getName() + ", recipient:" + recipient + "}");
                server.sendMessage(newMessage);
                System.out.println("(SEND)[" + Thread.currentThread().getName() + "]:SUCCESSFUL");

                sender.messagesSent++;

                try {
                    Thread.sleep(Client.random.nextInt(Client.MAX_DELAY));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
