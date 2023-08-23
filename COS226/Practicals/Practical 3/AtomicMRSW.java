public class AtomicMRSW<T> implements Register<T> {
    ThreadLocal<Long> lastStamp;
    // code (other member variables if any)
    private StampedValue<T>[][] a_table; // each entry is SRSW atomic

    @SuppressWarnings("unchecked")
    public AtomicMRSW(T init, int readers) {
        lastStamp = new ThreadLocal<Long>(){
            protected Long initialValue() { return 0L; };
        };
        a_table = (StampedValue<T>[][]) new StampedValue[readers][readers];
        StampedValue<T> value = new StampedValue<T>(init);
        //Initialize the table
        for (int i = 0; i < readers; i++) {
            for (int j = 0; j < readers; j++) {
                a_table[i][j] = value;
            }
        }
    }

    public T read() {
        int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
       StampedValue<T> value = a_table[me][me];
       //Read the table
       for (int i = 0; i < a_table.length; i++) {
           value = StampedValue.max(value, a_table[i][me]);
       }
         for (int i = 0; i < a_table.length; i++) {
              a_table[me][i] = value;
         }
         System.out.println("(reader) " + Thread.currentThread().getName() + ": " + value.value);
        return value.value;
    }

    public void write(T v) {
        long stamp = lastStamp.get() + 1;
        lastStamp.set(stamp);
        StampedValue<T> value = new StampedValue<T>(stamp, v);
        //Write the table
        for (int i = 0; i < a_table.length; i++) {
            a_table[i][i] = value;
        }
        System.out.println("(writer) " + Thread.currentThread().getName() + ": " + value.value);
    }
}
