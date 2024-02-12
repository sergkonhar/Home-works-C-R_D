#include "ItemDeck.h"
#include "Item.h"
#include <Algorithm>
#include "DeckSelectionHelper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//DONE

ItemDeck::ItemDeck() 
{
	
	std::fstream inputFile{};
	inputFile.open(m_itemsData, std::ios::in);

	std::string line;
	std::string segment;
	std::vector<std::string> splitedStringInner;
	std::vector<std::vector<std::string>> splitedStringOuter;

	int i = 0;
	while (std::getline(inputFile, line))
	{
		std::stringstream lineStream(line);

		while (std::getline(lineStream, segment, ';'))
		{
			splitedStringInner.push_back(segment);
			i++;

			if (i % 3 == 0)
			{
				splitedStringOuter.push_back(splitedStringInner);
				i = 0;
				splitedStringInner.clear();
			}
		}
	}

	for (int i = 0; i < splitedStringOuter.size(); i++)
	{
		if (splitedStringOuter[i][0] == "Weapon")
		{
			m_itemsDataBase.push_back(new Weapon{ splitedStringOuter[i][1], std::stoi(splitedStringOuter[i][2]) });
		}
		else if (splitedStringOuter[i][0] == "UndeadWeapon")
		{
			m_itemsDataBase.push_back(new UndeadWeapon{ splitedStringOuter[i][1], std::stoi(splitedStringOuter[i][2]) });
		}
		else if (splitedStringOuter[i][0] == "UndeadWeapon")
		{
			m_itemsDataBase.push_back(new ZombieSlayerWeapon{ splitedStringOuter[i][1], std::stoi(splitedStringOuter[i][2]) });
		}
		else
		{
			m_itemsDataBase.push_back(new GodSlayerWeapon{ splitedStringOuter[i][1], std::stoi(splitedStringOuter[i][2]) });
		}

	}
	
}

//DONE

ItemDeck::~ItemDeck()
{
	//DONE
	for (int i = 0; i < m_itemsDataBase.size(); i++)
	{
		delete m_itemsDataBase[i];
	}
	//DONE
}

std::vector<Item*> ItemDeck::generateItems()
{
	//DONE
	int initialItemsQuantity = 2;
	std::vector<Item*> playerItems;
	DeckSelectionHelper<Item> selectItem;

	while (playerItems.size() < initialItemsQuantity)
	{
		playerItems.push_back(selectItem(m_itemsDataBase, m_usedItems));
	}

	return playerItems;
	//DONE
}
//DONE
Item* ItemDeck::generateItem()
{
	DeckSelectionHelper<Item> selectItem;
	return selectItem(m_itemsDataBase, m_usedItems);
}
//DONE