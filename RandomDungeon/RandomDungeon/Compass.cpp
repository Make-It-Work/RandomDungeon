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
	int enemies = 0;
	std::string enemyHealth = " enemies: ";
	int traps = 0;
	while (prev.find(exit) != prev.end()) {
		wayOut = (prev.at(exit)->getExitName(exit)) + " " + wayOut;
		if (prev.at(exit)->hasEnemy()) {
			enemies++;
			enemyHealth = enemyHealth + std::to_string(prev.at(exit)->getEnemy()->getHealth());
		}
		if (prev.at(exit)->hasTrap()) {
			traps++;
		}
		exit = prev.at(exit);
	}
	wayOut = wayOut + ", " + std::to_string(enemies) + enemyHealth + ", " + std::to_string(traps) +" traps";
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

vector<Room*> Compass::returnPath(Layer* l, Player* p) {
	vector<Room*> path;
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
		return path;
	}
	while (!queue.empty()) {
		root = queue.top();
		queue.pop();
		for (pair<std::string, Room *> exit : root->getAdjacentRooms()) {
			if (exit.second != nullptr && !containsRoom(visited, exit.second)) {
				if (exit.second->minEffort > root->minEffort + exit.second->getDifficulty()) {
					exit.second->minEffort = root->minEffort + exit.second->getDifficulty();
					prev.insert(make_pair(exit.second, root));
				}
				queue.push(exit.second);
			}
		}
		visited.push_back(root);
	}
	while (prev.find(exit) != prev.end()) {
		//wayOut = (prev.at(exit)->getExitName(exit)) + " " + wayOut;
		path.push_back(prev.at(exit));
		exit = prev.at(exit);

	}
	return path;
}