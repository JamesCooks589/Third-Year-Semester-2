import java.util.concurrent.locks.Lock;

public class DatabaseManager {
    //Main
    public static void main(String[] args) {
        Crud crud = new Crud();
        
        //Small locks for each operation type
        Lock createLock = new BakeryLock();
        Lock readLock = new BakeryLock();
        Lock updateLock = new BakeryLock();
        Lock deleteLock = new BakeryLock();

        //Big Lock for the database
        Lock lock = new BakeryLock();

        //Create n threads of each operation type (n = 2)
        for (int i = 0; i < 2; i++) {
            Thread createThread = new Thread(new Create(crud, createLock, lock), "Create Thread " + i);
            Thread readThread = new Thread(new Read(crud, readLock, lock), "Read Thread " + i);
            Thread updateThread = new Thread(new Update(crud, updateLock, lock), "Update Thread " + i);
            Thread deleteThread = new Thread(new Delete(crud, deleteLock, lock), "Delete Thread " + i);

            //Start the threads
            createThread.start();
            readThread.start();
            updateThread.start();
            deleteThread.start();

        }
    }
}
