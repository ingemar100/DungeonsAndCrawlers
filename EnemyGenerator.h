#pragma once
#include <map>
#include <vector>
#include "Enemy.h"

class Enemy;
class EnemyGenerator
{
private:
	std::map<int, std::map<std::string, std::vector<int>>> enemies;
	std::map<int, std::map<int, std::string>> enemyIndexes;
public:
	EnemyGenerator();
	~EnemyGenerator();
	Enemy* createEnemy(int minLevel, int maxLevel);
};

