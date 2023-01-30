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
        std::cout<<str<<"\n";
    }
    void join(String& s1, String& s2) {
        str = new char[(strlen(s1.str) + strlen(s2.str))];
        strcpy(str, s1.str);
        strcat(str, s2.str);
    }
};

int main()
{
    String t1("hello");
    t1.show();
    String t2(" world");
    t2.show();

    String t3;
    t3.join(t1, t2);
    t3.show();

}