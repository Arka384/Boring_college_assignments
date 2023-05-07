import java.util.Scanner;

public class q_10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Metric mc = new Metric();
        System.out.println("1->Mile form Km\n2->Km from Mile\nChoice: ");
        int nChoice = sc.nextInt();
        switch(nChoice) {
            case 1:
                System.out.println("Enter distance in Km: ");
                double km = sc.nextDouble();
                System.out.println("Distance in Mile is: " + String.format("%.4f", mc.mileFromKm(km)));
                break;
            case 2:
                System.out.println("Enter distance in Mile: ");
                double mile = sc.nextDouble();
                System.out.println("Distance in Mile is: " + String.format("%.4f",mc.kmFromMile(mile)));
                break;
            default:
                System.out.println("Invalid choice");
        }
        sc.close();
    }   
}

class Metric {
    private double diff = 1.5;
    Metric() {}
    double mileFromKm(double Km) {
        return Km*(1/diff);
    }
    double kmFromMile(double Mile) {
        return Mile*diff;
    }
}
