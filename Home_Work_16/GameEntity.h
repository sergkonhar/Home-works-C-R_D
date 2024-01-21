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
	weapon(const std::string& name, int damage, int range);

	void printWeaponInfo();

private:
	std::string m_name;
	int m_damage;
	int m_range;
};

class player 
{
public:

	player();
	player(const std::string& name, int healtPoints, playerClass playerClass);
	~player();

	void setWeapon(weapon* weaponToAdd);
	weapon* getWeapon() const;

	void setTeam(const std::string& team);
	void removeFromTeam();
	std::string getTeam() const;

	std::string getName();

	void printPlayerInfo() const;
	
private:	
	int m_healtPoints;
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

private:
	std::string m_name;
	int m_maxMembers;
	std::vector<player*> m_teamMembers;

};