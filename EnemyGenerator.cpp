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


	const std::string file("Eindbazen.txt");
	std::ifstream boss_file(file); // Deze constructie opent de file voor het lezen;
	std::string line1;
	while (getline(boss_file, line1)) {
		std::string buffer;
		std::stringstream ss(line1);

		std::vector<std::string>tokens;

		while (std::getline(ss, buffer, ',')) {
			tokens.push_back(buffer);
		}
		if (tokens.size() > 1) {
			std::vector<int> properties;
			for (int i = 1; i < tokens.size(); i++) {
				properties.push_back(std::stoi(tokens[i]));
			}
			eindbazen[tokens[0]] = properties;
		}
	}
}


EnemyGenerator::~EnemyGenerator()
{
	enemies.clear();
}

void EnemyGenerator::addEnemies(int minLevel, int maxLevel, Ruimte* room) {
	if (minLevel < 1) {
		minLevel = 1;
	}
	if (maxLevel > 10) {
		maxLevel = 10;
	}

	int numEnemies = rand() % 3 + 1;
	for (int i = 0; i < numEnemies; i++) {
		int level = rand() % (maxLevel - minLevel + 1) + minLevel;

		if (enemies[level].size() == 0) {
			continue;
		}

		Enemy* enemy = new Enemy();
		int RandIndex = rand() % enemies[level].size();

		std::string enemyNaam = enemyIndexes[level][RandIndex];
		auto props = enemies[level][enemyNaam];

		enemy->setName(enemyNaam);
		enemy->setLevenspunten(props[0]);
		enemy->setAanval(props[1]);
		enemy->setVerdediging(props[2]);

		room->addEnemy(enemy);
	}
}

void EnemyGenerator::addEindbaas(Ruimte * room)
{
	int randIndex = rand() % eindbazen.size();
	Enemy* baas = new Enemy();

	int counter = 0;
	for each(auto kv in eindbazen) {
		if (counter == randIndex) {
			baas->setName(kv.first);
			auto props = kv.second;
			baas->setLevenspunten(props[0]);
			baas->setAanval(props[1]);
			baas->setVerdediging(props[2]);
		}
		counter++;
	}

	room->addEnemy(baas);
	room->eindbaas = true;
}

