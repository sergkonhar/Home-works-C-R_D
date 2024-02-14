#include <iostream>
#include "Array.h"

int main()
{
    DynamicArray<int> testArray;
    DynamicArray<int> testArray1;
    testArray.push_back(11);
    testArray.push_back(12);
    testArray.push_back(77);

    std::cout << testArray[0] << std::endl;
    std::cout << testArray[1] << std::endl;
    std::cout << testArray[2] << std::endl;

    std::cout << "Size: " << testArray.getSize() << std::endl;

    testArray1 = testArray;
    
    testArray1.reserve(100);
    std::cout << std::endl;
    std::cout << testArray1[0] << std::endl;
    std::cout << testArray1[1] << std::endl;
    std::cout << testArray1[2] << std::endl;

    std::cout << "Size: " << testArray1.getSize() << std::endl;

    testArray.clear();
}


