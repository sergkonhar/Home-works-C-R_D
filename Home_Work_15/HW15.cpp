#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>

const int amountOfRates = 4;
const int maxSumOfRates = 20;
const int amountOfStudents = 5;
const float rateTreshold = 0.75 * (static_cast<float>(maxSumOfRates) / amountOfRates);

struct Student
{
	std::string name;
	int rates[amountOfRates];
};

float averegeRateOfStudent(const Student& studentToClaculate);

bool sortByAvarageRate(const Student& firstStudent, const Student& secondStudent);

void printStudent(Student currenStudent);

Student* findBest(Student arrayOfStudents[amountOfStudents], const int amountOfStudents);

int sumStudentsPassedTreshold(Student arrayOfStudents[amountOfStudents], const int amountOfStudents, const float rateTreshold);

int main()
{
	Student firstStudent = { "Dwight",{4,5,3,5} };
	float studentAverageRates = averegeRateOfStudent(firstStudent);

	std::cout << "Avarage rate is: " << studentAverageRates << std::endl << std::endl;

	Student arrayOfStudents[amountOfStudents] = { {"Dwight",{4,5,3,5}} , {"Meg", {5,5,5,5}}, {"Bill", {5,5,5,5}}, {"Steve", {5,3,3,2}}, {"Nancy", {1,3,4,5}} };

	std::sort(std::begin(arrayOfStudents), std::end(arrayOfStudents), sortByAvarageRate);

	for (int i = 0; i < std::size(arrayOfStudents); i++)
	{
		printStudent(arrayOfStudents[i]);
	}

	Student* ptrToBestStudent = findBest(arrayOfStudents, amountOfStudents);
	std::cout << std::endl << "Best Student => ";
	printStudent(*ptrToBestStudent);

	int passedTreshold = sumStudentsPassedTreshold(arrayOfStudents, amountOfStudents, rateTreshold);
	std::cout << std::endl << "Number of students which pass over 75% avarage rate: " << passedTreshold << std::endl;

}

float averegeRateOfStudent(const Student& studentToClaculate)
{
	float averageRate = 0;
	for (int i = 0; i < std::size(studentToClaculate.rates); i++)
	{
		averageRate += studentToClaculate.rates[i];
	}

	averageRate /= static_cast<float>(std::size(studentToClaculate.rates));

	return averageRate;
}

bool sortByAvarageRate(const Student& firstStudent, const Student& secondStudent)
{
	float avarageRateFirstStudent = 0;
	float avarageRateSecondStudent = 0;

	for (int i = 0; i < std::size(firstStudent.rates); i++)
	{
		avarageRateFirstStudent += firstStudent.rates[i];
	}

	avarageRateFirstStudent /= static_cast<float>(std::size(firstStudent.rates));

	for (int i = 0; i < std::size(secondStudent.rates); i++)
	{
		avarageRateSecondStudent += secondStudent.rates[i];
	}

	avarageRateSecondStudent /= static_cast<float>(std::size(secondStudent.rates));

	return avarageRateFirstStudent < avarageRateSecondStudent;
}

void printStudent(Student currenStudent)
{
	std::string rates = "";
	for (int i = 0; i < std::size(currenStudent.rates); i++)
	{
		rates += " ";
		rates += std::to_string(currenStudent.rates[i]);
	}

	std::cout << "Name: " << currenStudent.name << " Rates: " << rates << std::endl;

}

Student* findBest(Student arrayOfStudents[amountOfStudents], const int amountOfStudents)
{
	int tempSumFirstStudent = 0;
	int tempSumSecondStudent = 0;
	Student* bestStudentPtr = nullptr;

	for (int i = 0; i < amountOfStudents - 1; i++)
	{
		for (int j = 0; j < std::size(arrayOfStudents[i].rates); j++)
		{
			tempSumFirstStudent += arrayOfStudents[i].rates[j];
		}

		for (int j = 0; j < std::size(arrayOfStudents[i + 1].rates); j++)
		{
			tempSumSecondStudent += arrayOfStudents[i + 1].rates[j + 1];
		}
		if (tempSumFirstStudent > tempSumSecondStudent)
		{
			bestStudentPtr = &arrayOfStudents[i];
			std::swap(arrayOfStudents[i], arrayOfStudents[i + 1]);
		}
		else
		{
			bestStudentPtr = &arrayOfStudents[i + 1];
		}
	}
	return bestStudentPtr;
}

int sumStudentsPassedTreshold(Student arrayOfStudents[amountOfStudents], const int amountOfStudents, const float rateTreshold)
{
	float tempSum;
	int passedTreshold = 0;

	for (int i = 0; i < amountOfStudents; i++)
	{
		tempSum = 0;
		for (int j = 0; j < std::size(arrayOfStudents[i].rates); j++)
		{
			tempSum += arrayOfStudents[i].rates[j];
		}
		if ((tempSum) / std::size(arrayOfStudents[i].rates) > rateTreshold)
		{
			passedTreshold += 1;
		}
	}
	return passedTreshold;
}