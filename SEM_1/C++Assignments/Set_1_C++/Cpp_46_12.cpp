#include <iostream>
#include <cstring>

class String {
private:
    char *str;
public:
    String() {}
    String(const char* s) {
        str = new char[strlen(s)];
        strcpy(str, s);
    }
    void show() {
        std::cout<<str;
    }

    String operator+(const String& s) {
        String temp;
        temp.str = new char[(strlen(this->str) + strlen(s.str))];
        strcpy(temp.str, this->str);
        strcat(temp.str, s.str);
        return temp;
    }

    void reverse() {
        int i=0, j=strlen(this->str)-1;
        while(i < j) {
            char c = this->str[i];
            this->str[i] = this->str[j];
            this->str[j] = c;
            i++;
            j--;
        }
    }

};

int main()
{
    String t1("hello");
    std::cout<<"\nFirst string is: ";
    t1.show();
    
    String t2(" world");
    std::cout<<"\nSecond string is: ";
    t2.show();

    std::cout<<"\nAfter joining the strings: ";
    String t3 = t1 + t2;    
    t3.show();
    std::cout<<"\nReversed: ";
    t3.reverse();
    t3.show();
}