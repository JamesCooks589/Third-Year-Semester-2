public class counter {
    public static int  counter = 0;

    //getAndIncrement increments the shared counter
    public int getAndIncrement(){
        return counter++;
    }
}
