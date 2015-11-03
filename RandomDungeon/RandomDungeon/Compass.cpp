#include "stdafx.h"
#include "Compass.h"
#include "Room.h"
#include "Layer.h"
#include "Player.h"
#include "Corridor.h"
#include "RoomComparer.h"
#include <queue>
#include <map>

using namespace std;

Compass::Compass()
{
}


Compass::~Compass()
{
}

std::string Compass::use(Layer* l, Player* p) {
	resetEfforts(l, p);
	Room* root = l->getCurrentRoom(p);
	Room* exit = l->getStartRoom();
	priority_queue<Room *, vector<Room *>, RoomWeightComparer> queue;
	vector<Room*> visited;
	map<Room *, Room *> prev;
	queue.push(root);
	root->minEffort = 0;
	string wayOut = "";
	if (root == exit) {
		return "You are already at the exit!";
	}
	while (!queue.empty()) {
		root = queue.top();
		queue.pop();
		for (pair<std::string, Room *> exit : root->getAdjacentRooms()) {
			if (exit.second != nullptr && !containsRoom(visited, exit.second)) {
				if (exit.second->minEffort > root->minEffort + exit.second->getDifficulty()) {
					exit.second->minEffort=root->minEffort + exit.second->getDifficulty();
					prev.insert(make_pair(exit.second, root));
				}
				queue.push(exit.second);
			}
		}
		visited.push_back(root);
	}
	while (prev.find(exit) != prev.end()) {
		wayOut = (prev.at(exit)->getExitName(exit)) + " " + wayOut;
		exit = prev.at(exit);

	}
	return wayOut;
}

bool Compass::containsRoom(vector<Room*> list, Room* r) {
	return find(list.begin(), list.end(), r) != list.end();
}

void Compass::resetEfforts(Layer* l, Player* p) {
	int xCounter = 0;
	int yCounter = 0;
	int vertexCount = l->getVertexCount();
	
	Room*** matrix = l->getMatrix();
	
	for (int i = 0; i < (vertexCount*vertexCount); i++) {
		while (yCounter < vertexCount) {
			xCounter = 0;
			while (xCounter < vertexCount) {
				matrix[xCounter][yCounter]->minEffort = INT_MAX;
				xCounter++;
			}
			yCounter++;
		}
	}
}

//std::string Compass::use(Layer* l, Player* p) {
//	vector<Room*> unvisited;
//	vector<Room*> visited;
//	vector<Corridor*> corridors;
//	map<Room*, Room*> previouses;
//	Room* exit = l->getStartRoom();
//
//	Room* startingPoint = nullptr;
//
//	int xCounter = 0;
//	int yCounter = 0;
//	int vertexCount = l->getVertexCount();
//
//	Room*** matrix = l->getMatrix();
//
//	for (int i = 0; i < (vertexCount*vertexCount); i++) {
//		while (yCounter < vertexCount) {
//			xCounter = 0;
//			while (xCounter < vertexCount) {
//				unvisited.push_back(matrix[xCounter][yCounter]);
//				matrix[xCounter][yCounter]->setPrimPriority(1000000);
//				if (matrix[xCounter][yCounter] == l->getCurrentRoom(p)) {
//					matrix[xCounter][yCounter]->setPrimPriority(0);
//					startingPoint = matrix[xCounter][yCounter];
//				}
//				xCounter++;
//			}
//			yCounter++;
//		}
//	}
//
//	if (startingPoint == exit) {
//		return "Just press exit to leave";
//	}
//
//	while (!unvisited.empty()) {
//		unvisited.erase(std::remove(unvisited.begin(), unvisited.end(), startingPoint), unvisited.end());
//		for each (auto kv in startingPoint->getAdjacentRooms())
//		{
//			Corridor* c = new Corridor(startingPoint, kv.second, kv.second->getDifficulty(), kv.first);
//			c->getRoomB()->setPrimPriority(startingPoint->getPrimPriority() + c->getRoomB()->getDifficulty());
//			corridors.push_back(c);
//		}
//
//		//Corridor* lightest = nullptr;
//		//int lowestPrio = 10000;
//		for each (Corridor* c in corridors)
//		{
//			if (std::find(visited.begin(), visited.end(), c->getRoomB()) == visited.end()) {
//				/* not yet visited the other side of the corridor */
//				if (c->getRoomB()->getPrimPriority() < startingPoint->getPrimPriority() + c->getRoomB()->getDifficulty())
//				{
//					c->getRoomB()->setPrimPriority(startingPoint->getPrimPriority() + c->getRoomB()->getDifficulty());
//					startingPoint = c->getRoomB();
//					previouses[c->getRoomB()] = c->getRoomA();
//				}
//			}
//		}
//
//		visited.push_back(startingPoint);
//		
//		string wayOut = "";
//		bool found = false;
//		Room* prev = nullptr;
//		for each (auto kv in previouses)
//		{
//			if (kv.second == exit)
//			{
//				prev = kv.first;
//			}
//		}
//
//		while (prev != nullptr) {
//			for each (auto kv in prev->getAdjacentRooms())
//			{
//				if (kv.second == exit)
//				{
//					wayOut = kv.first + " " + wayOut;
//				}
//			}
//			exit = prev;
//		}
//		return wayOut;
//	}
//}