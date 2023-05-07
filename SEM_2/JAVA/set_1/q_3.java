
import java.util.Scanner;

public class q_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter height in cm: ");
        int cm = sc.nextInt();
        sc.close();

        float inch = (float)cm/2.45f;
        float feet = (float)cm/30.5f;
        System.out.println("The height in inch is: " + inch);
        System.out.println("The height in feet is: " + feet);
    }
}
