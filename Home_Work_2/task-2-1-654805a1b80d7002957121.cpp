// Task#2_1/2/3/4/5.cpp : Home work 


#include <iostream>
#include <iomanip>

enum Week {
    Mon = 1,
    Tue =2,
    Wed = 3,
    Thu =4,
    Fri = 5,
    Sat = 6,
    Sun =7

};

int main()
{
   
    // Task#2_1 
    


    int firstNumber;
    int secondNumber;

    std::cout << "Task#2_1 \n\n";

    std::cout << "Enter first number ";

    std::cin >> firstNumber;

    std::cout << "Enter second number ";

    std::cin >> secondNumber;

    firstNumber ^= secondNumber;

    secondNumber ^= firstNumber;

    firstNumber ^= secondNumber;

    std::cout << "First number "<< firstNumber << "\n" << "Second number " << secondNumber;
    std::resetiosflags;

    // Task#2_2

    std::cout <<  "\n\nTask#2_2 \n\n";

    double dNumber = 7.789;
    int doubleToInt = int(dNumber);
    std::cout << "\n" << "double " << dNumber << std::endl;
    std::cout  << "double casted to int " << doubleToInt << std::endl;
    std::cout << std::right << std::setw(20) << std::setfill('$') << dNumber << std::endl;
    std::resetiosflags;


    // Task#2_3
    
    std::cout << "\n\nTask#2_3 \n\n";

    double dNumber1 = 349.757890755778;
    std::cout << "double " << dNumber1 << std::endl;
    std::cout << "precision 3 " << std::setprecision(3) << dNumber1  << std::endl;
    std::cout << "precision 5 " << std::setprecision(5) << dNumber1  << std::endl;
    std::cout << "precision 10 " << std::setprecision(10)  << dNumber1  << std::endl;
    std::cout << "standart notation " << std::fixed << dNumber1 << std::endl;
    std::cout << "e notation " << std::scientific << dNumber1 << std::endl;
    std::resetiosflags;
    
    // Task#2_4

    std::cout << "\n\nTask#2_4 \n\n";

    for (int i = Week::Mon; i <= Week::Sun; i++) {
        std::cout << static_cast<int>(i) << std::endl;
    }
    std::resetiosflags;


    // Task#2_5

    std::cout << "\n\nTask#2_4 \n\n";

    int num1;
    
    std::cin >> num1;

    bool boolVal = bool(num1);

    std::cout << "bool value is " << std::boolalpha << boolVal << std::endl;


    std::resetiosflags;

}


