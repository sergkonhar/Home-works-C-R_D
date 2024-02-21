#pragma once
#include "Munchkin.h"
#include "ItemDeck.h"
#include "MonsterDeck.h"
#include "ModifierDeck.h"

class Game
{
public:
	Game() = default;
	void run();

	ItemDeck* getItemsBonusDeck() { return &m_itemsBonusDeck; }
	ModifierDeck* getModifiersBonusDeck() { return &m_modifiersBonusDeck; }

private:
	void generateMunchkinInitialCards();
	Monster* generateMonster();
	

private:
	Munchkin m_munchkin;
	ItemDeck m_itemsDeck;
	ItemDeck m_itemsBonusDeck;
	ModifierDeck m_modifiersDeck;
	ModifierDeck m_modifiersBonusDeck;
	MonsterDeck m_monstersDeck;
};