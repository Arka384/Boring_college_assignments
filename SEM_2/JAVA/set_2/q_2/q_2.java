package q_2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class q_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        List<Student> students = new ArrayList<Student>();
        List<Faculty> faculties = new ArrayList<Faculty>();
    
        Address add1 = new Address(10, "Pal st", "Kolkata", "WB", 700002);
        Address add2 = new Address(4, "Hori ghosh st", "Howrah", "WB", 2000343);
        Address add3 = new Address(50, "College st", "Darjelling", "WB", 5020003);
        Address add4 = new Address(6, "Kalikumar st", "Kolkata", "WB", 700006);
        
        Student student_1 = new Student("Ram", add1, 1, "MCA");
        Student student_2 = new Student("Shyam", add2, 2, "BTECH");
        Student student_3 = new Student("Jadu", add3, 3, "MCA");
        students.add(student_1);
        students.add(student_2);
        students.add(student_3);

        Faculty fac_1 = new Faculty("Dipesh", add2, 32, "CSE", "Teacher");
        Faculty fac_2 = new Faculty("Samaresh", add4, 12, "Admin", "Admission");
        faculties.add(fac_1);
        faculties.add(fac_2);

        
        boolean executed = true;
        while(executed) {
            System.out.println("1 -> view all students");
            System.out.println("2 -> view all faculties");
            System.out.println("3 -> update student info");
            System.out.println("4 -> update faculty info");
            System.out.println("5 -> add new student");
            System.out.println("6 -> add new faculty");
            System.out.println("7 -> exit");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    for (Student s : students) {
                        System.out.println(s.toString() + "\n");
                    }
                    break;
                case 2:
                    for (Faculty f : faculties) {
                        System.out.println(f.toString() + "\n");
                    }
                    break;
                case 3:
                    System.out.println("Roll of students to update");
                    int roll = sc.nextInt();
                    Student curr = null;
                    for (int i = 0; i < students.size(); i++)
                        if (roll == students.get(i).getRoll()) {
                            curr = students.get(i);
                            break;
                        }
                    if(curr == null) continue;
                    System.out.println("1 -> update address");
                    System.out.println("2 -> update course");
                    int choice2 = sc.nextInt();
                    switch (choice2) {
                        case 1:
                            curr.setAddress(inputAddress(sc));
                            break;
                        case 2:
                            System.out.println("Enter new course");
                            String course = sc.next();
                            curr.setCourse(course);
                            break;
                        default:
                            break;
                    }
                    break;                
                case 4:
                    System.out.println("Enter id of faculty to update");
                    int id = sc.nextInt();
                    Faculty facCurr = null;
                    for (int i = 0; i < faculties.size(); i++)
                        if (id == faculties.get(i).getEmpId()) {
                            facCurr = faculties.get(i);
                            break;
                        }
                    if(facCurr == null) continue;
                    System.out.println("1 -> update department");
                    System.out.println("2 -> update sepcification");
                    System.out.println("3 -> update address");
                    int choice3 = sc.nextInt();
                    switch (choice3) {
                        case 1:
                            System.out.println("Enter new department");
                            String department = sc.next();
                            facCurr.setDept(department);
                            break;
                        case 2:
                            System.out.println("Enter new specification");
                            String specification = sc.next();
                            facCurr.setSpec(specification);
                            break;
                        case 3:
                            facCurr.setAddress(inputAddress(sc));
                    }
                    break;
                case 5:
                    System.out.println("Enter new Student information");
                    System.out.println("Enter name: ");
                    String name = sc.next();
                    System.out.println("Enter new course");
                    String course = sc.next();
                    System.out.println("Enter student roll");
                    int troll = sc.nextInt();
                    Student stud = new Student(name, inputAddress(sc), troll, course);
                    students.add(stud);
                    break;
                case 6:
                    System.out.println("Enter new Faculty information");
                    System.out.println("Enter new department");
                    String department = sc.next();
                    System.out.println("Enter new specification");
                    String specification = sc.next();
                    System.out.println("Enter name: ");
                    String ename = sc.next();
                    System.out.println("Enter Faculty id");
                    int eid = sc.nextInt();
                    Faculty fac = new Faculty(ename, inputAddress(sc), eid, department, specification);
                    faculties.add(fac);
                    break;
                case 7:
                    executed = false;
                default:
                    break;
    
            }
        }

        sc.close();
    }

    static Address inputAddress(Scanner sc) {
        System.out.println("Enter new address");
        System.out.println("Enter house number");
        int house = sc.nextInt();
        System.out.println("Enter new street");
        String street = sc.next();
        System.out.println("Enter new city");
        String city = sc.next();
        System.out.println("Enter new state");
        String state = sc.next();
        System.out.println("Enter new pincode");
        int pincode = sc.nextInt();
        Address address = new Address(house, street, city, state, pincode);
        return address;
    }


}
