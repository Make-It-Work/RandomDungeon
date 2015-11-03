#pragma once
#include <string>
#include <vector>
class Room;
class Layer;
class Player;
class Corridor;

class Compass
{
	private:
		bool containsRoom(std::vector<Room*> list, Room * r);
		void resetEfforts(Layer* l, Player* p);
public:
	Compass();
	~Compass();
	std::string use(Layer* l, Player* p);
	
};

