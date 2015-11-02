#pragma once
#include <map>
#include <vector>
class Enemy;
class EnemyGenerator
{
private:
	std::vector<std::string> _keys = { "name", "health", "strength", "sensitivity", "level", "type" };
	std::map<std::string, std::string> properties;
	std::vector<std::map<std::string, std::string>> enemies;
public:
	EnemyGenerator();
	~EnemyGenerator();
	Enemy* createEnemy();
};

