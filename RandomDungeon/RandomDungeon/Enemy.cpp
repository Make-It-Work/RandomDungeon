#include "stdafx.h"
#include "Enemy.h"
#include <string>
#include <map>
#include <iostream>

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

int Enemy::attack() {
	std::cout << "ATTACK " << strength << std::endl;
	return strength;
}
bool Enemy::hit() {
	if (level <= 4) {
		health -= sensitivity;
		if (checkAlive()) {
			std::cout << "You have done a little damage to your enemy, but he's still alive" << std::endl;
			return true;
		}
		else {
			std::cout << "You killed the " << name << "." << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Your enemy blinks his eyes in shock, but is still as strong as before" << std::endl;
	}
	return checkAlive();
}

bool Enemy::stabbed(int weaponStrength) {
	if (level <= 8) {
		health -= weaponStrength;
		if (checkAlive()) {
			std::cout << "You have done a little damage to your enemy, but he's still alive" << std::endl;
			return false;
		}
		else {
			std::cout << "You killed the " << name << "." << std::endl;
			return true;
		}
	}
	else {
		std::cout << "Your scratching has no effect on the enemy, except getting more ugly by the minute." << std::endl;
	}
}

bool Enemy::checkAlive() {
	if (health <= 0) {
		return false;
	} 
	return true;
}

void Enemy::setProperties(std::map<std::string, std::string> props) {
	for (auto kv : props) {
		if (kv.first == "level") {
			level = std::stoi(kv.second);
		} else if (kv.first == "health") {
			health = std::stoi(kv.second);
		} else if (kv.first == "sensitivity") {
			sensitivity = std::stoi(kv.second);
		} else if (kv.first == "strength") {
			strength = std::stoi(kv.second);
		} else if (kv.first == "type") {
			type = std::stoi(kv.second);
		} else if (kv.first == "name") {
			name = kv.second;
		}
	}
}
