#pragma once
#include <iostream>

int recurtionFactorial(int count) {

	if (count <= 1) {
		return 1;
	}
	return count * recurtionFactorial(count - 1);
}



int cycleFactorial(int count) {

	int result = 1;

	for (int i = 2; i <= count; i++) {
		result *= i;
	}
	return result;
}

void naturalNumbersRecursionGrow(int count) {

	if (count == 0) {
		return ;
	}
	naturalNumbersRecursionGrow(count - 1);
	std::cout << count << " ";
}

void naturalNumbersRecursionShrink(int count) {

	if (count == 1) {
		std::cout << count << " ";
		return;
	}
	std::cout << count << " ";
	naturalNumbersRecursionShrink(count - 1);
}

