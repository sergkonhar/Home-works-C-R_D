#pragma once
#include <string>
#include "Monster.h"
#include "Munchkin.h"

class Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster* monster) = 0;
	virtual int getMunchkinModifier() const { return m_munchkinPowerChange; }
	virtual int getMonsterModifier() const { return m_monsterPowerChange; }

	virtual std::string getFullInfo() const { return ""; }

	virtual bool isMonsterFriend() { return m_isFriend; };

protected:
	int m_munchkinPowerChange = 0;
	int m_monsterPowerChange = 0;
	bool m_isFriend = false;
};

class SimpleModifier : public Modifier
{
public:
	SimpleModifier(int powerBoost) : m_powerBoost(powerBoost) {}

	virtual void apply(Munchkin* munchkin, Monster* monster) override
	{
		m_munchkinPowerChange = m_powerBoost;
	}

	virtual std::string getFullInfo() const
	{
		return "Munchkin power +" + std::to_string(m_powerBoost);
	}

private:
	int m_powerBoost;
};

class DoubleMunchkinLevel : public Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster* monster) override
	{
		m_munchkinPowerChange = munchkin->getLevel();
	}

	virtual std::string getFullInfo() const override
	{
		return "Double Munchkin level!";
	}
};

class HalvesMonsterLevel : public Modifier
{
public:
	//DONE

	HalvesMonsterLevel(Tribe tribe = Tribe::Undead) :m_tribeToreducePower(tribe){}
	virtual void apply(Munchkin* munchkin, Monster* monster) override 
	{
		if (monster->getTribe() == m_tribeToreducePower)
		{
			m_monsterPowerChange = -(monster->getLevel() / 2);
		}
	} 

	virtual std::string getFullInfo() const override { return "Halves the power of monster from tribe " +  getTribeName(); }

	std::string getTribeName() const
	{
		if (m_tribeToreducePower == Tribe::Undead)
		{
			return "Undead";
		}
		else if (m_tribeToreducePower == Tribe::Zombie)
		{
			return "Zombie";
		}
		else if (m_tribeToreducePower == Tribe::Human)
		{
			return "Human";
		}
		else
		{
			return "God";
		}
	}

private:
	Tribe m_tribeToreducePower;
};
//DONE


//DONE
class Alcohol : public Modifier
{
public:
	virtual std::string getFullInfo() const override { return "Make Humans friendly"; }

	virtual void apply(Munchkin* munchkin, Monster* monster) override
	{
		if (monster->getTribe() == Tribe::Human)
		{
			m_isFriend = true;
		}
	}
};

//DONE