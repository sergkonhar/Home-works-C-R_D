#include <string>
#include <vector>

enum class playerClass 
{
	assault,
	medic,
	support,
	sniper
};

class weapon 
{
public:

	weapon();
	weapon(std::string name, int damage, int range);

	std::string m_name;
	int m_damage;
	int m_range;
};

class player 
{
public:

	player();
	player(std::string name, int healtPoints, playerClass playerClass);
	~player();

	void setWeapon(weapon* weaponToAdd);
	weapon* getWeapon() const;

	void setTeam(std::string team);
	void removeFromTeam();
	std::string getTeam() const;

	std::string getName();

	void printPlayerInfo() const;
	
	int m_healtPoints;

private:	
	std::string m_name;
	std::string m_team;
	weapon *m_activeWeapon;
	playerClass m_playerClass;
};

class team 
{	
public:

	team();
	team(std::string name, int maxMembers);

	~team();

	bool addPlayer(player* addPlayer);
	bool deletePlayer(player* removePlayer);

	void printTeamInfo();

	std::string m_name;
	int m_maxMembers;
	std::vector<player*> m_teamMembers;

};