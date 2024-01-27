#pragma once
#include <string>
#include <iostream>

class Weapon 
{
public:

	virtual float getDamage(int range) { return 0; };
	virtual float getMissChance(int range) { return 0;};
	virtual void printWeaponParameters() {};

	virtual void setName(std::string name);
	void setBaseDamage(float baseDamage);
	void setBaseMissChance(float baseMissChance);
	void setMaxRange(float maxRange);

	std::string getName();
	float getBaseDamage();
	float getBaseMissChance();
	float getMaxRange();

private:
	std::string m_name;
	float m_baseDamage;
	float m_baseMissChance;
	float m_maxRange;

};

class RangedWeapon : public Weapon
{
public:
	
	float getDamage(int range) override;
	float getMissChance(int range) override;
	void printWeaponParameters() override;

	void setRangeDivider( float rangeDivider);
	void setMissChanceIncreaseOverRangeQuotient(float missChanceIncreaseOverRangeQuotient);
	void setDamageReductionOverRangeQuotient(float damageReductionOverRangeQuotient);

	float getRangeDivider();
	float getMissChanceIncreaseOverRangeQuotient();
	float getDamageReductionOverRangeQuotient();
	
private:
	float m_rangeDivider;
	float m_missChanceIncreaseOverRangeQuotient;
	float m_damageReductionOverRangeQuotient;
};

class SniperRifle : public RangedWeapon
{
public:
	SniperRifle();
	
};

class AssaultRifle : public RangedWeapon
{
public:
	AssaultRifle();

};

class Pistol : public RangedWeapon
{
public:
	Pistol();

};

class Melee : public Weapon
{
public:
	float getDamage(int range);
	float getMissChance(int range);
	void printWeaponParameters();
	
};

class BareHands : public Melee 
{
public:
	BareHands();

};

class Axe : public Melee
{
public:
	Axe();
};

class Sword : public Melee
{
public:
	Sword();

};