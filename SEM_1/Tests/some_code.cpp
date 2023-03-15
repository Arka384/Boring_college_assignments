#include <iostream>
#include <string>
#include <fstream>

class City {
private:
    std::string name;
    int maxTemp;
    int minTemp;
public:
    City() = default;
    City(std::string name, int maxTemp, int minTemp) {
        this->name = name;
        this->maxTemp = maxTemp;
        this->minTemp = minTemp;
    }
    std::string getName() { return this->name; }
    void writeInFile(std::ofstream& outStream) {
        outStream << this->name << "\n";
        outStream << this->maxTemp <<"\n";
        outStream << this->minTemp <<"\n";
    }
    void readFromFile(std::ifstream& inputStream) {
        inputStream >> this->name;
        inputStream >> this->maxTemp;
        inputStream >> this->minTemp;
    }
    friend std::istream& operator >> (std::istream& stream, City& obj);
    friend std::ostream& operator << (std::ostream& stream, const City& obj);
};
std::istream& operator >> (std::istream& stream, City& obj) {
    std::cout<<"\nEnter name: ";
    stream >> obj.name;
    std::cout<<"\nEnter max tmep: ";
    stream >> obj.maxTemp;
    std::cout<<"\nEnter min tmep: ";
    stream >> obj.minTemp;
    return stream;
}
std::ostream& operator << (std::ostream& stream, const City& obj) {
    std::cout<<"\nname: ";
    stream << obj.name;
    std::cout<<"\nMax temp: ";
    stream << obj.maxTemp;
    std::cout<<"\nMin temp: ";
    stream << obj.minTemp;
    return stream;
}

void sortAlpha(City* cities, int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size-i-1;j++)
            if(cities[j].getName() > cities[j+1].getName()) {
                City temp = cities[j];
                cities[j] = cities[j+1];
                cities[j+1] = temp;
            }
}

int main()
{
    int n = 1;
    City *cities = new City[10];

    //taking input
    std::cout<<"\nEnter number of records: ";
    std::cin>>n;
    std::cout<<"Enter city record\n";
    for(int i=0;i<n;i++) {
        std::cout<<"Enter "<<i+1<<" record:\n";
        std::cin>>cities[i];
    }
    
    //display for the first time
    std::cout<<"\nCity record are\n";
    for(int i=0;i<n;i++)
        std::cout<<cities[i];

    //sort and display
    sortAlpha(cities, n);
    std::cout<<"\nAfter sorting City record are\n";
    for(int i=0;i<n;i++)
        std::cout<<cities[i];

    //write into the file
    std::ofstream out("city_file.txt");
    for(int i=0;i<n;i++)
        cities[i].writeInFile(out);
    out.close();
    

    //laod from the file
    std::ifstream in("city_file.txt");
    for(int i=0;i<n;i++) {
        cities[i].readFromFile(in);
        std::cout<<cities[i];
    }
    in.close();

}
