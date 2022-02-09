#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Vector.hpp"


/*
** Vector Test Start 
*/
template <class T>
void PrintVectorIterator(std::vector<T>& stdVec, ft::vector<T>& ftVec, std::ofstream& fout){
    fout << "| std vec | begin = " << *(stdVec.begin()) << " end = " << *(stdVec.end() - 1) << " rbegin = " << *(stdVec.rbegin()) << " rend = " << *(stdVec.rend() - 1) << std::endl;
    fout << "|  ft vec | begin = " << *(ftVec.begin()) << " end = " << *(ftVec.end() - 1) << " rbegin = " << *(ftVec.rbegin()) << " rend = " << *(ftVec.rend() - 1) << std::endl;
}

template <class T>
void PrintElement(std::vector<T>& stdVec, std::ofstream& fout){
    typename std::vector<T>::iterator stdIt = stdVec.begin();
    fout << " | vec element = ";
    for (; stdIt != stdVec.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
}

template <class T>
void PrintElement(ft::vector<T>& ftVec, std::ofstream& fout){
    typename ft::vector<T>::iterator ftIt = ftVec.begin();
    fout << " | vec element = ";
    for (; ftIt != ftVec.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
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
    fout << "|" << std::setw(46) << "Default Constructor" << std::setw(34) << "|" << std::endl;
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

    stdVecResize.resize(6);
    ftVecResize.resize(6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "resize case 5" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecResize, ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "empty" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | empty case = " << stdVecDefault.empty() << " | !empty case = " << stdVecResize.empty() << std::endl;
    fout << "|  ft vec | empty case = " << ftVecDefault.empty() << " | !empty case = " << ftVecResize.empty() << std::endl;

    stdVecResize.reserve(5);
    ftVecResize.reserve(5);
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
    fout << "| std vec | ";
    for(int i = 0; i < 5; i++){
        fout << "vec[" << i << "]=" << stdVecResize[i] << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | ";
    for(int i = 0; i < 5; i++){
        fout << "vec[" << i << "]=" << ftVecResize[i] << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case1" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    for(int i = 0; i < 5; i++){
        fout << "at[" << i << "]=" << stdVecResize.at(i) << " ";
    }
    fout << std::endl;
    fout << "|  ft vec | ";
    for(int i = 0; i < 5; i++){
        fout << "at[" << i << "]=" << ftVecResize.at(i) << " ";
    }
    fout << std::endl;

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "at case2" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | ";
    try {
        fout << stdVecResize.at(7);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }
    fout << "|  ft vec | ";
    try {
        fout << ftVecResize.at(7);
    }
    catch (std::exception& e){
        fout << e.what() << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "front" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | front = " << stdVecResize.front();
    PrintElement(stdVecResize, fout);
    fout << "|  ft vec | front = " << ftVecResize.front();
    PrintElement(ftVecResize, fout);

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "back" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | back = " << stdVecResize.back();
    PrintElement(stdVecResize, fout);
    fout << "|  ft vec | back = " << ftVecResize.back();
    PrintElement(ftVecResize, fout);

    std::vector<int> stdVecAssign;
    ft::vector<int> ftVecAssign;
    stdVecAssign.assign(stdVecResize.begin(), stdVecResize.end() - 1);
    ftVecAssign.assign(ftVecResize.begin(), ftVecResize.end() - 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(2, 6);
    ftVecAssign.assign(2, 6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(7, 1);
    ftVecAssign.assign(7, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    stdVecAssign.assign(0, 2);
    ftVecAssign.assign(0, 2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "assign case4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecAssign, ftVecAssign, fout);

    std::vector<int> stdVecPushback;
    ft::vector<int> ftVecPushback;
    for (int i = 0; i < 6; i++){
        if (i % 2 == 1){
            stdVecPushback.push_back(i);
            ftVecPushback.push_back(i);
        }
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "push_back case1" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPushback, ftVecPushback, fout);

    for (int i = 6; i < 10; i++){
        if (i % 2 == 1){
            stdVecPushback.push_back(i);
            ftVecPushback.push_back(i);
        }
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "push_back case2" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPushback, ftVecPushback, fout);

    std::vector<int> stdVecPopback(stdVecPushback);
    ft::vector<int> ftVecPopback(ftVecPushback);
    for (int i = 0; i < 2; i++){
        stdVecPopback.pop_back();
        ftVecPopback.pop_back();
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "pop_back case1" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPopback, ftVecPopback, fout);

    for (int i = 0; i < 2; i++){
        stdVecPopback.pop_back();
        ftVecPopback.pop_back();
    }
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(46) << "pop_back case2" << std::setw(34) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecPopback, ftVecPopback, fout);

    std::vector<int> stdVecInsert(1, 1);
    ft::vector<int> ftVecInsert(1, 1);
    stdVecInsert.insert(stdVecInsert.end(), 4);
    ftVecInsert.insert(ftVecInsert.end(), 4);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case1" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 0);
    ftVecInsert.insert(ftVecInsert.begin(), 0);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case2" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 2, -1);
    ftVecInsert.insert(ftVecInsert.begin(), 2, -1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case3" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin() + 4, 2, 2);
    ftVecInsert.insert(ftVecInsert.begin() + 4, 2, 2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case4" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.end(), 3, 5);
    ftVecInsert.insert(ftVecInsert.end(), 3, 5);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case5" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    std::vector<int> stdVecInsertTemp;
    ft::vector<int> ftVecInsertTemp;
    for (int i = 11; i < 16; i++){
        if (i % 2 == 1){
            stdVecInsertTemp.push_back(i);
            ftVecInsertTemp.push_back(i);
        }
    }
    stdVecInsert.insert(stdVecInsert.begin(), stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.begin(), ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case6" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin() + 7, stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.begin() + 7, ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case7" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.end(), stdVecInsertTemp.begin(), stdVecInsertTemp.end());
    ftVecInsert.insert(ftVecInsert.end(), ftVecInsertTemp.begin(), ftVecInsertTemp.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case8" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.insert(stdVecInsert.begin(), 50, 0);
    ftVecInsert.insert(ftVecInsert.begin(), 50, 0);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(45) << "insert case9" << std::setw(35) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin(), stdVecInsert.begin() + 50);
    ftVecInsert.erase(ftVecInsert.begin(), ftVecInsert.begin() + 50);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case1" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin() + 3, stdVecInsert.begin() + 6);
    ftVecInsert.erase(ftVecInsert.begin() + 3, ftVecInsert.begin() + 6);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case2" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.end() - 2, stdVecInsert.end());
    ftVecInsert.erase(ftVecInsert.end() - 2, ftVecInsert.end());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case3" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin());
    ftVecInsert.erase(ftVecInsert.begin());
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case4" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.begin() + 3);
    ftVecInsert.erase(ftVecInsert.begin() + 3);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case5" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    stdVecInsert.erase(stdVecInsert.end() - 1);
    ftVecInsert.erase(ftVecInsert.end() - 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "erase case6" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecInsert, ftVecInsert, fout);

    std::vector<int> stdVecSwap(5, 1);
    ft::vector<int> ftVecSwap(5, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "swap" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std before | size = " << stdVecSwap.size() << " | capacity = " << stdVecSwap.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecSwap.begin(); stdIt != stdVecSwap.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft before | size = " << ftVecSwap.size() << " | capacity = " << ftVecSwap.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecSwap.begin(); ftIt != ftVecSwap.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std insert | size = " << stdVecInsert.size() << " | capacity = " << stdVecInsert.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecInsert.begin(); stdIt != stdVecInsert.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft insert | size = " << ftVecInsert.size() << " | capacity = " << ftVecInsert.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecInsert.begin(); ftIt != ftVecInsert.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    stdVecSwap.swap(stdVecInsert);
    ftVecSwap.swap(ftVecInsert);
    fout << "| std after  | size = " << stdVecSwap.size() << " | capacity = " << stdVecSwap.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecSwap.begin(); stdIt != stdVecSwap.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft after  | size = " << ftVecSwap.size() << " | capacity = " << ftVecSwap.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecSwap.begin(); ftIt != ftVecSwap.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std insert | size = " << stdVecInsert.size() << " | capacity = " << stdVecInsert.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecInsert.begin(); stdIt != stdVecInsert.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft insert | size = " << ftVecInsert.size() << " | capacity = " << ftVecInsert.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecInsert.begin(); ftIt != ftVecInsert.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;

    stdVecSwap.clear();
    ftVecSwap.clear();
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(40) << "clear" << std::setw(40) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    PrintVector(stdVecSwap, ftVecSwap, fout);

    std::vector<int> stdVecNonMember1(5, 1);
    std::vector<int> stdVecNonMember2(5, 1);
    ft::vector<int> ftVecNonMember1(5, 1);
    ft::vector<int> ftVecNonMember2(5, 1);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator ==" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 == stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 == ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator !=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 != stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 != ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    stdVecNonMember2.push_back(2);
    ftVecNonMember2.push_back(2);
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator <" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 < stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 < ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator >" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 > stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 > ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator <=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 <= stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 <= ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(44) << "Operator >=" << std::setw(36) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std vec | result = ";
    if (stdVecNonMember1 >= stdVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }
    fout << "|  ft vec | result = ";
    if (ftVecNonMember1 >= ftVecNonMember2){
        fout << "true" << std::endl;
    }
    else {
        fout << "false" << std::endl;
    }

    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "|" << std::setw(42) << "ft::swap" << std::setw(38) << "|" << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout << "| std before | size = " << stdVecNonMember1.size() << " | capacity = " << stdVecNonMember1.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember1.begin(); stdIt != stdVecNonMember1.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft before | size = " << ftVecNonMember1.size() << " | capacity = " << ftVecNonMember1.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember1.begin(); ftIt != ftVecNonMember1.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std target | size = " << stdVecNonMember2.size() << " | capacity = " << stdVecNonMember2.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember2.begin(); stdIt != stdVecNonMember2.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft target | size = " << ftVecNonMember2.size() << " | capacity = " << ftVecNonMember2.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember2.begin(); ftIt != ftVecNonMember2.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    std::swap(stdVecNonMember1, stdVecNonMember2);
    ft::swap(ftVecNonMember1, ftVecNonMember2);
    fout << "| std after  | size = " << stdVecNonMember1.size() << " | capacity = " << stdVecNonMember1.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember1.begin(); stdIt != stdVecNonMember1.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft after  | size = " << ftVecNonMember1.size() << " | capacity = " << ftVecNonMember1.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember1.begin(); ftIt != ftVecNonMember1.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "| std target | size = " << stdVecNonMember2.size() << " | capacity = " << stdVecNonMember2.capacity() << " | element = ";
    for (std::vector<int>::iterator stdIt = stdVecNonMember2.begin(); stdIt != stdVecNonMember2.end(); stdIt++){
        fout << *(stdIt) << " ";
    }
    fout << std::endl;
    fout << "|  ft target | size = " << ftVecNonMember2.size() << " | capacity = " << ftVecNonMember2.capacity() << " | element = ";
    for (ft::vector<int>::iterator ftIt = ftVecNonMember2.begin(); ftIt != ftVecNonMember2.end(); ftIt++){
        fout << *(ftIt) << " ";
    }
    fout << std::endl;
    fout << "--------------------------------------------------------------------------------" << std::endl;
    fout.close();
}
/*
** Vector Test End
*/

int main(void){
    VectorTest();
    return (0);
}