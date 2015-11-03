#include "stdafx.h"
#include "Corridor.h"

Corridor::Corridor() {};

Corridor::Corridor(Room* a, Room* b, int weight, const std::string direction)
{
	roomA = a;
	roomB = b;
	_weight = weight;
	_direction = direction;
}


Corridor::~Corridor()
{
}
