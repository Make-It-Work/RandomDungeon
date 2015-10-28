#include "stdafx.h"
#include "Corridor.h"

Corridor::Corridor() {};

Corridor::Corridor(Room a, Room b)
{
	roomA = a;
	roomB = b;
}


Corridor::~Corridor()
{
}
