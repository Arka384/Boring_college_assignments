
public class q_6 {
    public static void main(String[] args) {
        show(20);
        show((short)24);
        show(25.56);
    }

    static void show(int a) {
        System.out.println("The parameter passed is: " + a);
    }
    static void show(double a) {
        System.out.println("The parameter passed is: " + a);
    }
}
