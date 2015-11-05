#pragma once
#include <vector>
#include <map>

class Trap;
class TrapGenerator
{
private:
	std::vector<std::string> _keys = { "name", "description", "action", "damage" };
	std::map<std::string, std::string> properties;
	std::vector<std::map<std::string, std::string>> traps;
public:
	TrapGenerator();
	~TrapGenerator();
	Trap * createTrap();
};

