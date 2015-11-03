#pragma once
#include <string>
#include <map>
class Enemy
{
private:
	int level = 0;
	int health = 0;
	int sensitivity = 0; //How many health will be lost when hit.
	int strength = 0; //How many health the player will lose when hit.
	std::string name = "";
	int type = 0;
public:
	int attack();
	bool hit();
	bool stabbed(int weaponStrength);
	bool checkAlive();
	std::string getName() { return name; }
	int getStrength() { return strength; }
	void setProperties(std::map<std::string, std::string>);
	Enemy();
	~Enemy();
};

