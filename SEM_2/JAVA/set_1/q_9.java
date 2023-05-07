
public class q_9 {
    public static void main(String[] args) {
        BankAccount a = new BankAccount(123456, 100, 4.f);

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

    void calculate() {
        float temp = balance * this.interset/100;
        this.balance = balance + temp;
    }

    public String toString() {
        return "accNumber = " + accNumber + ", balance = " + balance + ", interset = " + interset;
    }

}