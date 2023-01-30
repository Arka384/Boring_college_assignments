#include <iostream>

class square {
private:
    int num;
public:
    square() {};
    square(int n) { this->num = n; }
    
    inline int findSquare() { return (num*num); }

};


int main()
{
    int n;
    std::cout<<"\nEnter a number: ";
    std::cin>>n;

    square s(n);
    std::cout<<"\nThe square of given number is: "<<s.findSquare();
}