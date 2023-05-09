package q_2;

public class Student extends Person {
    private int roll;
    private String course;

    public Student(String name, Address address, int roll, String course) {
        super(name, address);
        this.roll = roll;
        this.course = course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public int getRoll() {
        return roll;
    }
    public String getCourse() {
        return course;
    }

    @Override
    public String toString() {
        return "Student: roll=" + roll + ", course=" + course + "\n" + super.toString();
    }

}
