package q_4.Transaction;

import java.util.ArrayList;

public class Transaction implements TransactionInterface {
    ArrayList<Entry> transactions = new ArrayList<Entry>();

    public Entry getEntry(String bid, String mid) {
        for(int i=0;i<transactions.size();i++) {
            Entry obj = transactions.get(i);
            if(obj.bookId.equals(bid) && obj.memberId.equals(mid))
                return obj;
        }
        return null;
    }

    public void removeEntry(Entry obj) {
        transactions.remove(obj);
    }

    public void Issue(Entry e) {
        transactions.add(e);
        System.out.println("Transaction has been done successfully...");
    }
    
    public void displayAllTransactions() {
        if(transactions.size() == 0) {
            System.out.println("No transactions to Display...");
            return;
        }
        System.out.println("All transaction details are:");
        for(int i=0;i<transactions.size();i++) {
            // entry obj=ts.get(i);
            System.out.print("Transaction "+(i+1)+"=> ");
            System.err.println(transactions.get(i));
        }
    }

}
