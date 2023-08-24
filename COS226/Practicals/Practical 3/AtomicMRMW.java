public class AtomicMRMW<T> implements Register<T>{

    private StampedValue<T>[] a_table; // array of atomic MRSW registers

    @SuppressWarnings("unchecked")
    public AtomicMRMW(int capacity, T init) {
        a_table = (StampedValue<T>[]) new StampedValue[capacity];
        StampedValue<T> value = new StampedValue<T>(init);
        //Initialize the table
        for (int i = 0; i < capacity; i++) {
            a_table[i] = value;
        }
    }

    public void write(T value) {
        int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
        StampedValue<T> max = StampedValue.MIN_VALUE;
        //Write the table
        for (int i = 0; i < a_table.length; i++) {
            a_table[i] = new StampedValue<T>(value);
        }
        a_table[me] = new StampedValue<T>(max.stamp + 1, value);
        System.out.println("(writer) " + Thread.currentThread().getName() + ": " + value);
    }

    public T read() {
        StampedValue<T> max = StampedValue.MIN_VALUE;
        //Find highest stamp
        for (int i = 0; i < a_table.length; i++) {
            max = StampedValue.max(max, a_table[i]);
        }
        System.out.println("(reader) " + Thread.currentThread().getName() + ": " + max.value);
        return max.value;
    }
}
