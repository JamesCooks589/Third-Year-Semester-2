public class MyThreads extends Thread {
    AtomicMRMW<Integer> register;
    boolean writer ;

	public MyThreads(AtomicMRMW<Integer> register_ , boolean writer ){
        this.register =register_ ;
        this.writer = writer ;
	}

	@Override
	public void run()
	{
        if (writer) {
			//Write random numbers between 0 and 100
			register.write((int) (Math.random() * 100));
		} else {
			register.read();
		}
	}

}
