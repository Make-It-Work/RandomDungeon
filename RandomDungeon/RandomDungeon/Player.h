#pragma once
#include <string>
#include <vector>

class GameObject;

class Player
{
private:
	std::string name;
	int xPosition = 0;
	int yPosition = 0;
	int level = 1;
	int health = 50;
	int xP = 0;
	int attack = 1;
	int defense = 1;
	int alertness = 1;
	std::vector<GameObject*> backpack;
public:
	Player();
	~Player();
	void setName(std::string);
	bool executeAction(std::string);
	int getXPosition() {
		return xPosition;
	}
	int getYPosition() {
		return yPosition;
	}
};

