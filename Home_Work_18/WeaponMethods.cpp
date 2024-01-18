#include "Weapon.h"
#include <Array>
#include <string>
#include <iostream>

void Weapon::setName(std::string name)
{
	m_name = name;
}

void Weapon::setBaseDamage(float baseDamage)
{
	m_baseDamage = baseDamage;
}

void Weapon::setBaseMissChance(float baseMissChance) 
{
	m_baseMissChance = baseMissChance;
}

void Weapon::setMaxRange(float maxRange) 
{
	m_maxRange = maxRange;
}

std::string Weapon::getName() 
{
	return m_name;
}

float Weapon::getBaseDamage() 
{
	return m_baseDamage;
}

float Weapon::getBaseMissChance()
{
	return m_baseMissChance;
}

float Weapon::getMaxRange()
{
	return m_maxRange;
}


void RangedWeapon::setRangeDivider(float rangeDivider)
{
	m_rangeDivider = rangeDivider;
}

void RangedWeapon::setMissChanceIncreaseOverRangeQuotient(float missChanceIncreaseOverRangeQuotient)
{
	m_missChanceIncreaseOverRangeQuotient = missChanceIncreaseOverRangeQuotient;
}

void RangedWeapon::setDamageReductionOverRangeQuotient(float damageReductionOverRangeQuotient)
{
	m_damageReductionOverRangeQuotient = damageReductionOverRangeQuotient;
}

float RangedWeapon::getRangeDivider()
{
	return m_rangeDivider;
}

float RangedWeapon::getMissChanceIncreaseOverRangeQuotient()
{
	return m_missChanceIncreaseOverRangeQuotient;
}

float RangedWeapon::getDamageReductionOverRangeQuotient()
{
	return m_damageReductionOverRangeQuotient;
}


SniperRifle::SniperRifle()
{
	this->setName("Sniper Rifle");
	this->setBaseDamage(50.0f);
	this->setBaseMissChance(0.05f);
	this->setMaxRange(1000.0f);
	this->setRangeDivider(1.0f);
	this->setMissChanceIncreaseOverRangeQuotient(0.05f);
	this->setDamageReductionOverRangeQuotient(1.0f);
	
}

AssaultRifle::AssaultRifle() 
{
	this->setName("Assault Rifle");
	this->setBaseDamage(40.0f);
	this->setBaseMissChance(0.1f);
	this->setMaxRange(700.0f);
	this->setRangeDivider(1.5f);
	this->setMissChanceIncreaseOverRangeQuotient(0.1f);
	this->setDamageReductionOverRangeQuotient(1.5f);

}

Pistol::Pistol() 
{
	this->setName("Pistol");
	this->setBaseDamage(30.0f);
	this->setBaseMissChance(0.2f);
	this->setMaxRange(500.0f);
	this->setRangeDivider(2.0f);
	this->setMissChanceIncreaseOverRangeQuotient(0.15f);
	this->setDamageReductionOverRangeQuotient(1.7f);
}

BareHands::BareHands()
{
	this->setName("Bare Hands");
	this->setBaseDamage(10.0f);
	this->setBaseMissChance(0.01f);
	this->setMaxRange(0.5f);
}

Axe::Axe()
{
	this->setName("Axe");
	this->setBaseDamage(25.0f);
	this->setBaseMissChance(0.01f);
	this->setMaxRange(0.7f);
}

Sword::Sword()
{
	this->setName("Sword");
	this->setBaseDamage(30.0f);
	this->setBaseMissChance(0.01f);
	this->setMaxRange(1.0f);
}



void RangedWeapon::printWeaponParameters()
{
	std::cout << std::endl;
	std::cout << "Weapon Info" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Base Damage: " << this->getBaseDamage() << std::endl;
	std::cout << "Base Miss Chance: " << this->getBaseMissChance() << std::endl;
	std::cout << "Max Range: " << this->getMaxRange() << std::endl;
	std::cout << std::endl;
}


float Melee::getDamage(int range)
{
	if (range > this->getMaxRange())
	{
		return 0.0f;
	}
	
	return this->getBaseDamage();
}

float Melee::getMissChance(int range)
{
	if (range > this->getMaxRange())
	{
		return 1.0f;
	}

	return this->getBaseMissChance();
}

void Melee::printWeaponParameters()
{
	std::cout << std::endl;
	std::cout << "Weapon Info" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Base Damage: " << this->getBaseDamage() << std::endl;
	std::cout << "Base Miss Chance: " << this->getBaseMissChance() << std::endl;
	std::cout << "Max Range: " << this->getMaxRange() << std::endl;
	std::cout << std::endl;
}

float RangedWeapon::getDamage(int range) 
{
	for (int i = 1; i < 5; i++)
	{
		if (range > this->getMaxRange() / (this->getRangeDivider() * i )) 
		{
			return this->getBaseDamage() - (this->getBaseDamage() / (this->getDamageReductionOverRangeQuotient() * i ));
		}
	}
	return this->getBaseDamage();
}

float RangedWeapon::getMissChance(int range)
{
	for (int i = 1; i < 5; i++)
	{
		if (range > this->getMaxRange() / (this->getRangeDivider() * i))
		{
			return 1-(this->getBaseMissChance()*i);
		}
	}
	return this->getBaseMissChance();
}