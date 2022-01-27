#include <vector>
#include <iostream>
#include <type_traits>

int main(void){
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.push_back(4);
    intVec.push_back(5);
    // std::cout << intVec.capacity() << std::endl;
    // std::cout << intVec.size() << std::endl;
    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    std::vector<int>::iterator it3;
    it1 = intVec.begin() + 1;
    it2 = intVec.end() - 1;
    std::cout << it1[-1] << std::endl;
    std::is_integral<int>
}