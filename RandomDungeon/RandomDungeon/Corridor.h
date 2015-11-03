#pragma once
#include <vector>
#include "Room.h"
class Corridor
{
	Room* roomA;
	Room* roomB;
	int _weight;
	std::string _direction;
public:
	Corridor();
	Corridor(Room* a, Room* b, int weight, const std::string direction);
	~Corridor();

	Room* getRoomA() { return roomA; }
	Room* getRoomB() { return roomB; }
	int getWeight() { return _weight; }
	std::string getDirection() { return _direction; }
};

