
public class q_8 {
    public static void main(String[] args) {
        Student s = new Student();
        Student s1 = new Student(50);
        Student s2 = new Student(10, "Arka");
        Student s3 = new Student(20, "Ram", 70);

        Student s4 = new Student(s3);

        System.out.println("s = [" + s + "]");
        System.out.println("s1 = [" + s1 + "]");
        System.out.println("s2 = [" + s2 + "]");
        System.out.println("s3 = [" + s3 + "]");
        System.out.println("s4 = [" + s4 + "]");
    }
}

class Student {
    private int roll;
    private String name;
    private float score;

    Student() {
        System.out.println("Default constructor invoked");
        this.roll = -1;
        this.name = null;
        this.score = -1;
    }
    Student(int roll) {
        System.out.println("constructor with ROLL invoked");
        this.roll = roll;
    }
    Student(int roll, String name) {
        System.out.println("constructor with ROLL, NAME invoked");
        this.roll = roll;
        this.name = name;
    }
    Student(int roll, String name, int score) {
        System.out.println("constructor with ROLL, NAME, SCORE invoked");
        this.roll = roll;
        this.name = name;
        this.score = score;
    }
    Student(Student other) {
        System.out.println("COPY constructor invoked");
        this.roll = other.roll;
        this.name = other.name;
        this.score = other.score;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setScore(float score) {
        this.score = score;
    }

    public int getRoll() {
        return this.roll;
    }
    public String getName() {
        return this.name;
    }
    public float getScore() {
        return this.score;
    }

    public String toString() {
        return "Roll = " + roll + " Name = " + name + " Score = " + score;
    }

}

