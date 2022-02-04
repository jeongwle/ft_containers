#include <vector>
#include <iostream>
#include <type_traits>

int main(void){
    std::vector<int> intVec;
    // std::vector<int> intVec2;
    // intVec.reserve(2);
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.push_back(4);
    intVec.push_back(5);
    // std::vector<int>::iterator erase2 = intVec.erase(intVec.begin() + 1, intVec.end() - 1);
    // std::cout << *(erase2) << std::endl;
    std::cout << "diff : " << (intVec.end() - 1) - (intVec.begin() + 1) << std::endl;
    // intVec.push_back(6);
    // std::cout << "diff : " << intVec.end() - (intVec.begin() + 2) - 1 << std::endl;
    // std::vector<int>::iterator erase = intVec.erase(intVec.begin() + 2);
    // std::cout << "erase = " << *(erase) << std::endl;
    // std::vector<int>::iterator insert = intVec.insert(intVec.begin()+ 1, 1, 2);
    // std::cout << "insert : " << *(insert) << std::endl;
    // intVec2.assign(intVec.begin(), intVec.end());
    // intVec.push_back(0);
    // intVec.push_back(0);
    std::cout << "size = " << intVec.size() << std::endl;
    std::cout << "capacity = " << intVec.capacity() << std::endl;
    // std::cout << "front = " << intVec.front() << std::endl;
    // std::cout << "back = " << intVec.back() << std::endl;
    // intVec.resize(3, 2);
    // std::cout << "size = " << intVec.size() << std::endl;
    // std::cout << "capacity = " << intVec.capacity() << std::endl;
    std::vector<int>::iterator it = intVec.begin();

    for (; it != intVec.end(); it++){
        std::cout << *(it) << std::endl;
    }
    // std::cout << *(intVec.end()) << std::endl;

}