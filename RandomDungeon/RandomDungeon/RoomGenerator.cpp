#include "stdafx.h"
#include "RoomGenerator.h"
#include <iostream>
#include <string>
#include "Room.h"
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

//enum RoomAttribute {TABLE, STOOL, BED, BOX, CLOSET, NONE};
//enum Dirt {DUST, BLOOD, NONE};
//enum Lightsource {CANDLE, TORCH, FIREPLACE,	WALLCRACKS, NONE};
//enum Floor {SAND, STONE, MUD};
//enum Decoration {SKELETON, PAINTING, CHAINS, NONE};

RoomGenerator::RoomGenerator()
{
	const string textfile{ "rooms.txt" };
	ifstream input_file{ textfile }; // stack-based file object; deze constructie opent de file voor lezen
	string line;
	int counter = 0;

	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		string property = keys[counter];
		std::istringstream buf(line);
		std::istream_iterator <std::string> beg(buf), end;
		std::vector<std::string> line(beg, end);
		properties[property] = line;
		counter++;
	}
}

RoomGenerator::~RoomGenerator()
{
}

Room* RoomGenerator::createRoom() {
	Room* room = new Room();
	int RandIndex = rand() % properties["size"].size();
	room->setSize(properties["size"][RandIndex]);
	RandIndex = rand() % properties["attribute"].size();
	room->setAttribute(properties["attribute"][RandIndex]);
	RandIndex = rand() % properties["dirt"].size();
	room->setDirt(properties["dirt"][RandIndex]);
	RandIndex = rand() % properties["lightsource"].size();
	room->setLightsource(properties["lightsource"][RandIndex]);
	RandIndex = rand() % properties["floor"].size();
	room->setFloor(properties["floor"][RandIndex]);
	RandIndex = rand() % properties["decoration"].size();
	room->setDecoration(properties["decoration"][RandIndex]);
	return room;
}
