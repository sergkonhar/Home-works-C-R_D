// Task#4_1/2/3/4/5/6 : Home work 


#include <iostream>
#include <iomanip>

enum class Months {
    Jan=1,
    Feb=2,
    Mar=3,
    Apr=4,
    May=5,
    Jun=6,
    Jul=7,
    Aug=8,
    Sep=9,
    Oct=10,
    Nov=11,
    Dec=12
};



int main()
{
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    Months inputMonth;

    // Task#4_1 

    std::cout << "\n\nTask#4_1\n\n";
    
    

    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "\n Enter second number: ";
    std::cin >> secondNumber;
    std::cout << "\n Enter third number: ";
    std::cin >> thirdNumber;
    int inputNumbers[3] = { firstNumber , secondNumber , thirdNumber };
    int N = sizeof(inputNumbers) / sizeof(inputNumbers[0]);


    for (int i = 0; i < N-1;i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (inputNumbers[j] > inputNumbers[j + 1]) {
                inputNumbers[j] ^= inputNumbers[j + 1];
                inputNumbers[j + 1] ^= inputNumbers[j];
                inputNumbers[j] ^= inputNumbers[j + 1];
            
            }
        }
    }
  

    
    std::cout << "\n Greatest number is:  " << inputNumbers[N-1] << std::endl;



    // Task#4_2

    std::cout << "\n\nTask#4_2\n\n";

    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "\n Enter second number: ";
    std::cin >> secondNumber;

    bool firstIsLesser = firstNumber < secondNumber;
    bool equal = firstNumber == secondNumber;
    std::string result;

    result = firstIsLesser ? "\n First is lesser than second" : (equal ? "\n Numbers are equal": "\n Second is lesser than first");

    std::cout << result;


    // Task#4_3

    std::cout << "\n\nTask#4_3\n\n";
    std::cout << "Enter number for evaluation: ";
    std::cin >> firstNumber;

    bool dividableByFive = !(firstNumber % 5);
    bool dividableByElevent = !(firstNumber % 11);

    if (dividableByFive && dividableByElevent) {
        std::cout << "\n Number is divadable by 5 and 11";
    }

    else if (dividableByFive && !dividableByElevent) {
        std::cout << "\n Number is divadable by 5";
    }
    else if (!dividableByFive && dividableByElevent) {
        std::cout << "\n Number is divadable by 11";
    }

    else {
        std::cout << "\n Number is not divadable by 5 or 11";
    }



    // Task#4_4

    std::cout << "\n\nTask#4_4\n\n";

    std::cout << "Enter first angle in degrees: ";
    std::cin >> firstNumber;
    std::cout << "\n Enter second angle in degrees: ";
    std::cin >> secondNumber;
    std::cout << "\n Enter third angle in degrees: ";
    std::cin >> thirdNumber;

    int anglesSum = firstNumber + secondNumber + thirdNumber;
    const int triangleAngles = 180;

    if (anglesSum == triangleAngles) {
        std::cout << "\n It's triangle";
    }

    else {
        std::cout << "\n It's not triangle";
    }



    // Task#4_5

    std::cout << "\n\nTask#4_5\n\n";

    std::cout << "Enter month value from 1 to 12: ";
    std::cin >> firstNumber;

    inputMonth = static_cast<Months>(firstNumber);

    switch (inputMonth)
    {
    case Months::Jan:
        std::cout << "\n Jan";
        break;
    case Months::Feb:
        std::cout << "\n Feb";
        break;
    case Months::Mar:
        std::cout << "\n Mar";
        break;
    case Months::Apr:
        std::cout << "\n Apr";
        break;
    
    case Months::May:
        std::cout << "\n May";
        break;

    case Months::Jun:
        std::cout << "\n Jun";
        break;

    case Months::Jul:
        std::cout << "\n Jul";
        break;

    case Months::Aug:
        std::cout << "\n Aug";
        break;

    case Months::Sep:
        std::cout << "\n Sep";
        break;

    case Months::Oct:
        std::cout << "\n Oct";
        break;

    case Months::Nov:
        std::cout << "\n Nov";
        break;
    
    case Months::Dec:
        std::cout << "\n Dec";
        break;
    
    default:
        std::cout << "\n Wrong Value";
    
    
    }

    
    // Task#4_6

    std::cout << "\n\nTask#4_6\n\n";

    std::cout << "Enter month value from 1 to 12: ";
    std::cin >> firstNumber;

    inputMonth = static_cast<Months>(firstNumber);

    switch (inputMonth)
    {
    case Months::Jan:
    case Months::Feb:
    case Months::Dec:
        std::cout << "\n Winter";
        break;
    case Months::Mar:
    case Months::Apr:
    case Months::May:
        std::cout << "\n Spring";
        break;

    case Months::Jun:
    case Months::Jul:
    case Months::Aug:
        std::cout << "\n Summer";
        break;

    case Months::Sep:
    case Months::Oct:
    case Months::Nov:
        std::cout << "\n Autumn";
        break;

    default:
        std::cout << "\n Wrong Value";


    }



}


