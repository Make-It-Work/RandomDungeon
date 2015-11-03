#include "stdafx.h"
#include "Player.h"
#include "Potion.h"
#include <iostream>
#include "GameObject.h"


Player::Player()
{
	Potion* po = new Potion("strengthPotion", 0, 3, 0);
	Potion* ti = new Potion("healthPotion", 3, 0, 0);
	Potion* on = new Potion("defensePotion", 0, 0, 3);
	potions[1] = po;
	potions[2] = ti;
	potions[3] = on;
}


Player::~Player()
{
	delete currentWeapon;
	for each (auto potion in potions)
	{
		delete potion.second;
	}
	potions.clear();
	for each (auto item in backpack)
	{
		delete item.second;
	}
	backpack.clear();
}

void Player::addToBackpack(GameObject * go)
{
	backpack.insert(std::make_pair(backpack.size() + 1, go));
}

void Player::setName(std::string _name) {
	name = _name;
}

bool Player::executeAction(std::string action)
{
	if (action == "info") {
		getInfo();
	}
	else if (action == "rest") {
		rest();
	}
	else if (action.find("use") == 0) {
		int weaponNumber = std::stoi(action.substr(4));
		use(weaponNumber);
	}
	else if (action.find("drink") == 0) {
		int potionNumber = std::stoi(action.substr(6));
		drink(potionNumber);
	}
	else if (action.find("move") == 0) {
		std::string direction = action.substr(5);

		if (direction == "up") {
			yPosition--;
		}
		else if (direction == "down") {
			yPosition++;
		}
		else if (direction == "left") {
			xPosition--;
		}
		else if (direction == "right") {
			xPosition++;
		}
	}
	else if (action == "inventory") {
		std::cout << "Your inventory contains:" << std::endl;
		for each (auto kv in backpack)
		{
			GameObject* obj = kv.second;
			std::cout << kv.first << " A " + obj->getMaterial() + " " + obj->getName() + " with a handle made of " + obj->getHandle() << std::endl;
		}
		std::cout << "Your still have the following potions:" << std::endl;
		for each (auto kv in potions)
		{
			Potion* obj = kv.second;
			std::cout << kv.first << " A " + obj->getName() << std::endl;
		}
	}
	return true;
}

void Player::getAttacked(int damage) {
	health -= (damage - defense);
}

int Player::getHealth() {
	return health;
}
int Player::getStrength() {
	return strength;
}
int Player::getDefense() {
	return defense;
}
void Player::setHealth(int nhealth) {
	health = nhealth;
}
void Player::setDefense(int ndefense) {
	defense = ndefense;
}
void Player::setStrength(int nstrength) {
	strength = nstrength;
}

void Player::getInfo() {
	std::cout << name << "'s statistics:" << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Defense: " << defense << std::endl;
}

void Player::use(int index) {
	currentWeapon = backpack[index];
}

void Player::drink(int index) {
	if (potions[index] == nullptr) {
		std::cout << "You can't drink a non-existing potion." << std::endl;
	}
	else {
		potions[index]->drink(this);
		delete potions[index];
		potions[index] = nullptr;
		std::cout << "You drank a potion." << std::endl;
	}
}

void Player::rest() {
	if (health < maxHealth) {
		health++;
	}
}

bool Player::exit(Room* curRoom, Room* end)
{
	if (talisman.use(curRoom, end) == 0) {
		return false;
	}
	return true;
}
