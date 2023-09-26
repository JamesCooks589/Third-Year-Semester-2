import java.util.concurrent.locks.Lock;
import java.util.Random;

public class Read implements Runnable{
    private Crud crud;
    private Lock crudLock;
    private Lock readLock;

    public Read(Crud crud, Lock readLock, Lock crudLock){
        this.crud = crud;
        this.crudLock = crudLock;
        this.readLock = readLock;
    }

    @Override
    public void run(){
        while(crud.read.size() > 0){
            readLock.lock();
            try{
                boolean read = crud.read.poll();
                if (read) {
                    System.out.println(Thread.currentThread().getName() + "[Read] is waiting for a request");
                    crudLock.lock();
                    try{
                        System.out.println(Thread.currentThread().getName() + "[Read]");
                        System.out.println("------------------------");
                        for (Info info : crud.database) {
                            System.out.println(info.toString());
                        }
                        System.out.println("------------------------");
                    }
                    finally{
                        crudLock.unlock();
                    }
                }
            }
            finally{
                readLock.unlock();
                try {
                    //Sleep for between 50 and 100 ms
                    Thread.sleep(new Random().nextInt(50) + 50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}