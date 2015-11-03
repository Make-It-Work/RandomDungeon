#pragma once
class Room;
class Talisman
{
public:
	Talisman();
	~Talisman();
	int use(Room * currentRoom, Room * endRoom);
};

