package q_4.BookList;

import java.util.ArrayList;

public class BookList implements BookListInterface {
    ArrayList<Book> bookList=new ArrayList<Book>();
    
    public void addBook(Book b) {
        bookList.add(b);
        System.out.println("Book Added in the booklist...");
    }

    public Book getBookWithId(String id) {
        for(int i=0;i<bookList.size();i++) {
            Book obj = bookList.get(i);
            if(obj.book_id.equals(id))
                return obj;
        }
        return null;
    }

    public boolean isAvialble(String id) {
        Book obj = getBookWithId(id);
        if(obj != null) {
            if(obj.copies_available == 0)
                return false;
            else return true;
        }
        return false;
    }

    public void updateCopyAvailable(String bid, int val) {
        Book objBook = getBookWithId(bid);
        if(objBook != null){
            objBook.copies_available += val;
            objBook.copies_purchased += val;
        }
        else
            System.out.println("Book not found...");
    }

    public void incrementCopyAvailable(String id) {
        Book obj = getBookWithId(id);
        if(obj != null)
            obj.copies_available += 1;
        else
            System.out.println("Book not found...");
    }

    public void decrementCopyAvailable(String id) {
        Book obj = getBookWithId(id);
        if(obj != null)
            obj.copies_available -= 1;
        else
            System.out.println("Book not found...");
    }

    public void displayBookWithId(String id) {
        Book obj = getBookWithId(id);
        if(obj != null)
            System.out.println(obj);
        else
            System.out.println("Book not found");
    }

    public void displayAllBooks() {
        if(bookList.size() == 0) {
            System.out.println("No Book to Display...");
            return;
        }
        System.out.println("Book details:");
        for(int i=0;i<bookList.size();i++) {
            //Book b = bookList.get(i);
            System.out.print("Book "+(i+1)+"=> ");
            System.out.println(bookList.get(i));
        }
    }

}
