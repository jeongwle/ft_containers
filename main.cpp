#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Vector.hpp"

template <class T>
void PrintVectorIterator(std::vector<T>& stdVec, ft::vector<T>& ftVec, std::ofstream& fout){
    fout << "| std vec | begin = " << *(stdVec.begin()) << " end = " << *(stdVec.end() - 1) << " rbegin = " << *(stdVec.rbegin()) << " rend = " << *(stdVec.rend() - 1) << std::endl;
    fout << "|  ft vec | begin = " << *(ftVec.begin()) << " end = " << *(ftVec.end() - 1) << " rbegin = " << *(ftVec.rbegin()) << " rend = " << *(ftVec.rend() - 1) << std::endl;
}

template <class T>
void PrintVector(std::vector<T>& stdVec, ft::vector<T>& ftVec, std::ofstream& fout){
    typename std::vector<T>::iterator stdIt = stdVec.begin();
    typename ft::vector<T>::iterator ftIt = ftVec.begin();
    fout << "| std vec | size = " << stdVec.size() << " | capacity = " << stdVec.capacity() << " | element = ";
    for (; stdIt != stdVec.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;

    fout << "|  ft vec | size = " << ftVec.size() << " | capacity = " << ftVec.capacity() << " | element = ";
    for (; ftIt != ftVec.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
}

void VectorTest(void){
    std::ofstream fout("VectorTest.log");

    std::vector<int> stdVecDefault;
    ft::vector<int> ftVecDefault;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(48) << "Default Constructor" << std::setw(32) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecDefault, ftVecDefault, fout);

    std::vector<int> stdVecFill(5, 5);
    ft::vector<int> ftVecFill(5, 5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Fill Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecFill, ftVecFill, fout);

    std::vector<int> stdVecRange(stdVecFill.begin() + 2, stdVecFill.end());
    ft::vector<int> ftVecRange(ftVecFill.begin() + 2, ftVecFill.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Range Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecRange, ftVecRange, fout);

    std::vector<int> stdVecCopy(stdVecRange);
    ft::vector<int> ftVecCopy(ftVecRange);
    stdVecCopy.push_back(7);
    ftVecCopy.push_back(7);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "Copy Constructor" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecCopy, ftVecCopy, fout);

    std::vector<int> stdVecOper;
    ft::vector<int> ftVecOper;
    stdVecOper = stdVecCopy;
    ftVecOper = ftVecCopy;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "Operator =" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecOper, ftVecOper, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(50) << "begin, end, rbegin, rend" << std::setw(30) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVectorIterator(stdVecOper, ftVecOper, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "max size" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | max size = " << stdVecOper.max_size() << std::endl;
    fout << "|  ft vec | max size = " << ftVecOper.max_size() << std::endl;

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> stdVecResize(arr, arr + 7);
    ft::vector<int> ftVecResize(arr, arr + 7);
    /* smaller than the current container size */
    stdVecResize.resize(5);
    ftVecResize.resize(5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container size */
    stdVecResize.resize(6);
    ftVecResize.resize(6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container capacity */
    stdVecResize.resize(8);
    ftVecResize.resize(8);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    /* greater than the current container capacity * 2 */
    stdVecResize.resize(30);
    ftVecResize.resize(30);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "empty" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | empty case = " << stdVecDefault.empty() << " | !empty case = " << stdVecResize.empty() << std::endl;
    fout << "|  ft vec | empty case = " << ftVecDefault.empty() << " | !empty case = " << ftVecResize.empty() << std::endl;

    stdVecResize.reserve(20);
    ftVecResize.reserve(20);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    stdVecResize.reserve(40);
    ftVecResize.reserve(40);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "reserve case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    try{
        stdVecResize.reserve(stdVecResize.max_size() + 1);
    }
    catch (std::exception& e){
        fout << "| std vec | ";
        fout << e.what() << std::endl;
    }
    try{
        ftVecResize.reserve(ftVecResize.max_size() + 1);
    }
    catch (std::exception& e){
        fout << "|  ft vec | ";
        fout << e.what() << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator []" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | Operator[] element = ";
    for(int i = 0; i < 5; i++){
        fout << stdVecResize[i] << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | Operator[] element = ";
    for(int i = 0; i < 5; i++){
        fout << ftVecResize[i] << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case1" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | at element = ";
    for(int i = 0; i < 5; i++){
        fout << stdVecResize.at(i) << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | at element = ";
    for(int i = 0; i < 5; i++){
        fout << ftVecResize.at(i) << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case2" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    try {
        fout << stdVecResize.at(30);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }
    fout << "|  ft vec | ";
    try {
        fout << ftVecResize.at(30);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }



















    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout.close();
}

int main(void){
    VectorTest();
    return (0);
}