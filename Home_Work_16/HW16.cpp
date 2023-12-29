#include <iostream>
#include "ClassRectangle.h"
#include "GameEntity.h"


int main()
{
	float perimeter;
	float area;

	Rectangle suqare;
	perimeter = suqare.getPerimeter();
	area = suqare.getArea();

	std::cout << std::endl;
	std::cout << "Square Side A : " << suqare.m_sideA << std::endl;
	std::cout << "Square Side B : " << suqare.m_sideB << std::endl;
	std::cout << "Square Perimeter : " << perimeter << std::endl;
	std::cout << "Square Area : " << area << std::endl;
	std::cout << std::endl;


	Rectangle rectangle(8, 12);
	perimeter = rectangle.getPerimeter();
	area = rectangle.getArea();

	std::cout << std::endl;
	std::cout << "Rectangle Side A : " << rectangle.m_sideA << std::endl;
	std::cout << "Rectangle Side B : " << rectangle.m_sideB << std::endl;
	std::cout << "Rectangle Perimeter : " << perimeter << std::endl;
	std::cout << "Rectangle Area : " << area << std::endl;
	std::cout << std::endl;

	player *frirstPlayer = new player("First", 150, playerClass::support);
	frirstPlayer->printPlayerInfo();
	frirstPlayer->setWeapon(new weapon("Liberator", 1010, 1100));
	
	std::cout << std::endl;
	std::cout << "Weapon of first player" << std::endl;
	std::cout << "Name: " << frirstPlayer->getWeapon()->m_name << std::endl;
	std::cout << "Damage: " << frirstPlayer->getWeapon()->m_damage << std::endl;
	std::cout << "Range: " << frirstPlayer->getWeapon()->m_range << std::endl;
	std::cout << std::endl;

    frirstPlayer->printPlayerInfo();

	team* firstTeam = new team("Nords", 3);
	firstTeam->printTeamInfo();
	
	firstTeam->addPlayer(frirstPlayer);

	firstTeam->printTeamInfo();

	std::cout << std::endl;
	std::cout << "First Player Team: " << frirstPlayer->getTeam();
	std::cout << std::endl;
	
	firstTeam->deletePlayer(frirstPlayer);

	firstTeam->printTeamInfo();

	std::cout << std::endl;
	std::cout << "First Player Team: " << frirstPlayer->getTeam();
	std::cout << std::endl;
}

