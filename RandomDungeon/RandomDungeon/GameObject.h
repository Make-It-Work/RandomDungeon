#pragma once
#include <string>

class GameObject
{
private:
	std::string _name = "";
public:
	GameObject();
	~GameObject();
	std::string getName();
};

