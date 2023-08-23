public class Main {
    public static void main(String[] args) {
        int n = 5;
	    MyThread[] threads = new MyThread[n];

        SharedResources CriticalSection = new SharedResources(n);

        for(int i = 0; i < n; i++)
            threads[i] = new MyThread(CriticalSection);

        for(MyThread t : threads)
            t.start();

    }
}
