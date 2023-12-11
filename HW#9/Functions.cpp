#include <iostream>
#include <cmath>

void  stringCharUppercaser(char inputChar[]) 
{
	int i = 0;
	while (inputChar[i] != '\0') 
	{
			inputChar[i] = toupper(inputChar[i]);
			i++;
	}
}

void  intTransformer(int inputNum[],int length) 
{
	for (int i = 0; i < length; i++) 
	{
		if (inputNum[i] > 0) {
			inputNum[i] *= 2;
		}
		else {
			inputNum[i] = 0;
		}
	}
}

bool isPalindrome(char palindromeArray[])
{
	int fullStrLength = strlen(palindromeArray);
	int halfStrLength = std::ceil(fullStrLength / 2.f)-1;
	for (int i = 0; i <= halfStrLength; i++)
	{
		if (palindromeArray[i] != palindromeArray[(fullStrLength - 1) - i]) {
			return false;
		}
	}
	return true;
}

void letterTypeConter(char inputArray[], int & consonantCount, int & vowelCount)
{
	char vovelArray[5] = { 'a','e','i','o','u' };

	for (int i = 0; i < strlen(inputArray); i++) 
	{
		if (isalpha(inputArray[i]))
		{
			for (int j = 0; j < 5; j++)
			{
				if (tolower(inputArray[i]) == vovelArray[j]) 
				{
					vowelCount += 1;
					break;
				}
				else if (j == 4) 
				{
					consonantCount += 1;
				}
			}
		}
	}
}
bool stringCompare(char firstString[], char secondString[]) {

	if (strlen(firstString) != strlen(secondString)) 
	{
		return false;
	}
	
	for (int i = 0; i < strlen(firstString); i++) 
	{
		if (firstString[i] != secondString[i]) 
		{
			return false;
		}
	}
	return true;
}