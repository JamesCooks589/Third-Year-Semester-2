import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name: James Cooks
// Student Number: u2165680

public class Filter implements Lock
{
	private volatile int size;
	private volatile int[] level;
	private volatile int[] victim;

	public Filter(int n)
	{
		//Set member variables
		size = n;
		level = new int[n];
		victim = new int[n];

		//Set initial values
		for (int i = 0; i < n; i++)
		{
			level[i] = 0;
		}
	}

	@Override
	public void lock() {
		//Get thread id
		int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
		for(int L = 1 ; L < size ; L++)
		{
			int k = 0;
			level[me] = L;
			victim[L] = me;
			//Wait until no other thread is at this level or higher
                while((k != me) && (level[k] >= L && victim[L] == me))
				{
					k++;
				}
			
			System.out.println(Thread.currentThread().getName() + ": level[" + me + "] = " + L + ", victim[" + L + "] = " + me);
		}
	}

	@Override
	public void unlock() {
		int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
		level[me] = 0;
	}
	

	public void lockInterruptibly() throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock()
	{
		throw new UnsupportedOperationException();
	}

	public boolean tryLock(long time, TimeUnit unit) throws InterruptedException
	{
		throw new UnsupportedOperationException();
	}

	public Condition newCondition()
	{
		throw new UnsupportedOperationException();
	}

	

}
