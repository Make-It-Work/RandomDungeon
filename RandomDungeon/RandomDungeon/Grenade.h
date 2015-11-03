#pragma once
class Room;
class Layer;
class Player;
class Grenade
{
public:
	Grenade();
	~Grenade();
	void use(Layer* l, Player* p);
};

