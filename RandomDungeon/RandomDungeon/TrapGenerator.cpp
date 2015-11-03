#include "stdafx.h"
#include "TrapGenerator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Trap.h"
using namespace std;

TrapGenerator::TrapGenerator()
{
	const string textfile{ "traps.txt" };
	ifstream input_file{ textfile }; // stack-based file object; deze constructie opent de file voor lezen
	string line;
	// getline() leest een regel die eindigt in een \n
	// (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
	while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
		int counter = 0;
		std::istringstream buf(line);
		std::istream_iterator <std::string> beg(buf), end;
		std::vector<std::string> line(beg, end);
		for each(std::string s in line) {
			string prop = _keys[counter];
			properties[prop] = s;
			counter++;
		}
		traps.push_back(properties);

	}
}


TrapGenerator::~TrapGenerator()
{
	traps.clear();
	properties.clear();
	_keys.clear();
}

Trap* TrapGenerator::createTrap() {
	Trap* trap = new Trap();
	int RandIndex = rand() % traps.size();
	map<std::string, std::string> enemyProperties = traps[RandIndex];
	trap->setProperties(enemyProperties);
	return trap;
}
