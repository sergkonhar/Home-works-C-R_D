#pragma once

#include <iostream>



void countValues(int numberOfInput) {

	double currentValue = 0;
	int counterPositive = 0;
	int counterNegative = 0;
	int counterZeroes = 0;

	std::cout << "Input numbers in row using spaces between them: ";


	for (int i = 1; i <= numberOfInput; i++) {

		std::cin >> currentValue;

		if (currentValue > 0)
		{
			counterPositive += 1;
		}
		else if (currentValue < 0)
		{
			counterNegative += 1;
		}
		else
		{
			counterZeroes += 1;
		}


	}

	std::cout << std::endl;
	std::cout << "Output " << "Positives: " << counterPositive << " Negatives: " << counterNegative << " Zeroes: " << counterZeroes;
}

void naturalNumbersCycleGrow(int count) {

	for (int i = 1; i <= count; i++) {
		std::cout << i << " ";
	
	}
}
void naturalNumbersCycleShrink(int count) {

	for (int i = count; i >= 1; i--) {
		std::cout << i << " ";

	}
}
