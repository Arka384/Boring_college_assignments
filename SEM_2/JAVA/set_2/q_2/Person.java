package q_2;

public class Person {
    private String name;
    private Address address;

    public Person(String name, Address address) {
        this.name = name;
        this.address = new Address(address);
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Address getAddress() {
        return address;
    }
    public void setAddress(Address address) {
        this.address.setHouseNum(address.getHouseNum());
        this.address.setStreet(address.getStreet());
        this.address.setCity(address.getCity());
        this.address.setState(address.getState());
        this.address.setPin(address.getPin());
    }

    @Override
    public String toString() {
        return "Person: name= " + name + ", \n" + address;
    }

}
