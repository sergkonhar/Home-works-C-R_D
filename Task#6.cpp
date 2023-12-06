// Task#6: Home work 


#include <iostream>
#include <iomanip>





int main()
{
    

    // Task#6_1 

    std::cout << "\n\nTask#6_1\n\n";
    
    int startElement;
    int step;
    int endElementNumber;


    std::cout << "Input start element: ";
    std::cin >> startElement;
    std::cout << "\nInput step: ";
    std::cin >> step;
    std::cout << "\nInput end element number: ";
    std::cin >> endElementNumber;


    for (int i = 1; i <= endElementNumber; i++) {
    
        std::cout << startElement << std::endl;
        startElement += step;
    
    }


    // Task#6_2

    std::cout << "\n\nTask#6_2\n\n";
    int fibElementNumber;

    std::cout << "Input Fibonacci element number: ";
    std::cin >> fibElementNumber;

    const int firstElementFib = 0;
    const int secondElementFib = 1;
    const int thirdElementFib = 1;
    
    long long int previousElement;
    long long int currentElement;
    


    if (fibElementNumber == 1) {
        std::cout << firstElementFib;
    }
    else if (fibElementNumber == 2) {
        std::cout << secondElementFib;
    }
    else {

        previousElement = firstElementFib;
        currentElement = secondElementFib;


        for (int i = 3; i <= fibElementNumber; i++) {



            currentElement += previousElement;
            previousElement = (currentElement - previousElement);


            if (i == fibElementNumber) {
                std::cout << currentElement << std::endl;

            }

        }
    }
        
     



     // Task#6_3

     std::cout << "\n\nTask#6_3\n\n";
     int factorialNumber;

     std::cout << "Input number to calculate factorial: ";
     std::cin >> factorialNumber;

     long long int resultingFactorial = 1;

     if (factorialNumber <= 0) {
         std::cout << "Wrong number"<<std::endl;
     }

     else {

         for (int i = 1; i <= factorialNumber; i++) {

             resultingFactorial *= i;

             if (i == factorialNumber) {
                 std::cout << resultingFactorial << std::endl;
             }
         }


         // Task#6_4

         std::cout << "\n\nTask#6_4\n\n";
         int height;
         int width;

         std::cout << "Input height: ";
         std::cin >> height;
         std::cout << "Input width: ";
         std::cin >> width;
         
     
         for (int i = 1; i <= height; i++)
         {
             for (int j = width -i; j < width; j++) {
             
                 std::cout << "*";
             }
             std::cout << "\n";
         }

         std::cout << "\n";

         for (int i = 1; i <= height; i++)
         {
             for (int j = i; j <= width; j++) {

                 std::cout << "*";
             }
             std::cout << "\n";
         }
         std::cout << "\n";

         for (int i = 1; i <= height; i++)
         {
             for (int j = 1; j <= width; j++) {

                 std::cout << "*";
             }
             std::cout << "\n";
         }


         std::cout << "\n";
       

         for (int i = 1; i <= height; i++)
         {
             std::cout  << std::setw(i) ;
             
             for (int j = 1; j <= width; j++) {

                 std::cout << "*";
             }
             std::cout << "\n";
         }
       
         std::cout << "\n";
         bool outPutValue;

         for (int i = 1; i <= height; i++)
         {
             outPutValue = i % 2;

             for (int j = width-i; j < width; j++) {

                 std::cout << outPutValue;

                 outPutValue = !outPutValue;
                 
             }
             std::cout << "\n";
         }
         


         // Task#6_5

         std::cout << "\n\nTask#6_5\n\n";
         
         
         char inputChar;
         int outputSum =0;
         const char exitCondition = '.';
         
         while (true) {
         
             std::cout << "Input char: ";
             std::cin >> inputChar;

             if (inputChar== exitCondition)
             {
                 std::cout << "Programm is completed" << std::endl;
                 break;
             }
             else if (isalpha(inputChar)) {
                 if (isupper(inputChar)) {
                     continue;
                 }
                 else { 
                     std::cout << "Letter converted to upeprcase: " << static_cast<char>(toupper(inputChar)) << std::endl;
                     continue;
                 }
             }
             else if (isdigit(inputChar)) {
                 outputSum += static_cast<int>(inputChar-'0');
                 std::cout << "Summ of all values: " << outputSum << std::endl;
                 continue;
             }

             else {
                 std::cout << "Unsupported value"  << std::endl;
                 continue;
             }

         }
         
         


    }






}


