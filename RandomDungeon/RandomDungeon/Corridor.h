#pragma once
#include <vector>
#include "Room.h"
class Corridor
{
	Room roomA;
	Room roomB;
public:
	Corridor();
	Corridor(Room a, Room b);
	~Corridor();
};

