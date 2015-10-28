#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <string>
#include "Attribute.h"
#include <algorithm>

using namespace std;

Room::Room()
{
}

Room::~Room()
{
	delete _attribute;
}

void Room::setSize(string size)
{
	_size = size;
}

std::string Room::getSize()
{
	return _size;
}

void Room::setAttribute(string attribute)
{
	_attribute = factory.createAttribute(attribute);
}

Attribute* Room::getAttribute()
{
	return _attribute;
}

void Room::addAdjacentRoom(Room* room) {
	adjacentRooms.push_back(room);
	std::cout << "";
}

bool Room::adjacentTo(Room* room) {
	if (!adjacentRooms.empty()) {
		return std::find(adjacentRooms.begin(), adjacentRooms.end(), room) != adjacentRooms.end();
	}
	return false;
}

void Room::print() {
	std::cout << "You are in a " + _size + "-sized room.";
	if (_attribute->getName() != "none") {
		std::cout << " In the corner is a " + _attribute->getName();
	}
	std::cout << std::endl;
}
