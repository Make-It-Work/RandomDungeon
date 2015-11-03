#pragma once
#include "Player.h"
#include <string>
class Potion
{
private:
	std::string _name = "";
	int gainedHealth = 0;
	int gainedStrength = 0;
	int gainedDefense = 0;
public:
	Potion::Potion(std::string name, int health, int strength, int defense);
	~Potion();

	void setName(std::string name) { _name = name; }
	void setHealth(int health) { gainedHealth = health; }
	void setStrength(int strength) { gainedStrength = strength; }
	void setDefense(int defense) { gainedDefense = defense; }

	std::string getName() { return _name; }

	void drink(Player* player);

};

