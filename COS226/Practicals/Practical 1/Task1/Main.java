// James Cooks u21654680
public class Main {
    
    public static void main(String[] args){
        
        //m is upper bound
        int m = 10;
        //n is lower bound
        int n = 0;
        int[] array;
        int range = 0;
        int threadCount = 0;
        Task1[] threads;
        
        // //Dynamic thread count and range
        //     //Dynamic thread count
        //     //Largest divisor of array length
        //     for(int i = 1; i <= m - n; i++){
        //         if((m - n) % i == 0){
        //             threadCount = i;
        //         }
        //     }
            

        //     //Get the range of each thread
        //     if(range % threadCount == 0){
        //         range = m / threadCount;
        //     }else{
        //         range = (m / threadCount) + 1;
        //     }

        //Manual thread count and range
        threadCount = 5;
        range = 2;

        //Create array
        array = new int[m - n];

        //Populate array with values from n to m
        for(int i = 0; i < array.length; i++){
            array[i] = n + i;
        }

        //Print array
        System.out.println("Array:");
        System.out.print("[ ");
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
        System.out.print("] \n");

        //Create threads
        threads = new Task1[threadCount];

        //Populate threads
        for(int i = 0; i < threads.length; i++){
            threads[i] = new Task1(array, i * range, (i + 1) * range);
        }

        //Start threads
        for(int i = 0; i < threads.length; i++){
            threads[i].start();
        }



    


    }
}
