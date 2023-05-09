package q_5;

public class InvalidScoreException extends Exception {
    // public InvalidScoreException(String message) {
    //     super(message);
    // }
    
    String message;
    public InvalidScoreException(String message) {
        this.message = message;
    }
    public String toString() {
        return message;
    }
}
