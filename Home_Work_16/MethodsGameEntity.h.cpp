#include "GameEntity.h"
#include <string>
#include <iostream>

weapon::weapon()
	:m_name("default"), m_damage(1), m_range(1)
{
}

weapon::weapon(const std::string& name, int damage, int range)
	:m_name(name), m_damage(damage), m_range(range)
{
}

void weapon::printWeaponInfo()
{
	std::cout << m_name << std::endl;
	std::cout << "Damage: " << m_damage << std::endl;
	std::cout << "Range: " << m_range << std::endl;
}

player::player()
	: m_name("No Name"), m_team("none"), m_healtPoints(100), m_playerClass(playerClass::assault), m_activeWeapon(nullptr)
{
}

player::player(const std::string& name, int healtPoints, playerClass playerClass)
	: m_name(name), m_team("none"), m_healtPoints(healtPoints), m_playerClass(playerClass), m_activeWeapon(nullptr)
{
}

player::~player()
{
	delete m_activeWeapon;
}

void player::setTeam(const std::string& team)
{
	m_team = team;
}

std::string player::getTeam() const
{
	return m_team;
}

void player::setWeapon(weapon* weaponToAdd)
{
	m_activeWeapon = weaponToAdd;
}

weapon* player::getWeapon() const
{
	return m_activeWeapon;
}

void player::printPlayerInfo() const
{

	std::string teamName = m_team;

	std::string className;

	switch (m_playerClass)
	{
	case (playerClass::assault):
		className = "assault";
		break;
	case (playerClass::medic):
		className = "medic";
		break;
	case (playerClass::support):
		className = "support";
		break;
	case (playerClass::sniper):
		className = "sniper";
		break;
	}

	std::cout << std::endl;
	std::cout << "Player's data" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "HP: " << m_healtPoints << std::endl;
	std::cout << "Class: " << className << std::endl;
	std::cout << "Team: " << teamName << std::endl;
	std::cout << std::endl;

	if (m_activeWeapon == nullptr)
	{
		std::cout << "Weapon: " << "No Weapon added to player" << std::endl;
	}
	else
	{
		std::cout << "Weapon: " << std::endl;
		this->getWeapon()->printWeaponInfo();
	}

}

void player::removeFromTeam()
{
	m_team = "none";
}

std::string player::getName() 
{
	return m_name;
}

team::team()
	: m_name("none"), m_maxMembers(1)
{
	m_name = "Unnamed team";
}

team::team(std::string name, int maxMembers)
{
	m_name = name;
	m_maxMembers = maxMembers;
}

team::~team()
{
	for (int i = 0; i < m_teamMembers.size(); i++)
	{
		m_teamMembers[i]->removeFromTeam();
	}
}

bool team::addPlayer(player* addPlayer)
{
	for (int i = 0; i < m_teamMembers.size(); i++)
	{
		if (m_teamMembers[i]->getTeam() == addPlayer->getTeam())
		{
			return false;
		}
	}

	m_teamMembers.push_back(addPlayer);
	addPlayer->setTeam(this->m_name);
	return true;
}

bool team::deletePlayer(player* removePlayer)
{
	for (int i = 0; i < m_teamMembers.size(); i++)
	{
		if (m_teamMembers[i]->getTeam() == removePlayer->getTeam())
		{
			m_teamMembers[i]->removeFromTeam();
			m_teamMembers.erase(m_teamMembers.begin() + i);
			return true;
		}
	}
	return false;
}

void team::printTeamInfo()
{
	std::cout << std::endl;
	std::cout << "Team Info" << std::endl;
	std::cout << "Name: "<< m_name << std::endl;
	std::cout << "Max members: " << m_maxMembers << std::endl;
	std::cout << "Team members: "  << std::endl;
	

	for (int i = 0; i < m_teamMembers.size(); i++)
	{
		 m_teamMembers[i]->printPlayerInfo();
		
	}
	std::cout << std::endl;
}