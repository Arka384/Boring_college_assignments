package q_4.Transaction;

public interface TransactionInterface {
    public Entry getEntry(String bid, String mid);
    public void removeEntry(Entry obj);
    public void Issue(Entry e);
    public void displayAllTransactions();
}
