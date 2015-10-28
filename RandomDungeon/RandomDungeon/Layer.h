#pragma once
#include <vector>
#include "Room.h"
#include "Corridor.h"
#include "RoomGenerator.h"

class Player;

class Layer
{
private:
	bool** _adjacencyMatrix;
	int _vertexCount;
	Room*** _roomMatrix = nullptr;
	RoomGenerator gen;
public:
	Layer();
	Layer(int vertextCount);
	~Layer();

	/*void addCorridor(int a, int b);
	void removeCorridor(int a, int b);
	bool isCorridor(int a, int b);*/
	void createConnection(Room * rooma, Room * roomb);
	void addRoom(int a, int b);
	void removeRoom(int a, int b);

	Room* getCurrentRoom(Player* player);

	void init();
	bool canMove(std::string action, Player* player);
};

