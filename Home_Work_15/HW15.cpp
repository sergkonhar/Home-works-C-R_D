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

float avaregeRateOfStudent(Student studentToClaculate);

bool sortByAvarageRate(Student firstStudent, Student secondStudent);

void printStudent(Student currenStudent);

Student* findBest(Student arrayOfStudents[amountOfStudents], const int amountOfStudents);

int sumStudentsPassedTreshold(Student arrayOfStudents[amountOfStudents], const int amountOfStudents, const float rateTreshold);

int main()
{
    Student firstStudent = { "Dwight",{4,5,3,5} };
    float studentAvarageRates = avaregeRateOfStudent(firstStudent);

    std::cout << "Avarage rate is: " << studentAvarageRates <<std::endl << std::endl;

    Student arrayOfStudents[amountOfStudents] = { {"Dwight",{4,5,3,5}} , {"Meg", {5,5,5,5}}, {"Bill", {5,5,5,5}}, {"Steve", {5,3,3,2}}, {"Nancy", {1,3,4,5}} };

    std::sort(std::begin(arrayOfStudents), std::end(arrayOfStudents), sortByAvarageRate);

    for (int i = 0; i < std::size(arrayOfStudents); i++)
    {
        printStudent(arrayOfStudents[i]);
    }

    Student* ptrToBestStudent = findBest(arrayOfStudents, amountOfStudents);
    std::cout << std::endl <<"Best Student => ";
    printStudent(*ptrToBestStudent);

    int passedTreshold = sumStudentsPassedTreshold( arrayOfStudents, amountOfStudents, rateTreshold);
    std::cout << std::endl << "Number of students which pass over 75% avarage rate: " << passedTreshold << std::endl;

}

float avaregeRateOfStudent(Student studentToClaculate)
{
    float avarageRate = 0;
    for (int i = 0; i < std::size(studentToClaculate.rates); i++)
    {
        avarageRate += studentToClaculate.rates[i];
    }

    avarageRate /= static_cast<float>(std::size(studentToClaculate.rates));

    return avarageRate;
}

bool sortByAvarageRate(Student firstStudent, Student secondStudent) 
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
    std::vector<int> rateSums;
    int tempSum;
    Student* bestStudentPtr = nullptr;

    for (int i = 0; i < amountOfStudents; i++)
    {
        tempSum = 0;

        for (int j = 0; j < std::size(arrayOfStudents[i].rates); j++)
        {
            tempSum += arrayOfStudents[i].rates[j];
        }
        
        rateSums.push_back(tempSum);
    }

    for (int i = 0; i < rateSums.size()-1; i++)
    {
        if (rateSums[i]> rateSums[i+1])
        {
            bestStudentPtr = (arrayOfStudents + i);
            std::swap(rateSums[i], rateSums[i + 1]);
            std::swap(arrayOfStudents[i], arrayOfStudents[i + 1]);
        }
        
        else 
        {
            bestStudentPtr = (arrayOfStudents + (i+1));
        }
    }
    return bestStudentPtr;
}

int sumStudentsPassedTreshold(Student arrayOfStudents[amountOfStudents], const int amountOfStudents, const float rateTreshold) 
{
    float tempSum;
    int passedTreshold=0;

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