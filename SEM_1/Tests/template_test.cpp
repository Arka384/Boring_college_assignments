#include <iostream>

class Vector2i {
public:
    int x, y;
    Vector2i(int a, int b) { x = a, y = b; }
    friend std::ostream& operator << (std::ofstream& stream, const Vector2i& obj);
};
std::ostream& operator << (std::ostream& stream, const Vector2i& obj) {
    stream << obj.x << " " <<obj.y;
    return stream;
}

template<typename T>
void function(T a) {
    std::cout<<a<<std::endl;
}
void function(int a) {
    std::cout<<"integer version: "<<a<<std::endl;
}

template<typename T1, typename T2>
void function(T1 a, T2 b) {
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
} 

int main()
{
    // function(10);
    // function(15.565);
    // function("hello world");
    // function(10);   //calls the integer version

    // function(Vector2i(5,6), 10);
    // function(Vector2i(2,3), "hello world");

}