#include "stdafx.h"
#include "EnemyGenerator.h"
#include <iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

EnemyGenerator::EnemyGenerator()
{
	const string textfile{ "enemies.txt" };
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
		enemies.push_back(properties);

	}
}


EnemyGenerator::~EnemyGenerator()
{
}

Enemy* EnemyGenerator::createEnemy() {
	Enemy* enemy = new Enemy();
	int RandIndex = rand() % enemies.size();
	map<std::string, std::string> enemyProperties = enemies[RandIndex];
	enemy->setProperties(enemyProperties);
	return enemy;
}