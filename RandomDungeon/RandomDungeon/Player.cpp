#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "GameObject.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setName(std::string _name) {
	name = _name;
}

bool Player::executeAction(std::string action)
{
	if (action == "exit") {
		return false;
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
		for each (GameObject* obj in backpack)
		{
			std::cout << obj->getName() << std::endl;
		}
	}
	

	return true;
}
