package q_2;

public class Faculty extends Person{
    private int empId;
    private String dept;
    private String spec;

    public Faculty(String name, Address address, int empId, String dept, String spec) {
        super(name, address);
        this.empId = empId;
        this.dept = dept;
        this.spec = spec;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }
    public void setSpec(String spec) {
        this.spec = spec;
    }

    public int getEmpId() {
        return empId;
    }

    public String getDept() {
        return dept;
    }

    public String getSpec() {
        return spec;
    }

    @Override
    public String toString() {
        return "Faculty: empId=" + empId + ", dept=" + dept + ", spec=" + spec + "\n" + super.toString();
    }

    
    
}
