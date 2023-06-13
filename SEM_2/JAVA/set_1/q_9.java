import java.util.Scanner;

public class q_9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter account number: ");
        int accountNumber = sc.nextInt();
        System.out.println("Enter balance: ");
        float balance = sc.nextFloat();
        System.out.println(("Enter interest rate: "));
        float interestRate = sc.nextFloat();
        sc.close();
        BankAccount a = new BankAccount(accountNumber, balance, interestRate);

        System.out.println(a);
        a.calculate();
        System.out.println(a);
    }
}

class BankAccount {
    private int accNumber;
    private float balance;
    private float interset = 4.f;

    BankAccount() {}
    BankAccount(int accNumber, float balance, float interset) {
        this.accNumber = accNumber;
        this.balance = balance;
        this.interset = interset;
    }

    public float getBalance() {
        return balance;
    }
    void calculate() {
        float temp = balance * this.interset/100;
        this.balance = balance + temp;
    }

    public String toString() {
        return "accNumber = " + accNumber + ", balance = " + balance + ", interset = " + interset;
    }

}