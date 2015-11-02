#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <string>
#include "Attribute.h"
#include "GameObject.h"
#include <algorithm>
#include "Enemy.h"

using namespace std;

Room::Room()
{
}

Room::~Room()
{
	delete _enemy;
	delete _attribute;
	delete _object;
	adjacentRooms.clear();
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

void Room::addAdjacentRoom(Room* room, std::string direction) {
	adjacentRooms[direction] = room;
}

bool Room::adjacentTo(Room* room) {
	if (!adjacentRooms.empty()) {
		for (auto kv : adjacentRooms) {
			if (kv.second == room) {
				return true;
			}
		}
	}
	return false;
}

void Room::addEnemy(Enemy* enemy) {
	_enemy = enemy;
}

void Room::addObject(GameObject * object)
{
	_object = object;
}

void Room::removeObject() {
	_object = nullptr;
}

void Room::print() {
	std::cout << std::endl << "You are in a " + _size + "-sized room.";
	if (_attribute->getName() != "none") {
		std::cout << " In the corner is a " + _attribute->getName() <<". ";
	}
	std::cout << "The floor is made of " << _floor << ". ";
	if (_dirt != "none") {
		std::cout << "The room is covered in " << _dirt << ". ";
	}
	if (_lightsource != "none") {
		std::cout << "There is a little light coming from the " + _lightsource;
	}
	else {
		std::cout << "The room is pitch black";
	}
	std::cout << ". ";
	if (_decoration != "none") {
		std::cout << "There's a " << _decoration << " against the wall. ";
	}
	std::cout << std::endl;
	std::cout << "You can move ";
	for each (auto kv in adjacentRooms) {
		std::cout << kv.first << " ";
	}
	std::cout << std::endl;
	if (_enemy != nullptr) {
		std::cout << "There is a " << _enemy->getName() << " here" << std::endl;
	}
}

GameObject* Room::search() {
	if (_object != nullptr) {
		std::cout << "There is a " << _object->getName() << " here. This will be added to your inventory.";
	}
	return _object;
}

void Room::destroyEnemy() {
	_enemy = nullptr;
}
