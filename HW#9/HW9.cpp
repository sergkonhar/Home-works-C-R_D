#include <iostream>
#include "Functions.h"

int main()
{
	const int numArraySize = 3;
	int inputNumArray[numArraySize];
	std::cout << "Input your numbers (10 numbers): ";
	
	for (int i = 0; i < numArraySize; i++) 
	{
		std::cin >> inputNumArray[i];
	}
	
	intTransformer(inputNumArray, numArraySize);
	std::cout << "Result string: ";
	
	for (int i = 0; i < numArraySize; i++)
	{
		std::cout << inputNumArray[i] << " ";
	}

	std::cout << std::endl;
	std::cin.ignore(1000,'\n');
	std::cout << std::endl;
	
	const int stringLength = 100;
	char inputString[stringLength];
	std::cout << "Input your string (100 or less consecutive characters): ";
	std::cin >> inputString;
	
	stringCharUppercaser(inputString);
	std::cout << "Result string: " << inputString;
	std::cout << std::endl;
	std::cin.ignore(1000, '\n');
	std::cout << std::endl;
	
	const int palindromeLength = 100;
	bool palindrome;
	char palindromeString[palindromeLength];
	std::cout << "Input your word for polindrom check (100 or less consecutive characters): ";
	std::cin >> palindromeString;
	
	palindrome = isPalindrome(palindromeString);
	std::cout << std::boolalpha << "Is the string palindrome: " << palindrome;
	std::cout << std::endl;
	std::cout << std::endl;

	const int countStringLength = 100;
	int consonantCount = 0;
	int vowelCount = 0;
	char countString[countStringLength];
	std::cout << "Input your word consonant and vowel count (100 or less consecutive characters): ";
	std::cin >> countString;
	
	letterTypeConter(countString, consonantCount, vowelCount);
	std::cout << "Count of consonants: " << consonantCount << " Count of vowels: " << vowelCount;
	
	std::cout << std::endl;
	std::cout << std::endl;

	const int comparisonStringLength = 100;
	bool stringsEquality;
	char firstString[comparisonStringLength];
	char secondString[comparisonStringLength];
	std::cout << "Input first string (100 or less consecutive characters): ";
	std::cin >> firstString;
	std::cout << std::endl;
	std::cout << "Input second string (100 or less consecutive characters): ";
	std::cin >> secondString;

	stringsEquality = stringCompare(firstString, secondString);
	std::cout << std::boolalpha << "Strings are equal: " << stringsEquality;
}

