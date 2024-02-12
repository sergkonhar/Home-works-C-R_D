#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareByLength(std::string firstParam, std::string secondParam) 
{
    return firstParam.length() > secondParam.length();
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) 
{
    unsigned int result = std::count_if(vec.begin(), vec.end(), [number](int inNumber) {return inNumber % number == 0;});
    return result;
}

class sortFunction
{
public:

    sortFunction() {}

    bool operator()(std::string firstParam, std::string secondParam) { return firstParam.length() > secondParam.length(); }
};

int main()
{
    std::vector<std::string> strings{ "abcd", "abcdef" , "abc", "abcd"};

    std::cout << "Unsorted vector: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << strings[i] << " ";
    }
    
    std::cout << std::endl;

    std::sort(strings.begin(), strings.end(), compareByLength);

    std::cout << "Sorted vector: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << strings[i] << " ";
    }

    std::cout << std::endl;

    std::sort(strings.begin(), strings.end(), [](std::string firstParam, std::string secondParam){return firstParam.length() < secondParam.length(); });

    std::cout << "Resorted vector: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << strings[i] << " ";
    }

    std::cout << std::endl;

    sortFunction sort;

    std::sort(strings.begin(), strings.end(), sort);

    std::cout << "Resorted vector: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << strings[i] << " ";
    }

    std::cout << std::endl;

    std::vector<int> numbers{ 4, 7 , 24, 57, 100, 73, 90, 22, 43, 10, 55 };
    int divider = 2;

    unsigned int result = countDivisibleBy(numbers, divider);

    std::cout << "Count divisible result: " << result;

    std::cout << std::endl;
}


