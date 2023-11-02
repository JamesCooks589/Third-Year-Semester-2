public class Job {
    private int id;
    private int hours;
    private boolean approved;

    public Job(int id, int hours) {
        this.id = id;
        this.hours = hours;
        this.approved = false;
    }

    //Getters
    public int getId() {
        return id;
    }

    public int getHours() {
        return hours;
    }

    public boolean isApproved() {
        return approved;
    }

    //Setters
    public void approve() {
        this.approved = true;
    }

    void setHours(int hours) {
        this.hours = hours;
    }

    void setID(int id) {
        this.id = id;
    }
}
