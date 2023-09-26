import java.util.concurrent.locks.Lock;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;

public class BakeryLock implements Lock{
    private AtomicInteger current = new AtomicInteger(0);
    private AtomicInteger next = new AtomicInteger(0);

    @Override
    public void lock() {
        int myNumber = next.getAndIncrement();
        while (current.get() != myNumber) {
            // wait while not my turn
        }
    }

    @Override
    public void unlock() {
        current.getAndIncrement();
    }

    // Other methods are not needed for this assignment
    @Override
    public void lockInterruptibly() throws InterruptedException {
        throw new UnsupportedOperationException();
    }
    @Override
    public boolean tryLock() {
        throw new UnsupportedOperationException();
    }
    @Override
    public boolean tryLock(long time, java.util.concurrent.TimeUnit unit) throws InterruptedException {
        throw new UnsupportedOperationException();
    }
    @Override
    public Condition newCondition() {
        throw new UnsupportedOperationException();
    }
}