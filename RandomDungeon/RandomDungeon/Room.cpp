#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <string>
#include "Attribute.h"
#include "GameObject.h"
#include <algorithm>
#include "Enemy.h"
#include "Trap.h"
#include "Attribute.h"
#include "GameObject.h"

using namespace std;

Room::Room()
{
}

Room::~Room()
{
	if (_enemy != nullptr) {
		delete _enemy;
		_enemy = nullptr;
	}
	if (_attribute != nullptr) {
		delete _attribute;
		_attribute = nullptr;
	}
	if (_object != nullptr) {
		delete _object;
		_object = nullptr;
	}
	if (_trap != nullptr) {
		delete _trap;
		_trap = nullptr;
	}
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

void Room::destroyCorridor(std::string direction)
{
	Room* r = adjacentRooms[direction];
	adjacentRooms.erase(direction);
	blockedAdjacentRooms[direction] = r;
}

std::string Room::getExitName(Room* r) {
	for each (auto kv in adjacentRooms)
	{
		if (kv.second == r) {
			return kv.first;
		}
	}
	return "";
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

void Room::addTrap(Trap* trap) {
	_trap = trap;
}

bool Room::hasTrap() {
	if (_trap != nullptr) {
		return true;
	}
	return false;
}

int Room::doTrap() {
	if (_trap != nullptr) {
		std::cout << "You've " << _trap->getAction() << " " << _trap->getDescription() << " a " << _trap->getName();
		int rv = _trap->getDamage();
		delete _trap;
		_trap = nullptr;
		return rv;
	}
	return 0;
}

int Room::getDifficulty() {
	int diff = 0;
	if (_trap != nullptr) {
		diff += _trap->getDamage();
	}
	if (_enemy != nullptr) {
		diff += _enemy->getStrength();
	}
	return diff;
}

bool Room::hasRight() {
	if (adjacentRooms.find("right") == adjacentRooms.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool Room::hasDown() {
	if (adjacentRooms.find("down") == adjacentRooms.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool Room::hasBlockedRight() {
	if (blockedAdjacentRooms.find("right") == blockedAdjacentRooms.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool Room::hasBlockedDown() {
	if (blockedAdjacentRooms.find("down") == blockedAdjacentRooms.end()) {
		return false;
	}
	else {
		return true;
	}
}
