import java.util.concurrent.locks.Lock;

public class SharedResources {
	Lock l;

	SharedResources(int n){
		//l = new Filter(n);
		l = new Bakery(n);
	}


	public void access(){
		l.lock();
		try{
			System.out.println(Thread.currentThread().getName() + "--------------------------------Done");
			//Random number between 200 and 1000
			int sleepTime = (int) (Math.random() * 800) + 200;
			//Sleep for random time
			try
			{
				Thread.sleep(sleepTime);
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
		}finally{
			l.unlock();

		}
	}
}
