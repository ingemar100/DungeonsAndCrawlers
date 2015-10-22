#include "RandomGenerator.h"
#include <random>
#include <iostream>

bool RandomGenerator::instanceFlag = false;
RandomGenerator* RandomGenerator::instance = nullptr;

RandomGenerator* RandomGenerator::getInstance() {
	if (!instanceFlag) {
		instance = new RandomGenerator();
		instanceFlag = true;
	}
	return instance;
}

int RandomGenerator::getRandom(int min, int max)
{

	std::random_device dev;
	std::default_random_engine dre{ dev() };
	std::uniform_int_distribution<int> dist{ min, max };

	return dist(dre);
}
