#include <iostream>
#include <string_view>

const int columns = 5;
const int rows = 5;

enum class sortTypes
{
	byColumns,
	byRows
};

void bubbleSort(int array[], int size);
int partition(int array[], int low, int high);
void qSort(int array[], int low, int high);
void sort2DArray(int array2d[rows][columns], sortTypes typeOfSort);

int main()
{
	int arrForBubbleSort[columns] = { 2,5,1,9,6 };
	bubbleSort(arrForBubbleSort, columns);
	std::cout << "Bubble sort: ";
	for (int i = 0; i < columns; i++)
	{
		std::cout << arrForBubbleSort[i] << " ";
	}
	std::cout << std::endl << std::endl;
	
	sortTypes order = sortTypes::byColumns;
	int arrayForQickSort[rows][columns] = {{772,75,17,9,67} ,{46,56,1,45,18} ,{12,15,221,93,65} ,{232,54,51,19,63} ,{23,52,43,39,64}};
	sort2DArray(arrayForQickSort, order);

	if (order== sortTypes::byRows)
	{
		std::cout << "Q sort by rows: " << std::endl;
	}
	else 
	{
		std::cout << "Q sort by columns: " << std::endl;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << arrayForQickSort[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void bubbleSort(int array[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < (size - i)-1; j++) 
		{
			if (array[j] > array[j + 1]) 
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

int partition(int array[], int low, int high) 
{
	int pivotPoint = array[high];
	int index = low - 1;

	for (int i = low; i < high; i++) 
	{
		if (array[i] <= pivotPoint) 
		{
			index++;
			std::swap(array[i], array[index]);
		}
	}
	std::swap(array[index + 1], array[high]);
	return (index + 1);
}

void qSort(int array[], int low, int high) 
{
	if (low < high)
	{
		int index = partition(array, low, high);
		qSort(array, low, index - 1);
		qSort(array, index + 1, high);
	}
}

void sort2DArray(int array2d[rows][columns], sortTypes typeOfSort) 
{
	if (typeOfSort == sortTypes::byRows) 
	{
		for (int i = 0; i < rows; i++)
		{
			qSort(array2d[i], 0, columns - 1);
		}
	}
	else 
	{
		for (int i = 0; i < columns; i++)
		{
			int tempArr[rows];
			for (int j = 0; j < rows; j++) 
			{				
				tempArr[j] = array2d[j][i];
			}
			qSort(tempArr, 0, rows - 1);
		
			for (int j = 0; j < rows; j++)
			{
				array2d[j][i] = tempArr[j];
			}
		}

	}
}