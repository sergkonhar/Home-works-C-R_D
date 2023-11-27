

#include <iostream>
#include "HW8HeaderRecursion.h"
#include "HW8HeaderCycles.h"

int main()
{
 
	int valuesToRead = 3;

	countValues(valuesToRead);
	
	
    int countForFactorial = 7;
	
    int resultFactorial = recurtionFactorial(countForFactorial);

	std::cout << "\nFactorial from recursion: " << resultFactorial;
	
	int resultCycle = cycleFactorial(countForFactorial);

	std::cout << "\nFactorial from cycle: " << resultCycle;
	
	
	int countForNaturalNumbers = 5;

	std::cout << "\nNatural numbers in recursion from smallest to biggest: ";
	naturalNumbersRecursionGrow(countForNaturalNumbers);

	std::cout << "\nNatural numbers in recursion from biggest to smallest: ";
	naturalNumbersRecursionShrink(countForNaturalNumbers);

	std::cout << "\nNatural numbers in cecle from smallest to biggest: ";
	naturalNumbersCycleGrow(countForNaturalNumbers);

	std::cout << "\nNatural numbers in cecle from biggest to smallest: ";
	naturalNumbersCycleShrink(countForNaturalNumbers);
}

