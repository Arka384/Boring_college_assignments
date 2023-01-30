#include <iostream>

class YearCheck {
private:
    bool isLeapYear;
    int year;
public:
    YearCheck() {};
    YearCheck(int year) {
        this->isLeapYear = false;
        this->year = year;
        if(year%4 == 0 && year%100 == 0 && year%400 == 0)
            isLeapYear = true;
    }
    ~YearCheck() {
        (isLeapYear == true) ? std::cout<<"\n"<<year<<" is a leap year" : std::cout<<"\n"<<year<<" is NOT a leap year";
    }
};

int main()
{
    YearCheck y1(1900);
    YearCheck y2(1992);
    YearCheck y3(1600);
    YearCheck y4(2400);
}