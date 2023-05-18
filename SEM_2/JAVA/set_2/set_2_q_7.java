import java.util.Scanner;

public class set_2_q_7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine();
        sc.close();

        int count = appears(str, "a");
        System.out.println("Number of times 'a' appears: " + count);
        count = appears(str, "and");
        System.out.println("Number of times 'and' appears: " + count);
        System.out.println();

        System.out.println("The string starts " + ((str.startsWith("The")) ? "with" : "without") + " The\n");
        
        char charArr[] = str.toCharArray();
        System.out.println("The string as char array");
        for(char c : charArr)
            System.out.print(c);
        System.out.println();
        
        String tokens[] = str.split(" ");
        System.out.println("The tokens with '.' seperation are");
        for(String s : tokens)
            System.out.println(s);
        System.out.println();
        
    }
    
    static int appears(String str, String target) {
        int count = 0;
        while(str.contains(target)) {
            count++;
            str = str.replaceFirst(target, "");
        }
        return count;
    }

}
