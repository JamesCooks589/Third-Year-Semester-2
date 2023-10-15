import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

public class BakeryLock {
    private final AtomicBoolean[] choosing;
    private final AtomicInteger[] number;

    public BakeryLock(int numThreads) {
        choosing = new AtomicBoolean[numThreads];
        number = new AtomicInteger[numThreads];
        for (int i = 0; i < numThreads; i++) {
            choosing[i] = new AtomicBoolean(false);
            number[i] = new AtomicInteger(0);
        }
    }

    public void lock(int threadId) {
        choosing[threadId].set(true);
        int maxNumber = 0;
        for (int i = 0; i < number.length; i++) {
            int currentNumber = number[i].get();
            maxNumber = Math.max(maxNumber, currentNumber);
        }
        number[threadId].set(maxNumber + 1);
        choosing[threadId].set(false);

        for (int i = 0; i < number.length; i++) {
            if (i != threadId) {
                while (choosing[i].get()) {
                    // Wait while other threads are choosing
                }

                while (number[i].get() != 0 && (number[threadId].get() > number[i].get() ||
                        (number[threadId].get() == number[i].get() && threadId > i))) {
                    // Wait while other threads with smaller numbers or the same number but higher thread ID are in the critical section
                }
            }
        }
    }

    public void unlock(int threadId) {
        number[threadId].set(0);
    }
}
