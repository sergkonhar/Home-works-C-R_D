#include "MonsterDeck.h"
#include <Algorithm>
#include "Monster.h"
#include "Runaway.h"
#include "DeckSelectionHelper.h"
#include <iostream>

MonsterDeck::MonsterDeck()
{
	//DONE
	m_monstersDatabase =
	{
		new Monster{"Crazy Joe", 4, Tribe::Human, new Runaway_ModifierFromHandRemoval{1}, new Victory_AdditionalItems{1} },
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_ItemEquipedRemoval{1}, new Victory_AdditionalLevels{2} },
		new Monster{"Vampire", 20, Tribe::Undead, new Runaway_LevelDowngrade{3}, new Victory_AdditionalLevels{3} },
		new Monster{"Drunk Bum", 70, Tribe::Human, new Runaway_ModifierFromHandRemoval{1}, new Victory_AdditionalItems{1} },
		new Monster{"Cripped Stripper", 25, Tribe::Zombie, new Runaway_LevelDowngrade{10}, new Victory_AdditionalLevels{2} },
		new Monster{"Vampire Lord", 50, Tribe::Undead, new Runaway_LevelDowngrade{30}, new Victory_AdditionalModifiers{1} },
		new Monster{"Devourer", 55, Tribe::God, new Runaway_ItemEquipedRemoval{1}, new Victory_AdditionalModifiers{1} },
	};
	//DONE
}

MonsterDeck::~MonsterDeck()
{
	//DONE
	for (int i = 0; i < m_monstersDatabase.size(); i++)
	{
		delete m_monstersDatabase[i];
	}
	//DONE
}

Monster* MonsterDeck::generateMonster()
{
	//DONE
	DeckSelectionHelper<Monster> selectMonster;
	Monster* selectedMonster = selectMonster(m_monstersDatabase, m_usedMonsters);
	
	return selectedMonster;
	//DONE
}


