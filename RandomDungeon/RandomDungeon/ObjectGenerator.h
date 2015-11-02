#pragma once
#include "GameObject.h"
#include <map>
#include <vector>
class ObjectGenerator
{
private:
	std::map<std::string, int> objectTypes;
	std::map<std::string, int> materials;
	std::vector<std::string> _handles;
public:
	ObjectGenerator();
	~ObjectGenerator();

	GameObject* createObject();
};

