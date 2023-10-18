import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;

public class MessageQueue {
    private final BlockingQueue<Message> queue = new LinkedBlockingQueue<>();
    private final Map<String, Object> locks = new HashMap<>(); // Use Object as a simple lock
    private final Reader[] readers = new Reader[Client.NUM_CLIENTS];

    public void addReader(Reader reader) {
        readers[Integer.parseInt(reader.getName().substring(7)) - 1] = reader;
    }

    public void removeReader(Reader reader) {
        readers[Integer.parseInt(reader.getName().substring(7)) - 1] = null;
    }

    public void sendMessage(Message message) {
        synchronized (getLock(message.getRecipient())) {
            try {
                queue.put(message);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Reader reader = readers[Integer.parseInt(message.getRecipient().substring(7)) - 1];
            if (reader != null) {
                reader.notifyNewMessage();
            }
        }
    }

    public Message receiveMessage(String recipient) {
        synchronized (getLock(recipient)) {
            Iterator<Message> iterator = queue.iterator();
            while (iterator.hasNext()) {
                Message message = iterator.next();
                if (message.getRecipient().equals(recipient)) {
                    iterator.remove();  // Use iterator to safely remove
                    return message;
                }
            }
        }
        return null;
    }

    private Object getLock(String recipient) {
        locks.putIfAbsent(recipient, new Object());
        return locks.get(recipient);
    }
}
