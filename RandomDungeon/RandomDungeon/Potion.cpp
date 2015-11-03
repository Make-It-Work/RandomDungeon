#include "stdafx.h"
#include "Potion.h"
#include "Player.h"


Potion::Potion(std::string name, int health, int strength, int defense)
{
	_name = name;
	gainedHealth = health;
	gainedStrength = strength;
	gainedDefense = defense;
}


Potion::~Potion()
{
}

void Potion::drink(Player * player)
{
	player->setHealth(player->getHealth() + gainedHealth);
	player->setStrength(player->getStrength()+ gainedStrength);
	player->setHealth(player->getDefense() + gainedDefense);
}
