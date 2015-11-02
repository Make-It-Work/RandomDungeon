#pragma once
#include <map>
#include <vector>
class Room;

class RoomGenerator
{
private:
	std::vector<std::string> keys = { "size", "attribute", "dirt", "lightsource", "floor", "decoration"};
	std::map<std::string, std::vector<std::string>> properties;
public:
	RoomGenerator();
	~RoomGenerator();
	Room* createRoom();
};

