#pragma once
#include <string>

class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	//DONE
	virtual std::string getFullInfo() { return ""; }
	//DONE
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level=1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return ("Will decrease level by " + std::to_string(m_levelToDowngrade)); }

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	std::string getFullInfo() override { return ("Will decrease level by " + std::to_string(m_levelToDowngrade)) ; }

	void apply(Munchkin* munchkin) override;

private:
	int m_minimalMunchkinLevelToApply;
};

//DONE
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	Runaway_ModifierFromHandRemoval(int numberOfItems = 1)
		:m_numberOfItemsToRemove(numberOfItems) {}

	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Will remove modifier from hand in quantity of " + std::to_string(m_numberOfItemsToRemove); }

private:
	int m_numberOfItemsToRemove;
};
//DONE

//DONE
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	Runaway_ItemEquipedRemoval(int numberOfItems = 1)
		:m_numberOfItemsToRemove(numberOfItems) {}

	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Will remove item from inventory in quantity of " + std::to_string(m_numberOfItemsToRemove); }

private:
	int m_numberOfItemsToRemove;
};
//DONE