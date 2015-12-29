#include "EnemyGenerator.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

EnemyGenerator::EnemyGenerator()
{
	const std::string textfile("Enemies.txt");
	std::ifstream input_file(textfile); // Deze constructie opent de file voor het lezen;
	int index = 0;
	int level = 1;
	std::string line;
	while (getline(input_file, line)) {
		if (line == "") {
			level++;
			index = 0;
		}
		else {
			std::string buffer;
			std::stringstream ss(line);

			std::vector<std::string>tokens;

			while (std::getline(ss, buffer, ',')) {
				tokens.push_back(buffer);
			}
			if (tokens.size() > 1) {
				std::vector<int> properties;
				for (int i = 1; i < tokens.size(); i++) {
					properties.push_back(std::stoi(tokens[i]));
				}
				enemies[level][tokens[0]] = properties;

				enemyIndexes[level][index++] = tokens[0];
			}
		}
	}
}


EnemyGenerator::~EnemyGenerator()
{
	enemies.clear();
}

Enemy* EnemyGenerator::createEnemy(int minLevel, int maxLevel) {
	int level = rand() % maxLevel + minLevel;

	if (enemies[level].size() == 0) {
		return nullptr;
	}

	Enemy* enemy = new Enemy();
	int RandIndex = rand() % enemies[level].size();
	
	std::string enemyNaam = enemyIndexes[level][RandIndex];
	auto props = enemies[level][enemyNaam];

	enemy->setName(enemyNaam);
	enemy->setLevenspunten(props[0]);
	enemy->setAanval(props[1]);
	enemy->setVerdediging(props[2]);

	return enemy;
}									