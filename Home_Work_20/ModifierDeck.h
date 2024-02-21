#pragma once
#include <vector>

class Modifier;

class ModifierDeck
{
public:
	ModifierDeck();
	~ModifierDeck();
	//DONE
	std::vector<Modifier*> generateModifiers();
	Modifier* generateModifier();
	//DONE
private:
	std::vector<Modifier*> m_modifiersDatabase;
	std::vector<Modifier*> m_usedModifiers;
};