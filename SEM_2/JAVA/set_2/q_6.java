
public class q_6 {
    public static void main(String[] args) {
        Integer n = 25;
        int i = 15;

        basicToObject(i);
        objectToBasic(n);
        basicToString(i);
        stringToObject("5678");
        objectToString(n);
        
    }

    static void basicToObject(int n) {
        Integer t = n;
        System.out.println("i: Basic type to object conversion: " + t);
    }
    static void objectToBasic(Integer n) {
        int t = n;
        System.out.println("ii: Object to primitive type conversion: " + t);
    }
    static void basicToString(int n) {
        System.out.println("iii: Basic to string type conversion: " + Integer.toString(n));
    }
    static void stringToObject(String str) {
        Integer t = Integer.parseInt(str);
        System.out.println("iv: String to object type conversion: " + t);
    }
    static void objectToString(Integer n) {
        System.out.println("v: Object to string type conversion: " + n);
    }

}
