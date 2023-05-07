
import java.util.Scanner;

public class q_4 {
    public static void main(String[] args) {
        final double pi = 3.141;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius: ");
        double radius = sc.nextDouble();
        sc.close();
        
        double area = pi * Math.pow(radius, 2);
        System.out.println("The area of the cirlce is: " + area);
        
    }
}
