import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.atomic.AtomicReference;

public class Timeout implements Lock {
    static Qnode AVAILABLE = new Qnode();
    AtomicReference<Qnode> tail;
    ThreadLocal<Qnode> myNode;

    //Constructor for TOLock
    public Timeout(){
        tail = new AtomicReference<Qnode>(null);
        myNode = new ThreadLocal<Qnode>(){
            protected Qnode initialValue(){
                return new Qnode();
            }
        };
    }

    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        long startTime = System.currentTimeMillis();
        long patience = TimeUnit.MILLISECONDS.convert(time, unit);
        Qnode qnode = new Qnode();
        myNode.set(qnode);
        qnode.pred = null;
        Qnode myPred = tail.getAndSet(qnode);
        if (myPred == null || myPred.pred == AVAILABLE) {
            return true;
        }
        while (System.currentTimeMillis() - startTime < patience) {
            Qnode predPred = myPred.pred;
            if (predPred == AVAILABLE) {
                return true;
            } else if (predPred != null) {
                myPred = predPred;
            }
        }
        if (!tail.compareAndSet(qnode, myPred)) {
            qnode.pred = myPred;
        }
        return false;
    }

    public void unlock() {
        Qnode qnode = myNode.get();
        if(!tail.compareAndSet(qnode, null)){
            qnode.pred = AVAILABLE;
        }
    }

    //Unimplemented methods from Lock interface

    @Override
    public void lock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lock'");
    }

    @Override
    public void lockInterruptibly() throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lockInterruptibly'");
    }


    @Override
    public Condition newCondition() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'newCondition'");
    }

    @Override
    public boolean tryLock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }
    
static class Qnode{
    volatile public Qnode pred = null;
    }
   
}



