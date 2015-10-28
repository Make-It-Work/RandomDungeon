#pragma once
#include <string>
class Player
{
private:
	std::string name;
	int xPosition = 0;
	int yPosition = 0;
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

