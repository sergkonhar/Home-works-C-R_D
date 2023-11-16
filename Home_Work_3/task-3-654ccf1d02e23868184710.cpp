// Task#3_1/2/3/4/5.cpp : Home work 


#include <iostream>
#include <iomanip>




int main()
{


    // Task#3_1 

    std::cout << "\n\nTask#3_1\n\n";
    int inputSeconds;
    std::cout << "Seconds Input " ;
    std::cin >> inputSeconds;

    int hours = inputSeconds / 3600;
    int minutes =  (inputSeconds / 60) - (hours * 60);
    int seconds = inputSeconds - (hours * 3600 + minutes * 60);



    std::cout << "Result Time\n"  << hours << " Hours, " << minutes << " Minutes, " << seconds << " Seconds " ;



    // Task#3_2

    std::cout << "\n\nTask#3_2\n\n";
    int numberOne;
    int numberTwo;
    int numberThree;
    std::cout << "Input number one: ";
    std::cin >> numberOne;
    std::cout << "\n";
    std::cout << "Input number two: ";
    std::cin >> numberTwo;
    std::cout << "\n";
    std::cout << "Input number three: ";
    std::cin >> numberThree;
    std::cout << "\n";

    int sum = numberOne + numberTwo + numberThree;
    int multiply = numberOne * numberTwo * numberThree;
    float avarage = (static_cast<float>(numberOne) + numberTwo + numberThree) / 3;
    bool compareFirestWithSecond = numberOne > numberTwo;
    bool compareSecondWithThird = numberTwo > numberThree;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << multiply << std::endl;
    std::cout << "Avarage: " << avarage << std::endl;
    std::cout << "Comparison first with second: " << std::boolalpha << compareFirestWithSecond << std::endl;
    std::cout << "Comparison second  with third: " << std::boolalpha << compareSecondWithThird << std::endl;



    // Task#3_3

    std::cout << "\n\nTask#3_3\n\n";

    int numberOneTask3;
    int numberTwoTask3;
  
    std::cout << "Input number one: ";
    std::cin >> numberOneTask3;
    std::cout << "\n";
    std::cout << "Input number two: ";
    std::cin >> numberTwoTask3;
    std::cout << "\n";

    bool lessThan = numberOneTask3 < numberTwoTask3;
    bool equal = numberOneTask3 == numberTwoTask3;
    bool moreThan = numberOneTask3 > numberTwoTask3;
    bool lessOrEqual = numberOneTask3 <= numberTwoTask3;


    std::cout << "First less than second numeric form: " << std::noboolalpha << lessThan << "    First less than second alphabetic form: " << std::boolalpha << lessThan << std::endl;
    std::cout << "First equal second numeric form: " << std::noboolalpha << equal << "    First equal second alphabetic form: " << std::boolalpha << equal << std::endl;
    std::cout << "First more than second numeric form: " << std::noboolalpha << moreThan << "    First more than second alphabetic form: " << std::boolalpha << moreThan << std::endl;
    std::cout << "First less than or equal second numeric form: " << std::noboolalpha << lessOrEqual << "    First less than or equal second alphabetic form: " << std::boolalpha << lessOrEqual << std::endl;


    // Task#3_4

    std::cout << "\n\nTask#3_4\n\n";
    int width;
    int height;

    std::cout << "Input width: ";
    std::cin >> width;
    std::cout << "\n";
    std::cout << "Input height: ";
    std::cin >> height;
    std::cout << "\n";

    int area = width * height;
    int perimeter = 2*width + 2*height;
    

    std::cout << "Area: "  << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    // Task#3_5

    std::cout << "\n\nTask#3_5\n\n";

    int radius;

    std::cout << "Input radius: ";
    std::cin >> radius;

    float pi = 3.14;

    float circleArea = pi * (radius^2);
    float arcLength = 2* pi * radius;


    std::cout << "Circle area: " << circleArea << std::endl;
    std::cout << "Arc length: " << arcLength << std::endl;



}


