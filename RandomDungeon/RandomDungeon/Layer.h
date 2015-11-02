#pragma once
#include <vector>
#include "Room.h"
#include "Corridor.h"
#include "RoomGenerator.h"
#include "EnemyGenerator.h"
#include "ObjectGenerator.h"
class Player;

class Layer
{
private:
	bool** _adjacencyMatrix;
	int _vertexCount;
	Room*** _roomMatrix = nullptr;
	RoomGenerator* gen = new RoomGenerator();
	EnemyGenerator* enem = new EnemyGenerator();
	ObjectGenerator* obj = new ObjectGenerator();
public:
	Layer();
	Layer(int vertextCount);
	void addEnemies(int vertexCount);
	void addObjects(int vertexCount);
	~Layer();

	void createConnection(Room * rooma, Room * roomb, std::string dirab, std::string dirba);
	void addRoom(int a, int b);
	void removeRoom(int a, int b);

	Room* getCurrentRoom(Player* player);

	void init();
	void draw();
	bool canMove(std::string action, Player* player);
};

