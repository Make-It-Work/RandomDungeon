#include "stdafx.h"
#include "Talisman.h"
#include "Room.h"
#include <vector>
#include <map>
#include <list>
#include <iostream>

Talisman::Talisman()
{
}


Talisman::~Talisman()
{
}

int Talisman::use(Room* currentRoom, Room* endRoom) {
	//Ik navigeer naar de startkamer van het spel, aangezien ik geen lagen in de kerker hoefde te maken. Het principe van het algoritme blijft hetzelfde.
	int distance = 0;
	if (currentRoom == endRoom) {
		distance = 0;
	}
	else {
		std::list<Room*> queue;
		std::map<Room*, Room*> previousRooms; //Key = room, Value is previous room
		std::vector<Room*> visited;

		queue.push_back(currentRoom);
		bool found = false;
		while (!queue.empty() && !found) {
			Room* room = queue.front();
			queue.pop_front();
			visited.push_back(room);

			std::map<std::string, Room*> adjacent = room->getAdjacentRooms();
			for each (auto kv in adjacent)
			{
				if (!found && std::find(visited.begin(), visited.end(), kv.second) == visited.end() && std::find(queue.begin(), queue.end(), kv.second) == queue.end()) {
					
					if (kv.second == endRoom) {
						found = true;
					}
					previousRooms[kv.second] = room;
					queue.push_back(kv.second);
				}
			}
		}
		bool finished = false;
		Room* r = endRoom;
		while (!finished) {
			if (previousRooms.find(r) == previousRooms.end()) {
				// not found
				finished = true;
			}
			else {
				// found
				r = previousRooms[r];
				distance++;
			}
		}
	}
	return distance;
}
