#pragma once
#include <string>
#include <map>

class GameObject
{
private:
	std::string _name = "";
	int _strength = 0;
	std::string _material = "";
	std::string _handle = "";
public:
	GameObject();
	~GameObject();
	std::string getName() {	return _name; };
	int getStrength() { return _strength; };
	std::string getMaterial() { return _material; };
	std::string getHandle() { return _handle; };

	void setName(std::string name) { _name = name; };
	void setMaterial(std::string material) { _material = material; };
	void setHandle(std::string handle) { _handle = handle; };
	void setStrength(int strength) { _strength = strength; };
};

