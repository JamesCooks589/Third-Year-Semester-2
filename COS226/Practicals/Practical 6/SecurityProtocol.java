import java.util.concurrent.atomic.AtomicInteger;

public class SecurityProtocol{
    public static void main(String[] args){
        //Create central database
        //True uses a queue, false uses a stack
        CentralDatabase<Job> centralDB = new CentralDatabase<Job>(true);

        //Create Developer threads
        AtomicInteger jobCount = new AtomicInteger(1);

        Developer dev1 = new Developer(centralDB, "Dev1", jobCount);
        Developer dev2 = new Developer(centralDB, "Dev2", jobCount);
        Developer dev3 = new Developer(centralDB, "Dev3", jobCount);
        Developer dev4 = new Developer(centralDB, "Dev4", jobCount);

        //Create SystemAdmin threads
        SystemAdmin admin1 = new SystemAdmin(centralDB, "Admin 1");
        SystemAdmin admin2 = new SystemAdmin(centralDB, "Admin 2");

        //Start threads
        dev1.start();
        dev2.start();
        dev3.start();
        dev4.start();

        admin1.start();
        admin2.start();
    }


}