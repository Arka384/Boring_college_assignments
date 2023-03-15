#include <iostream>
#include <string>

template<typename T, int N> class Bubble {
    T *a;
public:
    Bubble() = default;
    Bubble(T* b);
    void sort();
    void display(void);
    T getMedian(void);
};
template<typename T, int N> Bubble<T, N>::Bubble(T* b) {
    a = b;
}
template<typename T, int N> void Bubble<T, N>::display() {
    for(int i=0;i<N;i++)
        std::cout<<a[i]<<" ";
    std::cout<<"\n";
}
template<typename T, int N> void Bubble<T, N>::sort() {
    for(int i=0;i<N;i++)
        for(int j=0;j<N-i-1;j++)
            if(a[j] > a[j+1]) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}
template<typename T, int N> T Bubble<T, N>::getMedian() {
    if(N%2 != 0)  //odd size
        return a[N/2];
    else
        return (a[N/2] + a[N/2-1])/2;
}

int main() {
    int intArr[] = {2,3,1,5,4,6};
    float floatArr[] = {1.5,2.6,7.89,1.056,2.65,6.45};
    char charArr[] = {'c', 'x', 'a', 'p', 't', 'd'};
    // std::string stringArr[] = {"hello", "arka", "world", "noicee", "daymn"};
    Bubble<int, 6> o1(intArr);
    Bubble<float, 6> o2(floatArr);
    Bubble<char, 6> o3(charArr);
    // Bubble<std::string, 5> o4(stringArr);

    o1.sort();
    std::cout<<o1.getMedian()<<std::endl;
    o1.display();
    o2.sort();
    std::cout<<o2.getMedian()<<std::endl;
    o2.display();
    o3.sort();
    std::cout<<o3.getMedian()<<std::endl;
    o3.display();
    // o4.sort();
    // o4.display();
}