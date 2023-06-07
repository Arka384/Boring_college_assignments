package q_3.Transaction;

public class Entry {
    String bookId;
    String memberId;

    public Entry(String bookId, String memberId) {
        this.bookId = bookId;
        this.memberId = memberId;
    }

    @Override
    public String toString() {
        return "Entry [bookId=" + bookId + ", memberId=" + memberId + "]";
    }
    
}
