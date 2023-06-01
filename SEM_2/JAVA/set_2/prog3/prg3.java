import Booklist.book;
import Booklist.booklist;
import Memberlist.member;
import Memberlist.memberlist;
import Transaction.transaction;
import Transaction.entry;

import java.util.*;

    public class prg3{
        public static void main(String[] args){
            Scanner sc=new Scanner(System.in);
            booklist blist = new booklist();
            memberlist mlist = new memberlist();
            transaction tt = new transaction();
            int ch;
            do{
                System.out.println("1.Add new book in the list");
            	System.out.println("2.Add more copies for a book");
            	System.out.println("3.Show all book details");
            	System.out.println("4.Show a particular book detail");
            	System.out.println("5.Add new member");
            	System.out.println("6.Show details of all members");
            	System.out.println("7.Show details of a member");
            	System.out.println("8.Issue a book");
            	System.out.println("9.Return a book");
            	System.out.println("10.Display All Transaction Details");
            	System.out.println("Enter your choice:");
                ch=sc.nextInt();
                sc.nextLine();
                switch(ch){
                    case 1:
                        System.out.println("Enter book_id,title,copies purchased:");
                        String bid=sc.nextLine();
                        if(!blist.match(bid)){
                            String title=sc.nextLine();
                            long copies=sc.nextLong();
                            book b=new book(bid,title,copies);
                            blist.add_book(b);
                        }
                        else{
                            System.out.println("Already Present.Copies incremented...");
                                    blist.increment(bid,1);
                        }
                        break;
                    case 2:
                        System.out.print("Enter book id:");
                        bid=sc.nextLine();
                        System.out.print("Increment by:");
                        long val=sc.nextLong();
                        blist.increment(bid,val);
                        break;
                    case 3:
                        blist.displayAll();
                        break;
                    case 4:
                        System.out.print("Enter book id:");
                        bid=sc.nextLine();
                        blist.display(bid);
                        break;
                    case 5:
                        System.out.println("Enter member_id,name,date of birth(dd/mm/yyyy) and number of books issued:");
                        String mid=sc.nextLine();
                        if(!mlist.match(mid)){
                            String name=sc.nextLine();
                            String date=sc.nextLine();
                            long issued=sc.nextLong();
                            member m=new member(mid,name,date,issued);
                            mlist.add_member(m);
                        }
                        else{
                            System.out.println("Member ID should be unique...");
                        }
                        break;
                    case 6:
                        mlist.displayAll();
                        break;
                    case 7:
                        System.out.print("Enter member id:");
                        mid=sc.nextLine();
                        mlist.display(mid);
                        break;
                    case 8:
                        System.out.println("Enter valid book_id:");
                        bid=sc.nextLine();
                        if(blist.match(bid)){
                            System.out.println("Enter valid member_id:");
                            mid=sc.nextLine();
                            if(mlist.match(mid)){
                                if(mlist.canIssue(mid)){
                                    if(blist.isAvialble(bid)){
                                        entry e=new entry(bid,mid);
                                        tt.Issue(e);
//decrement book availability and increment ember book issued count
                                        blist.dec_avl(bid);
                                        mlist.inc_issued(mid);
                                    }
                                    else{
                                        System.out.println("Sorry ! Books Shortage... ");
                                    }
                                }
                                else{
                                    System.out.println("Maximum number of books already issued...");
                                }
                            }
                            else{
                                System.out.println("Invalid Member ID...");
                            }
                        }
                        else{
                            System.out.println("Invalid Book ID...");
                        }
                        break;
                    case 9:
                        System.out.println("Enter valid book_id and member_ID:");
                        bid=sc.nextLine();
                        mid=sc.nextLine();
                        if(tt.match(bid,mid)){
                            System.out.println("Book Returned successfully...");
//increment book availability and decrement member book issued count
                            blist.inc_avl(bid);
                            mlist.dec_issued(mid);
                        }
                        else{
                            System.out.println("Wrong entry details...");
                        }
                        break;
                    case 10:
                        tt.displayAll();
                        break;
                }
            }while(ch>=1&&ch<=10);
            sc.close();
        }
    }
