// James Cooks u21654680
public class Main {
    
    public static void main(String[] args){
        
        //m is upper bound
        int m = 10;
        //n is lower bound
        int n = 0;
        int[] array;
        

        //Create array
        array = new int[m - n];

        //Populate array
        for(int i = 0; i < array.length; i++){
            array[i] = n + i;
        }

        System.out.println("Array:");
        System.out.print("[ ");
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.print("] \n");

        //Create 2 threads
        Task2 t1 = new Task2(array);
        Task2 t2 = new Task2(array);

        //Start threads
        t1.start();
        t2.start();
        


    


    }
}
