package q_3.MemberList;

import java.util.ArrayList;

public class MemberList {
    ArrayList<Member> memberList = new ArrayList<Member>();

    public void addMember(Member m) {
        memberList.add(m);
        System.out.println("Member Added in the member list...");
    }

    public Member getMemberWithId(String id) {
        for(int i=0;i<memberList.size();i++) {
            Member mem = memberList.get(i);
            if(mem.mem_id.equals(id))
                return mem;
        }
        return null;
    }

    public boolean canIssue(String id) {
        Member obj = getMemberWithId(id);
        if(obj != null) {
            if(obj.booksIssued == Member.maxIssueAllowed)
                return false;
            else
                return true;
        }
        return false;
    }

    public void incrementIssued(String id) {
        Member obj = getMemberWithId(id);
        if(obj != null)
            obj.booksIssued++;
        else
            System.out.println("Member not found");
    }

    public void decrementIssued(String id) {
        Member obj = getMemberWithId(id);
        if(obj != null)
            obj.booksIssued--;
        else
            System.out.println("Member not found");
    }

    public void displayAllMembers() {
        if(memberList.size() == 0) {
            System.out.println("No member to Display...");
            return;
        }
        System.out.println("All member details:");
        for(int i=0;i<memberList.size();i++) {
            //member obj=ml.get(i);
            System.out.print("Member "+(i+1)+"=> ");
            System.out.println(memberList.get(i));
        }
    }

    public void displayMemberWithId(String id) {
        Member obj = getMemberWithId(id);
        if(obj != null)
            System.out.println(obj);
        else
            System.out.println("Member not found");
    }


}
