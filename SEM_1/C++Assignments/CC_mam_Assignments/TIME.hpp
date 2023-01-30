#pragma once
#include <iostream>

class TIME {
private:
    int hour, min, sec;

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

};