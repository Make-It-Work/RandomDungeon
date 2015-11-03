#pragma once
#include <vector>
#include <map>
#include "AttributeFactory.h"
#include "Enemy.h"

class Trap;
class Attribute;
class GameObject;

class Room
{
private:
	std::map<std::string, Room*> adjacentRooms;
	std::map<std::string, Room*> blockedAdjacentRooms;
	int primPriority = 10000000;
	Enemy* _enemy = nullptr;
	bool wasVisited = false;
	std::string _size = "";
	std::string _dirt = "";
	std::string _lightsource = "";
	std::string _floor = "";
	std::string _decoration = "";
	Attribute* _attribute = nullptr;
	AttributeFactory factory;
	GameObject* _object = nullptr;
	Trap* _trap = nullptr;
public:
	Room();
	~Room();
	void setSize(std::string size);
	std::string getSize();
	void setAttribute(std::string attribute);
	Attribute* getAttribute();
	void addAdjacentRoom(Room * room, std::string direction);
	void destroyCorridor(std::string direction);
	bool adjacentTo(Room * room);
	void addEnemy(Enemy* enemy);
	void addObject(GameObject* object);
	void removeObject();
	void print();
	GameObject* search();
	void destroyEnemy();
	void addTrap(Trap * trap);
	bool hasTrap();
	int doTrap();
	int getDifficulty();

	void setDirt(std::string dirt) { 
		_dirt = dirt; 
	};
	std::string getDirt() {	
		return _dirt; 
	};
	void setLightsource(std::string light) { 
		_lightsource = light; 
	};
	std::string getLightsource() {
		return _lightsource;
	};
	void setFloor(std::string floor) {
		_floor = floor;
	};
	std::string getFloor() {
		return _floor;
	};
	void setDecoration(std::string dec) {
		_decoration = dec;
	};
	std::string getDecoration() {
		return _decoration;
	};
	std::map<std::string, Room*> getAdjacentRooms() {
		return adjacentRooms;
	}
	Enemy* getEnemy() { 
		return _enemy; 
	}
	GameObject* getObject() { 
		return _object; 
	}
	int getPrimPriority() {
		return primPriority;
	}
	void setPrimPriority(int prio) {
		primPriority = prio;
	}
	bool hasEnemy() { return _enemy != nullptr; }
	bool hasObject() { return _object != nullptr; }
	bool hasRight();
	bool hasDown();
};

