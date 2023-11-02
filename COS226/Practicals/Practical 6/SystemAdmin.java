import java.util.Random;

public class SystemAdmin extends Thread{
    private CentralDatabase<Job> centralDB;
    private String name;
    private Random random = new Random();

    public SystemAdmin(CentralDatabase<Job> centralDB, String name) {
        this.centralDB = centralDB;
        this.name = name;
    }

    @Override
    public void run(){
        try{
            Thread.sleep(random.nextInt(100));
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }

        //Admins remove jobs until there are no more jobs
        while(true){
            //Remove job from central database
            Job job = centralDB.remove();

           if (job != null){
                int approval = random.nextInt(24) + 1;

                if (approval >= job.getHours()) {
                    job.approve();
                }

                //(OUT)[thread-name][job-number][hours][approval-status]
                System.out.println("(OUT)[" + name + "][" + job.getId() + "][" + job.getHours() + "][" + job.isApproved() + "]");
            }

        }
    }
}
