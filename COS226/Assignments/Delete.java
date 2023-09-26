import java.util.concurrent.locks.Lock;
import java.util.Random;

public class Delete implements Runnable{
    private Crud crud;
    private Lock crudLock;
    private Lock deleteLock;

    public Delete(Crud crud, Lock deleteLock, Lock crudLock){
        this.crud = crud;
        this.crudLock = crudLock;
        this.deleteLock = deleteLock;
    }

    @Override
    public void run(){
        while(crud.delete.size() > 0){
            deleteLock.lock();
            try{
                if (crud.delete.size() > 0) {
                    System.out.println(Thread.currentThread().getName() + "[Delete] is waiting for a request");
                    crudLock.lock();
                    try{
                        Info info = crud.delete.poll();
                        boolean hasBeenSuccefullyDeleted = false;
                        //Loop through the database
                        for (Info i : crud.database) {
                            //Check if the id and name match
                            if (i.id.equals(info.id) && i.name.equals(info.name)) {
                                //Delete the entry
                                crud.database.remove(i);
                                //Delete completed
                                hasBeenSuccefullyDeleted = true;
                                System.out.println(Thread.currentThread().getName() + "[Delete] success " + info.toString());
                                //Only delete first match
                                break;
                            }
                        }
                        if (hasBeenSuccefullyDeleted) {
                            System.out.println(Thread.currentThread().getName() + "[Delete] success " + info.toString());
                        }
                        else{
                            System.out.println(Thread.currentThread().getName() + "[Delete] failed " + info.toString());
                            ++info.attempt;
                            //If the delete has failed 2 times, don't try again
                            if (info.attempt < 3) {
                                crud.delete.add(info);
                            }
                        }
                    }
                    finally{
                        crudLock.unlock();
                    }
                }
            }
            finally{
                deleteLock.unlock();
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