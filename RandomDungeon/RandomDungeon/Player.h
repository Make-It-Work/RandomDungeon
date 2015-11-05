#pragma once
#include <string>
#include <map>
#include <vector>
#include "Talisman.h"
#include "Grenade.h"
#include "Compass.h"

class GameObject;
class Potion;
class Player
{
private:
	std::string name;
	int xPosition = 0;
	int yPosition = 0;
	int level = 1;
	int maxHealth = 25;
	int health = 25;
	int xP = 0;
	int strength = 1;
	int defense = 1;
	int alertness = 1;
	std::map<const int, GameObject*> backpack;
	std::map<const int, Potion*> potions;
	GameObject* currentWeapon = nullptr;
public:
	Player();
	~Player();
	void addToBackpack(GameObject* go);
	void setName(std::string);
	bool executeAction(std::string);
	int getXPosition() {
		return xPosition;
	}
	int getYPosition() {
		return yPosition;
	}
	int getHealth();
	int getStrength();
	int getDefense();
	void setHealth(int nhealth);
	void setDefense(int ndefense);
	void setStrength(int nstrength);
	void getInfo();
	GameObject* getWeapon() { return currentWeapon; };
	void getAttacked(int damage);
	void use(int index);
	void drink(int index);
	void rest();
	bool exit(Room* curRoom, Room* end);
	Talisman talisman;
	Grenade grenade;
	Compass compass;
};

