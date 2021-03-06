#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iterator>
#include <iostream>

#include "GameObjectGenerator.h"
#include "ValGenerator.h"

class Ruimte;

class RoomGenerator
{
private:
	std::vector<std::string> keys = { "formaat", "ordelijkheid", "meubels", "verlichting", "opbergruimte", "versiering", "temperatuur" };
	std::map<std::string, std::vector<std::string>> properties;
	GameObjectGenerator* gog = nullptr;
	ValGenerator* vg = nullptr;
public:
	RoomGenerator();
	~RoomGenerator();
	Ruimte* createRoom();
};

