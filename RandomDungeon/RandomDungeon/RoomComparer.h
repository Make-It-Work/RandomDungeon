#pragma once
#include "Room.h"
struct RoomWeightComparer {
	bool operator() (Room* a, Room* b) {
		//comparison code here
		//return true als a lagere effort heeft dan b
		return a->minEffort > b->minEffort;
	}
};