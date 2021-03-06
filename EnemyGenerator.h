#pragma once
#include <map>
#include <vector>
#include "Enemy.h"
#include "Ruimte.h"

class Enemy;
class EnemyGenerator
{
private:
	std::map<int, std::map<std::string, std::vector<int>>> enemies;
	std::map<int, std::map<int, std::string>> enemyIndexes;

	std::map<std::string, std::vector<int>> eindbazen;
public:
	EnemyGenerator();
	~EnemyGenerator();
	void addEnemies(int minLevel, int maxLevel, Ruimte* room);
	void addEindbaas(Ruimte* room);
};

