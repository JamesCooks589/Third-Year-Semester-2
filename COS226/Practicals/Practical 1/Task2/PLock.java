//James Cooks u21654680
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class PLock implements Lock {
    private volatile boolean[] flag = new boolean[2];
    private volatile int victim;
    
    //Constructor
    public PLock(){}

    //Lock method
    public void lock(){
        //Get thread id
        int i = (int) Thread.currentThread().getId() % 2;
        //Other thread id
        int j = 1 - i;
        //Set flag to true
        flag[i] = true;
        //Set victim to self
        victim = i;
        //Wait until other thread is not in critical section or self is not the victim
        while(flag[j] && victim == i){}
    }

    //Unlock method
    public void unlock(){
        //Get thread id
        int i = (int) Thread.currentThread().getId() % 2;
        //Set flag to false
        flag[i] = false;
    }


    //Methods needed for interface
    public void lockInterruptibly(){} 
    public boolean tryLock() {return false;}
    public boolean tryLock(long time, TimeUnit unit){return false;}  
    public Condition newCondition(){return newCondition();} 
}
