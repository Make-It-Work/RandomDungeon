#pragma once
#include <string>

class Attribute
{
private:
	std::string _name = "";
public:
	Attribute();
	~Attribute();
	void setName(std::string name);
	std::string getName();
};

