package q_4.BookList;

public class Book {
    String book_id;
    String title;
    int copies_purchased;
    int copies_available;
    
    public Book() {
    }

    public Book(String book_id, String title, int copies_purchased, int copies_available) {
        this.book_id = book_id;
        this.title = title;
        this.copies_purchased = copies_purchased;
        this.copies_available = copies_available;
    }

    @Override
    public String toString() {
        return "Book [book_id = " + book_id + ", title = " + title + ", copies_purchased = " + copies_purchased
                + ", copies_available = " + copies_available + " ]";
    }
    
}
