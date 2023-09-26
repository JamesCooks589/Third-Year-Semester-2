import java.util.concurrent.locks.Lock;
import java.util.Random;

public class Update implements Runnable{
    private Crud crud;
    private Lock crudLock;
    private Lock updateLock;

    public Update(Crud crud, Lock updateLock, Lock crudLock){
        this.crud = crud;
        this.crudLock = crudLock;
        this.updateLock = updateLock;
    }

    @Override
    public void run(){
        while(crud.update.size() > 0){
            updateLock.lock();
            try{
                if (crud.update.size() > 0) {
                    System.out.println(Thread.currentThread().getName() + "[Update] is waiting for a request");
                    crudLock.lock();
                    try{
                        //Get the info to update from the queue
                        Info info = crud.update.poll();
                        boolean hasBeenSuccefullyUpdated = false;
                        //Loop through the database
                        for (Info i : crud.database) {
                            //Check if the id and name match
                            if (i.id.equals(info.id) && i.name.equals(info.name)) {
                                //Update values
                                i.assignments = info.assignments;
                                i.practicals = info.practicals;
                                //Update completed
                                hasBeenSuccefullyUpdated = true;
                                System.out.println(Thread.currentThread().getName() + "[Update] success " + info.toString());
                                //Only update first match
                                break;
                            }
                        }
                        if (!hasBeenSuccefullyUpdated) {
                          System.out.println(Thread.currentThread().getName() + "[Update] failed " + info.toString());
                          ++info.attempt;
                          //If the update has failed 2 times, don't try again
                            if (info.attempt < 3) {
                                crud.update.add(info);
                            }
                        }
                    }
                    finally{
                        crudLock.unlock();
                    }
                }
            }
            finally{
                updateLock.unlock();
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
                        
                
                