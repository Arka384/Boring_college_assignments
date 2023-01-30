#include <iostream>

int calculate(const int& n, const char& c) {
    if(c == 'r') {  //reverse
        int reversedNum = 0;
        int temp = n;
        while(temp != 0) {
            reversedNum = (reversedNum*10) + (temp%10);
            temp /= 10;
        }
        return reversedNum;
    }
    else if(c == 'p') { //check prime
        int c = 0;
        for(int i=1;i<=n;i++) {
            if(n%i == 0) c++;
        }
        return (c == 2) ? 1 : 0;
    }
    return -1;
}

int main()
{
    std::cout<<"Reversed Number: "<<calculate(123,'r')<<"\n";

    std::cout<<(calculate(29,'p') ? "Is " : "Is Not " )<<"a prime number";

}