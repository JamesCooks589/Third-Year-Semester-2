import java.util.concurrent.locks.Lock;

public class Printer {
    Lock l;

	//Constructor for Printer
	public Printer(){
		l = new MCSQueue();
		//l = new Timeout();
	}

	public void Print(int reqNum){
		l.lock();
		// try {
		// 	l.tryLock(100, java.util.concurrent.TimeUnit.MILLISECONDS);
		// } catch (InterruptedException e) {
		// 	e.printStackTrace();
		// }
		try{
			//Print
			System.out.println("["+Thread.currentThread().getName() +"] [Request Number: " + reqNum + "] printing: LMAO look at this funny random number: " + (int) (Math.random() * 1000) + ". :skullEmoji:");
			//Sleep between 200 and 1000 ms
			int randomSleep = (int) (Math.random() * 800) + 200;
			Thread.sleep(randomSleep);
		}
		catch(InterruptedException e){
			System.out.println(e.getMessage());
		}
		finally{
			l.unlock();
		}
	}
}
