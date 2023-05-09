package q_2;

public class Address {
    private int houseNum;
    private String street;
    private String city;
    private String state;
    private int pin;

    public Address(int houseNum, String street, String city, String state, int pin) {
        this.houseNum = houseNum;
        this.street = street;
        this.city = city;
        this.state = state;
        this.pin = pin;
    }
    public Address(Address other) {
        this.houseNum = other.houseNum;
        this.street = other.street;
        this.city = other.city;
        this.state = other.state;
        this.pin = other.pin;
    }

    public void setHouseNum(int houseNum) {
        this.houseNum = houseNum;
    }
    public void setStreet(String street) {
        this.street = street;
    }
    public void setCity(String city) {
        this.city = city;
    }
    public void setState(String state) {
        this.state = state;
    }
    public void setPin(int pin) {
        this.pin = pin;
    }

    public int getHouseNum() {
        return houseNum;
    }
    public String getStreet() {
        return street;
    }
    public String getCity() {
        return city;
    }
    public String getState() {
        return state;
    }
    public int getPin() {
        return pin;
    }
    @Override
    public String toString() {
        return "Address: houseNum= " + houseNum + ", street= " + street + ", city= " + city + ", state= " + state + ", pin= "
                + pin;
    }
    
}
