#pragma once
#include <string>

class PlayerClass 
{
public:
	
	 virtual float getDamageModifier() const=0;
	 virtual float getArmorModifier() const=0;
	 virtual float getMissChance() const=0;

	 std::string getName() { return m_name; };


private:
	 std::string m_name;
};

class Default : public PlayerClass
{
public:

	float getDamageModifier() const override { return 1.0f; };
	float getArmorModifier() const override { return 1.0f; };
	float getMissChance() const override { return 0.0f; };

private:
	std::string m_name = "Default";
};

class Defender : public PlayerClass
{
public:
	 float getDamageModifier() const override { return 0.8f; };
	 float getArmorModifier() const override { return 2.1f; };
	 float getMissChance() const override { return 0.2f; };

private:
	 std::string m_name = "Defender";
};

class Attacker : public PlayerClass
{
public:
	float getDamageModifier() const override { return 1.4f; };
	float getArmorModifier() const override { return 0.5f; };
	float getMissChance() const override { return 0.0f; };

private:
	std::string m_name = "Attacker";
};

class LuckyMan : public PlayerClass
{
public:
	float getDamageModifier() const override { return 0.5f; };
	float getArmorModifier() const override { return 0.3f; };
	float getMissChance() const override { return 0.3f; };

private:
	std::string m_name = "Lucky Man";
};

