#pragma once
#include "GameObject.h"
#include <map>
#include <vector>

class GameObjectGenerator
{
	std::map<std::string, int> wapens;
	std::map<std::string, int> eten;
	std::map<std::string, int> kleding;

public:
	GameObjectGenerator();
	~GameObjectGenerator();

	GameObject* createGameObject();
};

