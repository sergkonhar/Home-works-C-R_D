#pragma once

class Munchkin;
class Monster;
class ItemDeck;
class ModifierDeck;

enum class FightResult
{
	NotStarted,
	InProgress,
	MunchkinWon,
	MonsterWon
};

class Fight
{
public:
	void setMunchkin(Munchkin* munchkin) { m_munchkin = munchkin; };
	void setMonster(Monster* monster) { m_monster = monster; }

	void start();
	bool getFinish() const { return m_result != FightResult::InProgress; }

	void applyModifier(int choice);

	int getMunchkinMonsterPowerDifference() const { return m_MunchkinPower - m_monsterPower; }

	int getMunchkinPower() const { return m_MunchkinPower; }
	int getMonsterPower() const { return m_monsterPower; }

	void runawayFlow();
	void victoryFlow(ItemDeck* items, ModifierDeck* modifiers);

	bool getInstantVictory();

	bool getFriendStatus();

private:
	void calculateMunchkinPower();
	void calculateMonsterPower();

private:
	int m_MunchkinPower = 0;
	int m_monsterPower = 0;
	bool m_monsterIsFriend = false;

	Munchkin* m_munchkin = nullptr;
	Monster* m_monster = nullptr;

	FightResult m_result = FightResult::NotStarted;
};