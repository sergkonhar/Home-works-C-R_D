#include "ModifierDeck.h"
#include <Algorithm>
#include "Modifier.h"
#include "DeckSelectionHelper.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{14}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::Human}},
		{new HalvesMonsterLevel{Tribe::God}},
		{new Alcohol{}},
		{new Alcohol{}},
		{new Alcohol{}},
		{new Alcohol{}},
		{new Alcohol{}}
	};
}

ModifierDeck::~ModifierDeck()
{
	//DONE
	for (int i = 0; i < m_modifiersDatabase.size(); i++)
	{
		delete m_modifiersDatabase[i];
	}
	//DONE
}


std::vector<Modifier*> ModifierDeck::generateModifiers() 
{
	//DONE
	int initialModifiersQuantity = 5;
	std::vector<Modifier*> playerModifaers;
	DeckSelectionHelper<Modifier> selectModifier;

	while (playerModifaers.size() < initialModifiersQuantity)
	{
		playerModifaers.push_back(selectModifier(m_modifiersDatabase, m_usedModifiers));
	}


	return playerModifaers;
	//DONE
}	

//DONE
Modifier* ModifierDeck::generateModifier() 
{
	DeckSelectionHelper<Modifier> selectModifier;
	return selectModifier(m_modifiersDatabase, m_usedModifiers);
}
//DONE