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
				_roomMatrix[xCounter][yCounter]->print();
				Room* currentRoom = _roomMatrix[xCounter][yCounter];
				//Decide connection upwards
				if (!yCounter - 1 < 0 && !currentRoom->adjacentTo(_roomMatrix[xCounter][yCounter-1])) {
					int RandIndex = rand() % 3; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter][yCounter - 1]);
						std::cout << "Room " << xCounter << "," << yCounter << " has connection up." << std::endl;
					}
				}
				//Decide connection downwards
				if (!yCounter + 1 >= vertexCount && !currentRoom->adjacentTo(_roomMatrix[xCounter][yCounter + 1])) {
					int RandIndex = rand() % 3; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter][yCounter + 1]);
						std::cout << "Room " << xCounter << "," << yCounter << " has connection down." << std::endl;
					}
				}
				//Decide connection left
				if (!xCounter - 1 < 0 && !currentRoom->adjacentTo(_roomMatrix[xCounter - 1][yCounter])) {
					int RandIndex = rand() % 3; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter - 1][yCounter]);
						std::cout << "Room " << xCounter << "," << yCounter << " has connection left." << std::endl;
					}
				}
				//Decide connection right
				if (!xCounter + 1 >= vertexCount && !currentRoom->adjacentTo(_roomMatrix[xCounter + 1][yCounter])) {
					int RandIndex = rand() % 3; //generates a random number between 0 and 2
					if (RandIndex != 1) {
						createConnection(currentRoom, _roomMatrix[xCounter + 1][yCounter]);
						std::cout << "Room " << xCounter << "," << yCounter << " has connection right." << std::endl;
					}
				}
				xCounter++;
			}
			yCounter++;
		}
	}
}

void Layer::createConnection(Room* rooma, Room* roomb) {
	rooma->addAdjacentRoom(roomb);
	roomb->addAdjacentRoom(rooma);
}

void Layer::addRoom(int a, int b) {
	if (a >= 0 && a < _vertexCount && b >= 0 && b < _vertexCount) {
		Room* r = gen.createRoom();
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

	delete[] _roomMatrix;
	delete[] _adjacencyMatrix;
}
