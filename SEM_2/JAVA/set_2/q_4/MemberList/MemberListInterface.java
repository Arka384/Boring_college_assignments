package q_4.MemberList;

public interface MemberListInterface {
    public void addMember(Member m);
    public Member getMemberWithId(String id);
    public boolean canIssue(String id);
    public void incrementIssued(String id);
    public void decrementIssued(String id);
    public void displayAllMembers();
    public void displayMemberWithId(String id);
}
