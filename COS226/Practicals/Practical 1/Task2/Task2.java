// James Cooks u21654680
public class Task2 extends Thread{
    private int[] array;
    //Shared counter
    private counter currIndex = new counter();
    //Lock
    private PLock lock = new PLock();
    int index = 0;

    //Constructor
    public Task2(int[] array){
        this.array = array;
    }

    //Run method
    public void run(){
        //While the index is less than the array length
        while(index < array.length){
            lock.lock();
            //Critical section
            try{
                //Check if index is out of bounds
                if(currIndex.counter >= array.length){
                    break;
                }
                
                index = currIndex.getAndIncrement();
            }finally{
                //Release lock
                lock.unlock();
            }
            //Output in format similair to task 1
            if(isPrime(array[index])){
                System.out.println(this.getName() + " [" + index +"]: " + array[index]);
            }
        }

    }



    //isPrime checks if a number is prime
    public boolean isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }





}
