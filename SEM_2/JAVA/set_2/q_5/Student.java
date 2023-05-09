package q_5;

public class Student {
    private int roll;
    private int score;

    Student() {}

    public int getRoll() {
        return roll;
    }
    public void setRoll(int roll) {
        this.roll = roll;
    }

    public int getScore() {
        return score;
    }
    public void setScore(int score) throws InvalidScoreException {
        if(score < 0 || score > 100)
            throw new InvalidScoreException("Exception: Invalid Score");
        this.score = score;
    }

    @Override
    public String toString() {
        return "Student [roll = " + roll + ", score = " + score + "]";
    }
    
    
}
