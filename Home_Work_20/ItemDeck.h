#pragma once
#include <vector>
#include <string>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();
	//DONE
	std::vector<Item*> generateItems();
	Item* generateItem();
	//DONE
	
private:
	std::vector<Item*> m_itemsDataBase;
	std::vector<Item*> m_usedItems;
	const std::string m_itemsData = "Items.txt";
};