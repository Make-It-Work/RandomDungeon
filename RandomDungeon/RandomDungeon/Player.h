#pragma once
#include <string>
#include <map>

class GameObject;

class Player
{
private:
	std::string name;
	int xPosition = 0;
	int yPosition = 0;
	int level = 1;
	int health = 25;
	int xP = 0;
	int attack = 1;
	int defense = 1;
	int alertness = 1;
	std::map<const int, GameObject*> backpack;
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
	GameObject* getWeapon() { return currentWeapon; };
	void getAttacked(int damage);
	void use(int index);
};

