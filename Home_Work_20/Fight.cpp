#include "Fight.h"

#include "Item.h"
#include "Modifier.h"
#include "Munchkin.h"
#include "Monster.h"
#include "Runaway.h"
#include "Victory.h"
#include <cassert>

void Fight::start()
{
	m_result = FightResult::InProgress;

	calculateMunchkinPower();
	calculateMonsterPower();
}

void Fight::applyModifier(int choice)
{
	Modifier* modifier = m_munchkin->popModifier(choice);
	if (modifier == nullptr)
	{
		//DONE
		assert(modifier != nullptr && "Modifier in deck is nullptr");
		//DONE
		return;
	}

	modifier->apply(m_munchkin, m_monster);

	m_MunchkinPower += modifier->getMunchkinModifier();
	m_monsterPower += modifier->getMonsterModifier();
	m_monsterIsFriend = modifier->isMonsterFriend();
}

void Fight::runawayFlow()
{
	Runaway* policy = m_monster->getRunawayPolicy();
	policy->apply(m_munchkin);

	m_result = FightResult::MonsterWon;
}

void Fight::victoryFlow(ItemDeck* items, ModifierDeck* modifiers)
{
	
	m_munchkin->updateLevelBy(1);
	//DONE
	Victory* victoryPolicy = m_monster->getVictoryPolicy();
	victoryPolicy->apply(m_munchkin, items, modifiers);
	//DONE

	m_result = FightResult::MunchkinWon;
}

void Fight::calculateMunchkinPower()
{
	m_MunchkinPower += m_munchkin->getLevel();
	for (Item* item : m_munchkin->getItems())
	{
		m_MunchkinPower += item->getPower(m_monster->getTribe());
	}
}

void Fight::calculateMonsterPower()
{
	m_monsterPower = m_monster->getLevel();
}

bool Fight::getInstantVictory() 
{
	for (int i = 0; i < m_munchkin->getItems().size(); i++)
	{
		if (m_munchkin->getItems()[i]->getInstantKill(m_monster->getTribe())) 
		{
			return true;
		}
	}

	return false;
}

bool Fight::getFriendStatus() 
{
	return m_monsterIsFriend;
}