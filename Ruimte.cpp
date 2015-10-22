#include "Ruimte.h"
#include "RandomGenerator.h"
#include <iostream>


Ruimte::Ruimte()
{
}


Ruimte::~Ruimte()
{
}

std::string Ruimte::getBeschrijving() {
	return "Je staat in een kamer met in het midden een tafel. Om de tafel staan vier stoelen. In een hoek staat een kist. ";
}

void Ruimte::fillRandomly() {
	int eger = RandomGenerator::getInstance()->getRandom(5, 15);

	//std::cout << eger << "\n";
}

std::string Ruimte::getMapTile() {
	return ".";
}