import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.atomic.AtomicReference;

public class MCSQueue implements Lock{
    AtomicReference<Qnode> tail;
    ThreadLocal<Qnode> myNode;

    //Constructor for MCSQueue
    public MCSQueue(){
        tail = new AtomicReference<Qnode>(null);
        myNode = new ThreadLocal<Qnode>(){
            protected Qnode initialValue(){
                return new Qnode();
            }
        };
    }

    public void lock(){
        Qnode qnode = myNode.get();
        Qnode pred = tail.getAndSet(qnode);
        if(pred != null){
            qnode.locked = true;
            pred.next = qnode;
            while(qnode.locked){
                System.out.print("");
            }
        }
    }

    public void unlock(){
        Qnode qnode = myNode.get();
        if(qnode.next == null){
            if(tail.compareAndSet(qnode, null)){
                return;
            }
            while(qnode.next == null){
            }
        }
        qnode.next.locked = false;
        qnode.next = null;

    }

    //Unimplemented methods from Lock interface
    @Override
    public void lockInterruptibly() throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'lockInterruptibly'");
    }

    @Override
    public boolean tryLock() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }

    @Override
    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'tryLock'");
    }

    @Override
    public Condition newCondition() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'newCondition'");
    }
    
}


class Qnode{
    volatile boolean locked = false;
    Qnode next = null;

}
