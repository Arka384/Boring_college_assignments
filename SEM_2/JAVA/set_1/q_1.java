
import java.util.Scanner;

public class q_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        short a = sc.nextShort();
        System.out.print("Enter second number: ");
        short b = sc.nextShort();
        sc.close();

        short c = (short)(a+b);
        System.out.print("The addition of shorts are: " + c);
    }
}
