import java.util.Random;
import java.util.concurrent.locks.Lock;

public class Create implements Runnable {
    private Crud crud;
    private Lock createLock;
    private Lock crudLock;

    public Create(Crud crud, Lock createLock, Lock crudLock) {
        this.crud = crud;
        this.createLock = createLock;
        this.crudLock = crudLock; 
    }

    @Override
    public void run() {
        while (crud.create.size() > 0){
            createLock.lock();
            try {
                if (crud.create.size() > 0) {
                    System.out.println(Thread.currentThread().getName() + "[Create] is waiting for a request");
                    crudLock.lock();
                    try{
                        Info info = crud.create.poll();
                        crud.database.add(info);
                        System.out.println(Thread.currentThread().getName() + "[Create] success " + info.toString());
                    }
                    finally{
                        crudLock.unlock();
                    }
                }
            } finally {
                createLock.unlock();
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
