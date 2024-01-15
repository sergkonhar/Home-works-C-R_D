#include "Vector.h"
#include <iostream>

int main()
{
    Vector2d firstVector(12.2f, 41.9f);
    Vector2d secondVector(2.2f, 1.9f);
    Vector2d thirdVector;

    Vector2d testVectorOne = firstVector - secondVector;
    std::cout << testVectorOne() <<std::endl;
   

    std::cin >> thirdVector;
    std::cout << std::endl;
    std::cout << thirdVector << std::endl;
    std::cout << std::endl;
  
    Vector2d testVectorTwo = firstVector + secondVector;
    std::cout << testVectorTwo() << std::endl;

    std::cout << "Vector 2d instances: " << Vector2d::getInstanceCount() << std::endl;
}

