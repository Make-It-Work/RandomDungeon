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
	void setOptions();
	std::string display(Room* room);
	bool executeCommand(std::string command);
};

