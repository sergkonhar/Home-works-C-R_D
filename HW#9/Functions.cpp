
#include <iostream>


void  stringCharUppercaser(char inputChar[]) {

	int i = 0;

	while (inputChar[i] != '\0') {

		if (isalpha(inputChar[i])) {
			inputChar[i] = toupper(inputChar[i]);
			i++;
			continue;
		}
		else {
			inputChar[i] = inputChar[i];
			i++;
		}

	}

	std::cout << "Result string: " << inputChar;

}

void  intTransformer(int inputNum[],int length) {

	std::cout << "Result string: ";

	for (int i = 0; i < length; i++) 
	{
		if (inputNum[i] > 0) {
			inputNum[i] *= 2;
			std::cout << inputNum[i] << " ";
			continue;
		}
		else {
			inputNum[i] = 0;
			std::cout << inputNum[i] << " ";
		}

	}



	

}

bool isPalindrome(char palindromeArray[])
{

	
	for (int i = 0; i < strlen(palindromeArray); i++) {
	
		if (palindromeArray[i] != palindromeArray[(strlen(palindromeArray) - 1) - i]) {
			return false;
		}
	
		
	}
	return true;

}

void letterTypeConter(char inputArray[], int & consonantCount, int& vowelCount)

{
	char vovelArray[5] = { 'a','e','i','o','u' };

	for (int i = 0; i < strlen(inputArray); i++) {

		if (isalpha(inputArray[i])) {

			for (int j = 0; j < strlen(vovelArray); j++) {
				if (tolower(inputArray[i]) == vovelArray[j]) {
					vowelCount += 1;
					break;
				}
				else if (j == strlen(vovelArray) - 1) {
					consonantCount += 1;
				}

			}

		}
		

	}

}
bool stringCompare(char firstString[], char secondString[]) {

	if (strlen(firstString) == strlen(secondString)) {
		for (int i = 0; i < strlen(firstString); i++) {
			if (firstString[i] != secondString[i]) {
				return false;
			}

			else if (i == strlen(firstString) - 1) {
				return true;
			}
		}

	}
	else {
		return false;
	}



}