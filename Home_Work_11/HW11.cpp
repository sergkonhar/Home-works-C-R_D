#include <iostream>

const int columns = 3;
const int rows = 3;

enum class sortDirection 
{
    Ascending,
    Descending
};

bool findInArray(int inarray[rows][columns], int valueToFind);
bool isSorted(int inarray[], sortDirection sort, const int columns);
void arrayPassFirstVariant(int inarray[rows][columns]);
void arrayPassSecondVariant(int inarray[rows][columns]);

int main()
{
    int valueToFind = 10;
    int Array2D[rows][columns] = { {1,2,3},{4,10,22},{4,6,8} };

    bool isNumberInArray = findInArray(Array2D, valueToFind);
    std::cout<< std::boolalpha << "Value found: " << isNumberInArray;
    std::cout << std::endl;

    sortDirection currentSort = sortDirection::Ascending;
    int sortedArray[columns]= { 1,2,3};

    bool isArraySorted = isSorted(sortedArray, currentSort, columns);
    std::cout << std::boolalpha << "Array is sorted: " << isArraySorted;
    std::cout << std::endl;

    arrayPassFirstVariant(Array2D);

    arrayPassSecondVariant(Array2D);
}

bool findInArray(int inarray[rows][columns], int valueToFind)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++) 
        {
            if (inarray[i][j] == valueToFind) 
            {
                return true;
            }
        }
    }
    return false;
}

bool isSorted(int inarray[], sortDirection sort, const int columns)
{
    if (sort == sortDirection::Ascending) 
    {
        for (int i = 0; i < columns-1; i++) 
        {
            if (inarray[i] > inarray[i + 1]) 
            {
                return false;
            }
        }
    }
    else if (sort == sortDirection::Descending)
    {
        for (int i = 0; i < columns - 1; i++)
        {
            if (inarray[i] < inarray[i + 1])
            {
                return false;
            }
        }
    }
    return true;
}

void arrayPassFirstVariant(int inarray[rows][columns]) 
{
    std::cout << "Pass throw array 1st variant:";

    for (int i = columns-1; i >=0; i--)
    {
        for (int j = 0; j < rows; j++) 
        {
            std::cout << " " << inarray[j][i];
        }
    }
    std::cout << std::endl;
}

void arrayPassSecondVariant(int inarray[rows][columns]) 
{
    std::cout << "Pass throw array 2nd variant:";

    for (int i = rows - 1; i >= 0; i--) 
    {
        if (i % 2 == 0) 
        {
            for (int j = 0; j < columns; j++) 
            {
                std::cout << " " << inarray[i][j];
            }
        }
        else 
        {
            for (int j = columns-1; j >=0; j--)
            {
                std::cout << " " << inarray[i][j];
            }
        }
    }
}
