public class AtomicSRSW<T> implements Register<T> {
    ThreadLocal<Long> lastStamp;
    ThreadLocal<StampedValue<T>> lastRead;
    // code (other member variables if any)
    StampedValue<T> r_value; // regular SRSW timestamp-value pair

    public AtomicSRSW(T init) {
        // code here
        r_value = new StampedValue<T>(init);
        //Set lastStamp to 0 using ThreadLocal
        lastStamp = new ThreadLocal<Long>(){
            protected Long initialValue() { return 0L; };
        };
        //Set lastRead 
        lastRead = new ThreadLocal<StampedValue<T>>(){
            protected StampedValue<T> initialValue() { return r_value; };
        };

    }

    public T read() {
        // code here
        StampedValue<T> value = r_value;
        StampedValue<T> last = lastRead.get();
        StampedValue<T> result = StampedValue.max(value, last);
        lastRead.set(result);
        System.out.println("(reader) " + Thread.currentThread().getName() + ": " + result.value);
        return result.value;
    }

    public void write(T v) {
        long stamp = lastStamp.get() + 1;
        r_value = new StampedValue<T>(stamp, v);
        lastStamp.set(stamp);
        System.out.println("(writer) " + Thread.currentThread().getName() + ": " + r_value.value);
    }
}
