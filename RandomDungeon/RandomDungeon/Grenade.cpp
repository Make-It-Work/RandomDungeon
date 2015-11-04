#include "stdafx.h"
#include "Grenade.h"
#include "Room.h"
#include "Layer.h"
#include "Player.h"
#include <list>
#include <map>
#include <iostream>

Grenade::Grenade()
{
}


Grenade::~Grenade()
{
}

void Grenade::use(Layer* l, Player* p) {
	std::list<Room*> queue;
	std::list<Room*> visited;
	std::list<Corridor*> corridors;
	std::list<Corridor*> minSpanningCors;
	int xCounter = 0;
	int yCounter = 0;
	int vertexCount = l->getVertexCount();

	Room*** matrix = l->getMatrix();

	for (int i = 0; i < (vertexCount*vertexCount); i++) {
		while (yCounter < vertexCount) {
			xCounter = 0;
			while (xCounter < vertexCount) {
				queue.push_back(matrix[xCounter][yCounter]);
				matrix[xCounter][yCounter]->setPrimPriority(1000000);
				if (matrix[xCounter][yCounter] == l->getCurrentRoom(p)) {
					matrix[xCounter][yCounter]->setPrimPriority(0);
				}
				xCounter++;
			}
			yCounter++;
		}
	}

	visited.push_back(l->getCurrentRoom(p));

	while (!queue.empty()) {
		Room* start = queue.front();
		queue.pop_front();

		for each (auto kv in start->getAdjacentRooms())
		{
			
				Corridor* c = new Corridor(start, kv.second, kv.second->getDifficulty(), kv.first);
				corridors.push_back(c);
			
		}

		Corridor* lightest = nullptr;
		for each (Corridor* cor in corridors)
		{
			if (std::find(visited.begin(), visited.end(), cor->getRoomB()) == visited.end()) {
				/* not yet visited the other side of the corridor */
				if (cor->getDirection() == "right" || cor->getDirection() == "down") {
					if (lightest == nullptr || cor->getWeight() < lightest->getWeight()) {
						lightest = cor;
					}
				}
			}
		}
		
		if (lightest != nullptr) {
			minSpanningCors.push_back(lightest);
			visited.push_back(lightest->getRoomB());
		}
	}

	if (corridors.size() == minSpanningCors.size()) {
		std::cout << "Cannot use the grenade without locking yourself in" << std::endl;
	}
	else {
		int removed = 0;


		for each (Corridor* cor in corridors)
		{
			if (removed < 10 && std::find(minSpanningCors.begin(), minSpanningCors.end(), cor) == minSpanningCors.end()) {
				removed++;
				cor->getRoomA()->destroyCorridor(cor->getDirection());
			}
			delete cor;
		}
		corridors.clear();
		minSpanningCors.clear();

		std::cout << "used grenade" << std::endl;
	}

}
