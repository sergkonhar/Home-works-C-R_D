#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>



template <class T>
class DeckSelectionHelper
{
public:

	T* operator()(std::vector<T*>& entityList, std::vector<T*>& entityExcludeList)
	{
		if (entityList.size()== entityExcludeList.size())
		{
			entityExcludeList.clear();
		}

		T* generatedEntity = nullptr;

		while(generatedEntity == nullptr) 
		{
			
			std::shuffle(entityList.begin(), entityList.end(), std::random_device());

			auto it = std::find(entityExcludeList.begin(), entityExcludeList.end(), entityList[0]);

			if (it == entityExcludeList.end())
			{
				generatedEntity = entityList[0];
				entityExcludeList.push_back(entityList[0]);

			}
		}

		return generatedEntity;
	}

};