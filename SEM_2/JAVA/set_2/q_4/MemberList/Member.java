package q_4.MemberList;

public class Member {
    String mem_id;
    String name;
    String dob;
    int booksIssued;
    static int maxIssueAllowed = 4;

    public Member(String mem_id, String name, String dob) {
        this.mem_id = mem_id;
        this.name = name;
        this.dob = dob;
        this.booksIssued = 0;
    }

    @Override
    public String toString() {
        return "Member [ mem_id = " + mem_id + ", name = " + name + ", dob = " + dob + ", booksIssued = " + booksIssued + " ]";
    }

}
