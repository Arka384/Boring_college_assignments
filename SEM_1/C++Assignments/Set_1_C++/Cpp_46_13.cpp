#include <iostream>

class TIME {
private:
    int hour, min, sec;

    int update(int *val) {
        if(*val > 59) {
            *val = *val - 60;
            return 1;
        }
        return 0;
    }

public:
    TIME() {}
    TIME(int hour, int min, int sec) {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    friend std::ostream& operator << (std::ostream& out, const TIME& time) {
        out << time.hour << ":" << time.min << ":" << time.sec;
        return out;
    }

    friend std::istream& operator >> (std::istream& in, TIME& time) {
        std::cout<<"\nEnter time in hour min second: ";
        in >> time.hour;
        in >> time.min;
        in >> time.sec;
        return in;
    }

    TIME operator + (const TIME& t) {
        TIME temp;
        int c = 0;
        temp.sec = this->sec + t.sec;
        c = update(&temp.sec);
        temp.min = this->min + t.min + c;
        c = update(&temp.min);
        temp.hour = this->hour + t.hour + c;
        return temp;
    }

    bool operator == (const TIME& t) {
        if(this->hour == t.hour && 
            this->min == t.min && 
            this->sec == t.sec)
            return true;
        return false;
    }

};



int main()
{
    TIME t1, t2;
    std::cin >> t1 >> t2;
    std::cout << "\nThe given two times are " << ((t1 == t2) ? "" : "NOT ") << "Equal"; 
    TIME t3 = t1 + t2;
    std::cout << "\nAfter adding (" << t1 << ") and (" << t2 << ") the added time is: " << t3;
    
}