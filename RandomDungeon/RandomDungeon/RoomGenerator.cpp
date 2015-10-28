#include "stdafx.h"
#include "RoomGenerator.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Room.h"
#include <time.h>
#include <chrono>
#include <random>

const char* sizes[] =
{
	"small", "medium", "large"
};
const char* roomAttributes[] =
{
	"table", "stool", "bed", "box", "closet", "none"
};
//enum RoomAttribute {TABLE, STOOL, BED, BOX, CLOSET, NONE};
//enum Dirt {DUST, BLOOD, NONE};
//enum Lightsource {CANDLE, TORCH, FIREPLACE,	WALLCRACKS, NONE};
//enum Floor {SAND, STONE, MUD};
//enum Decoration {SKELETON, PAINTING, CHAINS, NONE};

RoomGenerator::RoomGenerator()
{
}


RoomGenerator::~RoomGenerator()
{
}

Room* RoomGenerator::createRoom() {
	Room* room = new Room();//initialize the random seed
	int RandIndex = rand() % 3; //generates a random number between 0 and 2
	room->setSize(sizes[RandIndex]);
	RandIndex = rand() % 6; //generates a random number between 0 and 5
	room->setAttribute(roomAttributes[RandIndex]);
	return room;
}
