import java.util.Scanner;

public class q_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of accounts: ");
        int n = sc.nextInt();
        Account accounts[] = new Account[n];
        for(int i=0;i<n;i++) {
            System.out.println("Enter details for account: " + (i+1));
            System.out.println("Enter ID: ");
            int id = sc.nextInt();
            System.out.println("Enter holders Name: ");
            //sc.next();
            String name = sc.next();
            System.out.println("Enter holders phone number: ");
            long phone = sc.nextLong();
            System.out.println("If priviledged customer then enter 1 else 0: ");
            int privi = sc.nextInt();
            accounts[i] = new Account(id, name, phone, (privi == 1) ? true : false);
        }
        
        boolean execute = true;
        while(execute) {
            System.out.println("1->account info\n2->find credit limit\n3->find current loan amount");
            System.out.println("4->loan can seek\n5->get loan\n6->Exit\nEnter choice: ");
            int nChoice = sc.nextInt();
            if(nChoice == 6)
                break;
            System.out.println("Enter account id to search: ");
            int currId = sc.nextInt();
            Account currAc = null;
            for(int i=0;i<n;i++) {
                if(accounts[i].getId() == currId)
                    currAc = accounts[i];
            }
            if(currAc == null) {
                System.out.println("Account not found");
                continue;
            }

            switch(nChoice) {
                case 1:
                    System.out.println(currAc);
                    break;
                case 2:
                    System.out.println("Credit limit is: " + currAc.getCreditLimit());
                    break;
                case 3:
                    System.out.println("Current loan amount is: " + currAc.getCurr_loan());
                    break;
                case 4:
                    System.out.println("Account can seek loan of: " + currAc.loanCanSeek());
                    break;
                case 5:
                    System.out.println("Enter amount of loan");
                    int loan = sc.nextInt();
                    if(currAc.askForLoan(loan))
                        System.out.println("Loan granted");
                    break;
                default:
                    System.out.println("Wrong choice");
            }
        }
        sc.close();
    }    
}

class Account {
    private int id;
    private String name;
    private int curr_loan;
    private long phone;
    private int creditLimit;
    private boolean isPrivileged;
    
    public Account() {
    }

    public Account(int id, String name, long phone, boolean isPrivileged) {
        this.id = id;
        this.name = name;
        this.curr_loan = 0;
        this.phone = phone;
        this.isPrivileged = isPrivileged;
        if(this.isPrivileged == true)
            this.creditLimit = 20000;
        else
            this.creditLimit = 10000;
    }

    boolean askForLoan(int amount) {
        if(this.creditLimit < (amount + this.curr_loan)) {
            System.out.println("Loan amount greater than credit limit");
            System.out.println("Loan not granted");
            return false;
        }
        this.curr_loan += amount;
        return true;
    }

    int loanCanSeek() {
        return this.creditLimit - this.curr_loan;
    }

    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getCreditLimit() {
        return creditLimit;
    }
    public int getCurr_loan() {
        return curr_loan;
    }
    public long getPhone() {
        return phone;
    }
    public void setPhone(long phone) {
        this.phone = phone;
    }
    @Override
    public String toString() {
        return "Account [id = " + id + ", name = " + name + ", curr_loan = " + curr_loan + ", phone = " + phone + "]";
    }
}

