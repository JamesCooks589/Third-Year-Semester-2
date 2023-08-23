// James Cooks u21654680
public class Task1 extends Thread{
    private int[] array;
    private int from;
    private int to;

    //COnstructor takes in array object and range variables
    public Task1(int[] array, int from, int to){
        this.array = array;
        this.from = from;
        this.to = to;
    }

    //run searches the array object and display output when a prime nuimber is found.
    public void run(){
        for(int i = from; i < to; i++){
            if(isPrime(array[i])){
                System.out.println(this.getName() + " [" + from + "-" + to + "]: " + array[i]);
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
