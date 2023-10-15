import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;

public class MessageQueue {
    private final BlockingQueue<Message> queue = new LinkedBlockingQueue<>();
    private final Map<String, Lock> locks = new HashMap<>();
    private final Reader[] readers = new Reader[Client.NUM_CLIENTS];

    public void addReader(Reader reader) {
        readers[Integer.parseInt(reader.getName().substring(7)) - 1] = reader;
    }

    public void removeReader(Reader reader) {
        readers[Integer.parseInt(reader.getName().substring(7)) - 1] = null;
    }

    public void sendMessage(Message message) {
        Lock lock = getLock(message.getRecipient());
        lock.lock();
        try {
            try {
                queue.put(message);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Reader reader = readers[Integer.parseInt(message.getRecipient().substring(7)) - 1];
            if (reader != null) {
                reader.notifyNewMessage();
            }
        } finally {
            lock.unlock();
        }
    }

    public Message receiveMessage(String recipient) {
        Lock lock = getLock(recipient);
        lock.lock();
        try {
            Iterator<Message> iterator = queue.iterator();
            while (iterator.hasNext()) {
                Message message = iterator.next();
                if (message.getRecipient().equals(recipient)) {
                    iterator.remove();  // Use iterator to safely remove
                    return message;
                }
            }
        } finally {
            lock.unlock();
        }
        return null;
    }

    private Lock getLock(String recipient) {
        locks.putIfAbsent(recipient, new ReentrantLock());
        return locks.get(recipient);
    }
}
