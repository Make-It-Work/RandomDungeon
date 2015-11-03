#include "stdafx.h"
#include "Layer.h"
#include "Player.h"
#include <iostream>

Layer::Layer()
{
}

Layer::Layer(int vertexCount) {
	_vertexCount = vertexCount;
	_adjacencyMatrix = new bool*[vertexCount];
	for (int i = 0; i < vertexCount; i++) {
		_adjacencyMatrix[i] = new bool[vertexCount];
		for (int j = 0; j < vertexCount; j++) {
			_adjacencyMatrix[i][j] = false;
		}
	}

	int xCounter = 0;
	int yCounter = 0;
	_roomMatrix = new Room**[vertexCount];
	for (int i = 0; i < (vertexCount); i++) {
		_roomMatrix[i] = new Room*[vertexCount];
	}
	while (yCounter < vertexCount) {
		xCounter = 0;
		while (xCounter < vertexCount) {
			addRoom(xCounter, yCounter);
			xCounter++;
		}
		yCounter++;
	}

	yCounter = 0;
	for (int i = 0; i < (vertexCount*vertexCount); i++) {
		while (yCounter < vertexCount) {
			xCounter = 0;
			while (xCounter < vertexCount) {
				Room* currentRoom = _roomMatrix[xCounter][yCounter];
				//Decide connection upwards
				if (!yCounter - 1 < 0 && !currentRoom->adjacentTo(_roomMatrix[xCounter][yCounter-1])) {
					int RandIndex = rand() % 4; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter][yCounter - 1], "up", "down");
					}
				}
				//Decide connection downwards
				if (yCounter + 1 < vertexCount && !currentRoom->adjacentTo(_roomMatrix[xCounter][yCounter + 1])) {
					int RandIndex = rand() % 4; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter][yCounter + 1], "down", "up");
					}
				}
				//Decide connection left
				if (!xCounter - 1 < 0 && !currentRoom->adjacentTo(_roomMatrix[xCounter - 1][yCounter])) {
					int RandIndex = rand() % 4; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter - 1][yCounter], "left", "right");
					}
				}
				//Decide connection right
				if (xCounter + 1 < vertexCount && !currentRoom->adjacentTo(_roomMatrix[xCounter + 1][yCounter])) {
					int RandIndex = rand() % 4; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter + 1][yCounter], "right", "left");
					}
				}
				xCounter++;
			}
			yCounter++;
		}
	}
	addEnemies(vertexCount);
	addObjects(vertexCount);
	addTraps(vertexCount);
	startRoom = _roomMatrix[0][0];
}

void Layer::addEnemies(int vertexCount) {
	int area = vertexCount * vertexCount;
	int amountOfEnemies = area / 2;
	int counter = 0;
	while (counter < amountOfEnemies) {
		bool hasPlaced = false;
		int xIndex = rand() % vertexCount;
		int yIndex = rand() % vertexCount;
		Enemy* enemy = enem->createEnemy();
		while (_roomMatrix[xIndex][yIndex]->hasEnemy() && !hasPlaced) {
			int xIndex = rand() % vertexCount;
			int yIndex = rand() % vertexCount;
			hasPlaced = true;
		}
		_roomMatrix[xIndex][yIndex]->addEnemy(enemy);
		enemy = nullptr;
		hasPlaced = true;
		counter++;
	}
}

void Layer::addObjects(int vertexCount) {
	int area = vertexCount * vertexCount;
	int amountOfObjects = area / 3;
	int counter = 0;
	while (counter < amountOfObjects) {
		bool hasPlaced = false;
		int xIndex = rand() % vertexCount;
		int yIndex = rand() % vertexCount;
		GameObject* object = obj->createObject();
		while (_roomMatrix[xIndex][yIndex]->hasObject() && !hasPlaced) {
			int xIndex = rand() % vertexCount;
			int yIndex = rand() % vertexCount;
			hasPlaced = true;
		}
		_roomMatrix[xIndex][yIndex]->addObject(object);
		object = nullptr;
		hasPlaced = true;
		counter++;
	}
}

void Layer::addTraps(int vertexCount) {
	int area = vertexCount * vertexCount;
	int amountOfTraps = area / 5;
	int counter = 0;
	while (counter < amountOfTraps) {
		bool hasPlaced = false;
		int xIndex = rand() % vertexCount;
		int yIndex = rand() % vertexCount;
		Trap* t = trap->createTrap();
		while (_roomMatrix[xIndex][yIndex]->hasTrap() && !hasPlaced) {
			int xIndex = rand() % vertexCount;
			int yIndex = rand() % vertexCount;
			hasPlaced = true;
		}
		_roomMatrix[xIndex][yIndex]->addTrap(t);
		t = nullptr;
		hasPlaced = true;
		counter++;
	}
}

void Layer::createConnection(Room* rooma, Room* roomb, std::string dirab, std::string dirba) {
	rooma->addAdjacentRoom(roomb, dirab);
	roomb->addAdjacentRoom(rooma, dirba);
}

void Layer::addRoom(int a, int b) {
	if (a >= 0 && a < _vertexCount && b >= 0 && b < _vertexCount) {
		Room* r = gen->createRoom();
		_roomMatrix[a][b] = r;
	}
}

void Layer::removeRoom(int a, int b) {
	if (a >= 0 && a < _vertexCount && b > 0 && b < _vertexCount) {
		_roomMatrix[a][b] = false;
		_roomMatrix[b][a] = false;
	}
}

void Layer::init() {
	
}

void Layer::draw()
{
}

bool Layer::canMove(std::string action, Player* player) {
	std::string direction = action.substr(5);
	int curX = player->getXPosition();
	int curY = player->getYPosition();

	if (direction == "up") {
		if (!curY - 1 < 0) {
			return _roomMatrix[curX][curY]->adjacentTo(_roomMatrix[curX][curY - 1]);
		}
	}
	else if (direction == "down") {
		if (curY + 1 < _vertexCount) {
			return _roomMatrix[curX][curY]->adjacentTo(_roomMatrix[curX][curY + 1]);
		}
	}
	else if (direction == "left") {
		if (!curX - 1 < 0) {
			return _roomMatrix[curX][curY]->adjacentTo(_roomMatrix[curX - 1][curY]);
		}
	}
	else if (direction == "right") {
		if (curX + 1 < _vertexCount) {
			return _roomMatrix[curX][curY]->adjacentTo(_roomMatrix[curX + 1][curY]);
		}
	}
	return false;
}

Room* Layer::getCurrentRoom(Player* player) {
	int xPos = player->getXPosition();
	int yPos = player->getYPosition();
	return _roomMatrix[xPos][yPos];
}

Layer::~Layer()
{
	for (int i = 0; i < _vertexCount; i++) {
		delete[] _adjacencyMatrix[i];
		int y = 0;
		while (y < _vertexCount) {
			delete _roomMatrix[i][y];
			_roomMatrix[i][y] = nullptr;
			y++;
		}
		delete[] _roomMatrix[i];
	}
	
	delete trap;
	delete obj;
	delete enem;
	delete gen;
	delete[] _roomMatrix;
	startRoom = nullptr;
	delete[] _adjacencyMatrix;
}
