#include "Runaway.h"
#include "Munchkin.h"

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

//DONE
void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin) 
{
	int munchkinModifiersQuantity = munchkin->getModifiers().size();
	if (munchkinModifiersQuantity >=1)
	{
		if (munchkinModifiersQuantity - m_numberOfItemsToRemove <= 0) 
		{
			int indexToRemove = std::rand() % munchkinModifiersQuantity;
			munchkin->removeModifierFromHand(indexToRemove);
			return;
		}

		for (int i = 0; i < m_numberOfItemsToRemove; i++)
		{
			int indexToRemove = std::rand() % munchkinModifiersQuantity;
			munchkin->removeModifierFromHand(indexToRemove);
		}
	}
	else 
	{
		return;
	}
}
//DONE

//DONE
void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin) 
{
	int munchkinItemsQuantity = munchkin->getItems().size();
	if (munchkinItemsQuantity >= 1)
	{
		if (munchkinItemsQuantity - m_numberOfItemsToRemove <= 0)
		{
			int indexToRemove = std::rand() % munchkinItemsQuantity;
			munchkin->removeItemEquipped(indexToRemove);
			return;
		}

		for (int i = 0; i < m_numberOfItemsToRemove; i++)
		{
			int indexToRemove = std::rand() % munchkinItemsQuantity;
			munchkin->removeItemEquipped(indexToRemove);
		}
	}
	else
	{
		return;
	}
}
//DONE