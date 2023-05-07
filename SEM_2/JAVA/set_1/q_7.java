
public class q_7 {
    public static void main(String[] args) {
        Student s = new Student();

        s.setRoll(10);
        s.setName("Arka");
        s.setScore(56.f);

        Student t = s;
        t.setRoll(50);
        System.out.println("The contents of the object are: ");
        System.out.println(s.getRoll());
        System.out.println(s.getName());
        System.out.println(s.getScore());

        System.out.println("The contents of the copied object are: ");
        System.out.println(t.getRoll());
        System.out.println(t.getName());
        System.out.println(t.getScore());

    }
}

class Student {
    private int roll;
    private String name;
    private float score;

    Student() {
        System.out.println("constructor invoked");
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
}
