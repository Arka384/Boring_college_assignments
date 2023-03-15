#include <iostream>
#include <fstream>
#include <string>
//#define NORMAL_MODE
#define BINARY_MODE

#ifdef BINARY_MODE
class temp {
    std::string name;
    int marks;
public:
    temp() = default;
    temp(const std::string& name, const int& marks) {
        this->marks = marks;
        this->name = name;
    }
    void show() {
        std::cout<<name<<"\n";
        std::cout<<marks<<std::endl;
    }
};
#endif

int main()
{
#ifdef NORMAL_MODE
    std::string line;
    //lets write into file
    std::ofstream output("normal_text.txt");
    output << "hello world";
    output.close();

    //lets read from file
    std::ifstream input("normal_text.txt");
    while(std::getline(input, line)) {
        std::cout<<line<<"\n";
    }
    input.close();
#endif

#ifdef BINARY_MODE
    //writing a binary file
    std::ofstream outBin("binary_text.bin", std::ios::out | std::ios::binary);
    temp a("Arka Das",90);
    outBin.write((char *)&a, sizeof(temp));
    outBin.close();

    //read from binary file
    std::ifstream inBin("binary_text.bin", std::ios::binary);
    temp b;
    inBin.read((char *)&b, sizeof(temp));
    b.show();
    inBin.close();

#endif
}

