package q_4.BookList;

public interface BookListInterface {
    public void addBook(Book b);
    public Book getBookWithId(String id);
    public boolean isAvialble(String id);
    public void updateCopyAvailable(String bid, int val);
    public void incrementCopyAvailable(String id);
    public void decrementCopyAvailable(String id);
    public void displayBookWithId(String id);
    public void displayAllBooks();
}
