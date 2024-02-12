#include "Victory.h"
#include "Munchkin.h"
#include "ItemDeck.h"
#include <vector>
#include "DeckSelectionHelper.h"
#include "Item.h"
#include "Modifier.h"
#include "ModifierDeck.h"

void Victory_AdditionalLevels::apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers)
{
	munchkin->updateLevelBy(m_additionalLevels);
}

	
void Victory_AdditionalItems::apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers)
{
	
	std::vector<Item* > generetadItems;
	

	while (generetadItems.size() < m_additionalItems)
	{
		generetadItems.push_back(items->generateItem());
		
		
	}
	
	while (generetadItems.size()!=0)
	{
		munchkin->addItem(generetadItems[0]);
		generetadItems.erase(generetadItems.begin());
	}
}

void Victory_AdditionalModifiers::apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers)
{
	std::vector<Modifier* > generetadModifier;
	

	while (generetadModifier.size() < m_additionalModifiers)
	{
		generetadModifier.push_back(modifiers->generateModifier());
	}

	while (generetadModifier.size()!=0)
	{
		munchkin->addModifier(generetadModifier[0]);
		generetadModifier.erase(generetadModifier.begin());
	}

}
	
