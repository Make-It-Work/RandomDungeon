#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "GameObject.h"


Player::Player()
{
}


Player::~Player()
{
	backpack.clear();
}

void Player::addToBackpack(GameObject * go)
{
	backpack.insert(std::make_pair(backpack.size() + 1, go));
}

void Player::setName(std::string _name) {
	name = _name;
}

bool Player::executeAction(std::string action)
{
	if (action == "exit") {
		return false;
	}
	else if (action.find("use") == 0) {
		int weaponNumber = std::stoi(action.substr(4));
		use(weaponNumber);
	}
	else if (action.find("move") == 0) {
		std::string direction = action.substr(5);

		if (direction == "up") {
			yPosition--;
		}
		else if (direction == "down") {
			yPosition++;
		}
		else if (direction == "left") {
			xPosition--;
		}
		else if (direction == "right") {
			xPosition++;
		}
	}
	else if (action == "inventory") {
		std::cout << "Your inventory contains:" << std::endl;
		for each (auto kv in backpack)
		{
			GameObject* obj = kv.second;
			std::cout << kv.first << " A " + obj->getMaterial() + " " + obj->getName() + " with a handle made of " + obj->getHandle() << std::endl;
		}
	}
	return true;
}

void Player::getAttacked(int damage) {
	health -= damage;
}

int Player::getHealth() {
	return health;
}

void Player::use(int index) {
	currentWeapon = backpack[index];
}
