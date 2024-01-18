#pragma once
#include "PlayerClass.h"
#include "Weapon.h"
#include <string>
#include "Player.h"
#include <iostream>
#include <random>

Player::Player()
	: m_helthPoints(100), m_armor(5), m_name("Unnamed Player"), m_playersWeapon(new BareHands), m_playersClass(new Default)
{	
}

Player::Player(Weapon* weapon, PlayerClass* playerClass, std::string name)
	: m_helthPoints(100), m_armor(5)
{
	m_playersWeapon = weapon;
	m_playersClass = playerClass;
	m_name = name;
}

Player::~Player()
{
	delete m_playersClass;
	delete m_playersWeapon;
}

void Player::printPlayerinfo() 
{
	std::cout << std::endl;
	std::cout << "Player's data" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Current helth: " << m_helthPoints << std::endl;
	std::cout << "Armor: " << m_armor << std::endl;
	std::cout << "Class: " << m_playersClass->getName() << std::endl;
	std::cout << std::endl;
	std::cout << "Player's weapon" << std::endl;
	m_playersWeapon->printWeaponParameters();

}

float Player::getHelthPoints()
{
	return m_helthPoints;
}

void Player::setHelthPoints(float updatedHealthPoints) 
{
	m_helthPoints = updatedHealthPoints;
}

float Player::getArmor()
{
	return m_armor;
}

std::string Player::getName()
{
	return m_name;
}

PlayerClass* Player::getClass()
{
	return m_playersClass;
}

Weapon* Player::getWeapon()
{
	return m_playersWeapon;
}

float Player::getMissThershold()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.0, 1.0);
	float missThreshold = dis(gen);

	return missThreshold;
}

void Player::attack(Player* otherPlayer, int range)
{
	float missChances = this->getWeapon()->getMissChance(range) + otherPlayer->getClass()->getMissChance();
	float armor = otherPlayer->getArmor() * otherPlayer->getClass()->getArmorModifier();
	float weaponDamage = this->getWeapon()->getDamage(range);
	float missThreshold = this->getMissThershold();

	if (this == otherPlayer)
	{
		std::cout << std::endl;
		std::cout << "Do not attack your self";
		std::cout << std::endl;
		return;
	}

	else if (otherPlayer->getHelthPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << "Enemy already defeated";
		std::cout << std::endl;
		return;
	}

	else if (weaponDamage <= armor)
	{
		std::cout << std::endl;
		std::cout << "You can't penetrait armor come closer or run away";
		std::cout << std::endl;
		return;
	}
	
	else if (missChances >= missThreshold)
	{
		std::cout << std::endl;
		std::cout << "You miss, come closer, try one more time or run away";
		std::cout << std::endl;
		return;
	}


	otherPlayer->setHelthPoints(otherPlayer->getHelthPoints()- (weaponDamage - armor));

	if (otherPlayer->getHelthPoints() <= 0)
	{
		otherPlayer->setHelthPoints(0);
		std::cout << std::endl;
		std::cout << this->getName() << " Attacked player " << otherPlayer->getName() << " With weapon " << this->getWeapon()->getName()
			<< " With base damage " << this->getWeapon()->getBaseDamage() << " Resulting enemy HP " << otherPlayer->getHelthPoints();
		std::cout << std::endl;
		std::cout << "Enemy defeated";
		std::cout << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << this->getName() << " Attacked player " << otherPlayer->getName() << " With weapon " << this->getWeapon()->getName()
		<< " With base damage " << this->getWeapon()->getBaseDamage() << " Resulting enemy HP " << otherPlayer->getHelthPoints();
	std::cout << std::endl;
	return;
}





