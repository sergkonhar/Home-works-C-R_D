#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return getBasePower(); }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const =0;
	//DONE
	virtual bool getInstantKill(Tribe monsterTribeModifier) { return false; }
	//DONE

protected:
	std::string m_name;
	

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

	//DONE
	virtual bool getInstantKill(Tribe monsterTribeModifier) { return false; }
	//DONE

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
			return getBasePower() * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

//DONE
class ZombieSlayerWeapon : public Weapon
{
public:
	ZombieSlayerWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: instantly kills Zombie!\n";
	}

	bool getInstantKill(Tribe monsterTribeModifier) override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::God:
			return false;
		case Tribe::Zombie:
			return true;
		default:
			return false;
		}
	}



};


class GodSlayerWeapon : public Weapon
{
public:
	GodSlayerWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: instantly kills God!\n";
	}

	bool getInstantKill(Tribe monsterTribeModifier) override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::Zombie:
			return false;
		case Tribe::God:
			return true;
		default:
			return false;
		}
	}



};
//DONE

