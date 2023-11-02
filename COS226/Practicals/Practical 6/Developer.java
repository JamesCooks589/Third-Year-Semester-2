import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;

public class Developer extends Thread {
    private CentralDatabase<Job> centralDB;
    private String name;
    private Random random = new Random();
    private AtomicInteger jobCount;

    public Developer(CentralDatabase<Job> centralDB, String name, AtomicInteger jobCount) {
        this.centralDB = centralDB;
        this.name = name;
        this.jobCount = jobCount;
    }

    @Override
    public void run(){
        //Every dev must schedule at least 3 jobs
        for (int i = 1; i <= 4; i++){
            int jobID = jobCount.getAndIncrement();
            //Hours is random number between 1 and 24
            int hours = random.nextInt(24) + 1;

            //Create job
            Job job = new Job(jobID, hours);
            //Insert job into central database
            centralDB.add(job);

            //Print job details
            //(IN)[thread-name][job-number][hours]
            System.out.println("(IN)[" + name + "][" + jobID + "][" + hours + "]");

            //Sleep for random time between 0 and 500ms
            try{
                Thread.sleep(random.nextInt(500));
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}
