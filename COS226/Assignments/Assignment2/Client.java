import java.util.Random;

public class Client extends Thread {
    public static String[] messages = {"Hello", "How are you?", "I'm fine", "Goodbye", "See you later", "Good morning", "Good afternoon", "Good evening", "Good night", "Good luck"};
    private static Thread readThread;
    private static Thread writeThread;
    public static final int NUM_CLIENTS = 4;
    public static final int NUM_MESSAGES = 10;
    public static final int MAX_DELAY = 1000;
    public final String name;
    public int messagesSent = 0;
    private final MessageQueue queue;
    private final BakeryLock bakeryLock; // New parameter
    public static final Random random = new Random(); // Added random field

    public Client(String name, MessageQueue queue, BakeryLock bakeryLock) { // Updated constructor
        this.name = name;
        this.queue = queue;
        this.bakeryLock = bakeryLock; // Initialize the bakeryLock
    }

    public void run() {
        if (readThread == null || !readThread.isAlive()) {
            readThread = new Thread(new Reader(queue, name, bakeryLock)); // Pass bakeryLock to Reader
            readThread.start();
        }
        if (writeThread == null || !writeThread.isAlive()) {
            writeThread = new Thread(new Writer(queue, name, bakeryLock)); // Pass bakeryLock to Writer
            writeThread.start();
        }
    }
}
