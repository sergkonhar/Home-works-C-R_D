#include <iostream>



void swapTwoValues(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void swapTwoValuesReference(int* pointerToA, int* pointerTob) {
	*pointerToA ^= *pointerTob;
	*pointerTob ^= *pointerToA;
	*pointerToA ^= *pointerTob;

}

bool arrayChecker(int* numArr, int arrSize, int& arrSum) {

	if (arrSize > 0) {
		for (int i = 0; i < arrSize; i++)
		{
			arrSum += numArr[i];
		}
		return true;
	}
	return false;
}


bool searchValue(int* numArr, int arrSize, int searchValue) {

	for (int i = 0; i < arrSize; i++)
	{
		if (*(numArr + i) == searchValue) {
			return true;
		}
	}

	return false;
}


int main()
{
	int a = 10;
	int b = 15;
	int* pointerToA = &a;
	int* pointerTob = &b;


	swapTwoValues(a, b);
	std::cout << "Function result with references " << "Value of A: " << a << " Value of B: " << b << std::endl;

	swapTwoValuesReference(pointerToA, pointerTob);
	std::cout << "Function result with references " << "Value of A: " << *pointerToA << " Value of B: " << *pointerTob << std::endl;

	const int arraySize = 5;
	int numArray[arraySize] = { 1,4,6,8,9 };
	int arraySum = 0;




	bool arrayCheckResult = arrayChecker(numArray, arraySize, arraySum);
	std::cout << std::boolalpha << "Array is no null: " << arrayCheckResult << "; Sum of all elements: " << arraySum << std::endl;

	const int arrayForSearchSize = 5;
	int searchArray[arrayForSearchSize] = { 12,41,65,82,29 };
	int numberForSearch = 41;

	bool searchResult = searchValue(searchArray, arrayForSearchSize, numberForSearch);
	std::cout << std::boolalpha << "Array contains the value: " << searchResult << std::endl;

}

