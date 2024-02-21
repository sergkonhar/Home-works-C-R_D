#pragma once
#include <string>
#include "ModifierDeck.h"
#include "ItemDeck.h"

class Munchkin;

class Victory
{
public:
	virtual void apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers) = 0;
	virtual std::string getFullInfo() { return ""; }
	
};

class Victory_AdditionalLevels : public Victory
{
public:
	Victory_AdditionalLevels(int levelsToIncrease = 1) : m_additionalLevels(levelsToIncrease) {}
	void apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers) override;
	std::string getFullInfo() override { return ("Give additional levels in quantity of " + std::to_string(m_additionalLevels)); }

protected:
	int m_additionalLevels;
};

class Victory_AdditionalItems : public Victory
{
public:
	Victory_AdditionalItems(int itemsToAdd = 1) : m_additionalItems(itemsToAdd) {}
	void apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers) override;
	std::string getFullInfo() override { return ("Give additional items in quantity of " + std::to_string(m_additionalItems)); }

protected:
	int m_additionalItems;
};

class Victory_AdditionalModifiers : public Victory
{
public:
	Victory_AdditionalModifiers(int modifiersToAdd = 1) : m_additionalModifiers(modifiersToAdd) {}
	void apply(Munchkin* munchkin, ItemDeck* items, ModifierDeck* modifiers) override;
	std::string getFullInfo() override { return ("Give additional modifiers in quantity of " + std::to_string(m_additionalModifiers)); }

protected:
	int m_additionalModifiers;
};