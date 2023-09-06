public class Node extends Thread {

    private Printer p;

	Node(Printer _p)
	{
		this.p = _p ;
	}

	@Override
	public void run()
	{
		//Make 5 print requests to the printer
		for (int i = 0; i < 5; i++)
		{
			//[Thread-Name][Request-Number]printingrequest.
			System.out.println(Thread.currentThread().getName() + " " + (i + 1) + " printing request.");
			p.Print(i+1);
		}
	}
}
