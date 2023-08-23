import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

// Name:
// Student Number:

public class Bakery implements Lock
{
	private volatile int[] ticket;
	private volatile boolean[] flag;
	private int n;
	//n is the number of levels

	public Bakery(int n)
	{
		//Set member variables
		this.n = n;
		ticket = new int[n];
		flag = new boolean[n];

		//Set initial values
		for (int i = 0; i < n; i++)
		{
			ticket[i] = 0;
			flag[i] = false;
		}
	}

	@Override
	public void lock() {
		int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
		flag[me] = true;
		ticket[me] = getMax(ticket) + 1;

		System.out.println(Thread.currentThread().getName() + ": flag[" + me + "] = true, ticket[" + me + "] = " + ticket[me]);

		for(int i = 0; i < n; i++)
		{
			while((i != me) && flag[i] && ((ticket[i] < ticket[me]) || (ticket[i] == ticket[me] && i < me)))
			{
				//Wait while other threads are in the same or higher level and I am the victim
			}
		}
	}

	@Override
	public void unlock() {
		int me = Integer.parseInt(Thread.currentThread().getName().substring(7));
		flag[me] = false;
	}

	private int getMax(int[] arr)
	{
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < arr.length; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
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
