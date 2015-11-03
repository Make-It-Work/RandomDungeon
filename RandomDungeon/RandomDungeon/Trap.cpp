#include "stdafx.h"
#include "Trap.h"
#include <map>

Trap::Trap()
{
}


Trap::~Trap()
{
}

void Trap::setProperties(std::map<std::string, std::string> props) {
	for (auto kv : props) {
		if (kv.first == "name") {
			_name = kv.second;
		}
		else if (kv.first == "description") {
			_description = kv.second;
		}
		else if (kv.first == "action") {
			_action = kv.second;
		}
		else if (kv.first == "damage") {
			_damage = std::stoi(kv.second);
		}
	}
}
