#pragma once
#include <vector>
#include "AttributeFactory.h"
class Attribute;

class Room
{
private:
	std::vector<Room*> adjacentRooms;
	int RoomNumber = 0;
	bool wasVisited = false;
	std::string _size = "";
	std::string _dirt = "";
	std::string _lightsource = "";
	std::string _floor = "";
	std::string _decoration = "";
	Attribute* _attribute = nullptr;
	AttributeFactory factory;
public:
	Room();
	~Room();
	void setSize(std::string size);
	std::string getSize();
	void setAttribute(std::string attribute);
	Attribute* getAttribute();
	void addAdjacentRoom(Room * room);
	bool adjacentTo(Room * room);
	void print();
};

