package q_5;

import java.util.Scanner;

public class q_5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Creating a student object");
        Student student = new Student();
        
        System.out.println("Enter student roll");
        int roll = sc.nextInt();
        try {
            System.out.println("Enter student score");
            int score = sc.nextInt();
            student.setRoll(roll);
            student.setScore(score);
            sc.close();
            System.out.println(student);
        }
        catch (InvalidScoreException e) {
            System.out.println(e);
            System.out.println("Student object not created");
        }
        
    }
}
