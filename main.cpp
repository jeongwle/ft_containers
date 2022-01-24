#include <vector>
#include <iostream>

int main(void){
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(1);
    intVec.push_back(1);
    intVec.push_back(1);
    intVec.push_back(1);
    std::cout << intVec.capacity() << std::endl;
    std::cout << intVec.size() << std::endl;
}