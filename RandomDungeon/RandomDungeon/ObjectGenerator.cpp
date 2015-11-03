#include "stdafx.h"
#include "ObjectGenerator.h"
#include "GameObject.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

ObjectGenerator::ObjectGenerator()
{
	const string textfile{ "weapons.txt" };
	ifstream input_file{ textfile }; // stack-based file object; deze constructie opent de file voor lezen
	string line;
	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	int phase = 0;
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		if (line == "_____") {
			phase++;
		}
		else if (phase == 0) {
			//create the map with types with it's strength
			string buf; // Have a buffer string
			stringstream ss(line); // Insert the string into a stream

			std::vector<std::string> tokens; // Create vector to hold our words

			while (ss >> buf) {
				tokens.push_back(buf);
			}
			if (tokens.size() > 1) {
				objectTypes[tokens[0]] = std::stoi(tokens[1]);
			}

		}
		else if (phase == 1) {
			//Create the map with material and it's multiplication factor
			string buf; // Have a buffer string
			stringstream ss(line); // Insert the string into a stream

			std::vector<std::string> tokens; // Create vector to hold our words

			while (ss >> buf) {
				tokens.push_back(buf);
			}
			if (tokens.size() > 1) {
				materials[tokens[0]] = std::stoi(tokens[1]);
			}
		}
		else if (phase == 2) {
			//Create vector of handles
			_handles.push_back(line);
		}
	}
}


ObjectGenerator::~ObjectGenerator()
{
	objectTypes.clear();
	materials.clear();
	_handles.clear();
}

GameObject * ObjectGenerator::createObject()
{
	GameObject* go = new GameObject();
	int randIndex = rand() % objectTypes.size();
	int counter = 0;
	int tmpStrength = 0;
	for each (auto kv in objectTypes)
	{
		if (counter == randIndex) {
			go->setName(kv.first);
			tmpStrength = kv.second;
		}
		counter++;
	}
	randIndex = rand() % materials.size();
	counter = 0;
	for each (auto kv in materials)
	{
		if (counter == randIndex) {
			go->setMaterial(kv.first);
			tmpStrength *= kv.second;
		}
		counter++;
	}
	go->setStrength(tmpStrength);
	randIndex = rand() % _handles.size();
	go->setHandle(_handles[randIndex]);
	return go;
}
