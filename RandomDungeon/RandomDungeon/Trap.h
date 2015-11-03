#pragma once
#include <string>
#include <map>
class Trap
{
private:
	std::string _name = "";
	std::string _description = "";
	std::string _action = "";
	int _damage =  0;
public:
	Trap();
	~Trap();
	void setProperties(std::map<std::string, std::string>);
	void setName(std::string name) {
		_name = name;
	};
	std::string getName() {
		return _name;
	};
	void setDescription(std::string des) {
		_description = des;
	};
	std::string getDescription() {
		return _description;
	};
	void setAction(std::string action) {
		_action = action;
	}
	std::string getAction() {
		return _action;
	}
	void setDamage(int damage) {
		_damage = damage;
	}
	int getDamage() {
		return _damage;
	};
};

