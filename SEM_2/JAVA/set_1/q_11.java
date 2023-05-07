
// import java.util.Scanner;

public class q_11 {
    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        Instructor ins1 = new Instructor("Ins_1", 1234);
        Instructor ins2 = new Instructor("Ins_2", 5678);

        TextBook text1 = new TextBook("Book_1", "auth_1", "pub_1");
        TextBook text2 = new TextBook("Book_2", "auth_2", "pub_2");
        
        Course cs1 = new Course("Course_1", ins1, text1);
        Course cs2 = new Course("Course_2", ins2, text2);

        System.out.println(ins1 + "\n");
        System.out.println(ins2 + "\n");
        
        System.out.println(text1 + "\n");
        System.out.println(text2 + "\n");
        
        System.out.println(cs1 + "\n");
        System.out.println(cs2 + "\n");


    }
}

class TextBook {
    private String title;
    private String author;
    private String publisher;
    public TextBook(String title, String author, String publisher) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
    }
    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }
    public String getAuthor() {
        return author;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
    public String getPublisher() {
        return publisher;
    }
    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }
    @Override
    public String toString() {
        return "TextBook [title = " + title + ", author = " + author + ", publisher = " + publisher + "]";
    }
}

class Instructor {
    private String name;
    private long phone;

    public Instructor(String name, long phone) {
        this.name = name;
        this.phone = phone;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public long getPhone() {
        return phone;
    }
    public void setPhone(long phone) {
        this.phone = phone;
    }
    @Override
    public String toString() {
        return "Instructor [name = " + name + ", phone = " + phone + "]";
    }
}

class Course {
    private String name;
    private Instructor instructor;
    private TextBook textBook;
    
    public Course(String name, Instructor instructor, TextBook textBook) {
        this.name = name;
        this.instructor = new Instructor(instructor.getName(), instructor.getPhone());
        this.textBook = new TextBook(textBook.getTitle(), textBook.getAuthor(), textBook.getPublisher());
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Instructor getInstructor() {
        return instructor;
    }
    public void setInstructor(Instructor instructor) {
        this.instructor = instructor;
    }
    public TextBook getTextBook() {
        return textBook;
    }
    public void setTextBook(TextBook textBook) {
        this.textBook = textBook;
    }
    @Override
    public String toString() {
        return "Course [name = " + name + ", instructor = " + instructor + ", textBook = " + textBook + "]";
    }

}