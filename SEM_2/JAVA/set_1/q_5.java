
import java.util.Scanner;

public class q_5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        String otherStr = str;
        System.out.println("With strings assigned");
        System.out.println("output of .equal() is: " + str.equals(otherStr));
        System.out.println("output of == is: " + (str == otherStr));

        System.out.print("\nEnter another string: ");
        String str2 = sc.nextLine();
        sc.close();

        System.out.println("\nWith same strings as input");
        System.out.println("output of .equal() is: " + str.equals(str2));
        System.out.println("output of == is: " + (str == str2));

    }
}
