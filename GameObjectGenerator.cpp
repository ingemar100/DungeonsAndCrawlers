#include "GameObjectGenerator.h"
#include "Gameobject.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>



GameObjectGenerator::GameObjectGenerator()
{
	const std::string textfile("Spullen.txt");
	std::ifstream input_file(textfile); // Dze constructie opent de file voor het lezen;
	std::string line;
	int phase = 0;
	while (getline(input_file, line)) {
		if (line == "__________"){
			phase++;
		}
		else if (phase == 0) {
			//create the map met wapens en hun strength
			std::string buffer;
			std::stringstream ss(line);

			std::vector<std::string>tokens;

			while (std::getline(ss, buffer, ',')) {
				tokens.push_back(buffer);
			}
			if (tokens.size() > 1) {
				wapens[tokens[0]] = std::stoi(tokens[1]);
			}
		}
		else if (phase == 1) {
			std::string buffer;
			std::stringstream ss(line);

			std::vector<std::string>tokens;

			while (std::getline(ss, buffer, ',')) {
				tokens.push_back(buffer);
			}
			if (tokens.size() > 1) {
				eten[tokens[0]] = std::stoi(tokens[1]);
			}
		}
		else if (phase == 2){
			std::string buffer;
			std::stringstream ss(line);

			std::vector<std::string>tokens;

			while (std::getline(ss, buffer, ',')) {
				tokens.push_back(buffer);
			}
			if (tokens.size() > 1) {
				kleding[tokens[0]] = std::stoi(tokens[1]);
			}
		}
	}
}


GameObjectGenerator::~GameObjectGenerator()
{
	wapens.clear();
	eten.clear();
	kleding.clear();
}

GameObject* GameObjectGenerator::createGameObject() 
{
	GameObject* go = new GameObject();
	int randIndex = rand() % 4 + 1;
	int counter = 0;
	if (randIndex == 1) {
		int randIndex = rand() % wapens.size();
		for each(auto kv in wapens) {
			if (counter == randIndex) {
				go->setNaam(kv.first);
				go->setStrength(kv.second);
				go->setType(GameObject::WAPEN);
			}
			counter++;
		}
	}
	else if (randIndex == 2) {
		int randIndex = rand() % eten.size();
		for each(auto kv in eten) {
			if (counter == randIndex) {
				go->setNaam(kv.first);
				go->setStrength(kv.second);
				go->setType(GameObject::ETEN);
			}
			counter++;
		}
	}
	else if (randIndex == 3) {
		int randIndex = rand() % kleding.size();
		for each(auto kv in kleding) {
			if (counter == randIndex) {
				go->setNaam(kv.first);
				go->setStrength(kv.second);
				go->setType(GameObject::KLEDING);
			}
			counter++;
		}
	}
	else {
		go = nullptr;
	}
	// else if == 4 dan wordt er geen GameObject toegevoegd aan de Kamer en is de Kamer leeg. 

	return go;
}