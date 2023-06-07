package q_4;
import q_4.BookList.Book;
import q_4.BookList.BookList;
import q_4.MemberList.Member;
import q_4.MemberList.MemberList;
import q_4.Transaction.Entry;
import q_4.Transaction.Transaction;

import java.util.Scanner;

public class q_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BookList bList = new BookList();
        MemberList mList = new MemberList();
        Transaction tx = new Transaction();
        int choice = 0;

        do {
            System.out.println("\n\n1.Add new book in the list");
            System.out.println("2.Add more copies for a book");
            System.out.println("3.Show all book details");
            System.out.println("4.Show a particular book detail");
            System.out.println("5.Add new member");
            System.out.println("6.Show details of all members");
            System.out.println("7.Show details of a member");
            System.out.println("8.Issue a book");
            System.out.println("9.Return a book");
            System.out.println("10.Display All Transaction Details");
            System.out.println("11.Exit");
            System.out.println("Enter your choice:");
            choice = sc.nextInt();
            sc.nextLine();

            switch(choice) {
            case 1:
                System.out.println("Enter bookId: ");
                String bid = sc.nextLine();
                System.out.println("Enter book Title: ");
                String title = sc.nextLine();
                System.out.println("Enter book copies available: ");
                int c_available = sc.nextInt();
                System.out.println("Enter book copies purchased: ");
                int c_purchases = sc.nextInt();
                Book book = bList.getBookWithId(bid);
                if(book != null)
                    System.out.println("Already Present");
                else {
                    Book b = new Book(bid, title, c_purchases, c_available);
                    bList.addBook(b);
                }
                break;

            case 2:
                System.out.print("Enter book id: ");
                bid = sc.nextLine();
                System.out.print("Increment by: ");
                int val = sc.nextInt();
                bList.updateCopyAvailable(bid, val);
                break;

            case 3:
                bList.displayAllBooks();
                break;

            case 4:
                System.out.print("Enter book id: ");
                bid = sc.nextLine();
                bList.displayBookWithId(bid);
                break;

            case 5:
                System.out.println("Enter member id: ");
                String memberId = sc.nextLine();
                System.out.println("Enter member name: ");
                String memberName = sc.nextLine();
                System.out.println("Enter member DOB(dd/mm/yyyy): ");
                String date = sc.nextLine();
                Member member = mList.getMemberWithId(memberId);
                if(member != null)
                    System.out.println("Already Present");
                else {
                    Member m = new Member(memberId, memberName, date);
                    mList.addMember(m);
                }
                break;

            case 6:
                mList.displayAllMembers();
                break;

            case 7:
                System.out.print("Enter member id: ");
                memberId = sc.nextLine();
                mList.displayMemberWithId(memberId);
                break;

            case 8:
                System.out.println("Enter valid book_id: ");
                bid = sc.nextLine();
                System.out.println("Enter valid member_id: ");
                memberId = sc.nextLine();
                if(bList.getBookWithId(bid) == null || mList.getMemberWithId(memberId) == null) {
                    System.out.println("Invalid book_id or member_id given");
                    break;
                }
                if(bList.isAvialble(bid) == false) {
                    System.out.println("No copies of book available");
                    break;
                }
                if(mList.canIssue(memberId) == false) {
                    System.out.println("Member cannot issue more books");
                    break;
                }
                Entry e = tx.getEntry(bid, memberId);
                if(e != null) {
                    System.out.println(memberId + " has already borrowed " + bid);
                    break;
                }
                Entry entry = new Entry(bid, memberId);
                tx.Issue(entry);
                bList.decrementCopyAvailable(bid);
                mList.incrementIssued(memberId);
                break;

            case 9:
                System.out.println("Enter valid book_id: ");
                bid = sc.nextLine();
                System.out.println("Enter valid member_id: ");
                memberId = sc.nextLine();
                e = tx.getEntry(bid, memberId);
                if(e == null) {
                    System.out.println("Invalid details are given");
                    break;
                }
                tx.removeEntry(e);
                bList.incrementCopyAvailable(bid);
                mList.decrementIssued(memberId);
                break;

            case 10:
                tx.displayAllTransactions();
                break;
            
            default:
                break;
            }
            //end of switch
        } while(choice >= 1 && choice <= 10);
        sc.close();
        //end of while loop
    }


}
