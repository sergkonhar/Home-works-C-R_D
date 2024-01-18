#pragma once
#include "PlayerClass.h"
#include "Weapon.h"
#include <string>

class Player 
{
public:
	Player();
	Player(Weapon* weapon, PlayerClass* playerClass, std::string name);

	~Player();

	void printPlayerinfo();
	void attack(Player* otherPlayer, int range);

	float getHelthPoints();
	void setHelthPoints(float updatedHealthPoints);

	float getArmor();

	std::string getName();

	PlayerClass* getClass();
	Weapon* getWeapon();

	float getMissThershold();

private:
	std::string m_name;
	float m_helthPoints;
	float m_armor;
	PlayerClass* m_playersClass = nullptr;
	Weapon* m_playersWeapon = nullptr;
};