#pragma once
#include <string>
#include <vector>
class Room;
class GameDialog
{
private:
	std::vector<std::string> options;
public:
	GameDialog();
	~GameDialog();
	void setOptions(Room* room);
	void setFightOptions(Room* room);
	std::string fightDisplay(Room* room);
	std::string display(Room* room);
};

