#include "Laag.h"
#include <iostream>
#include "RandomGenerator.h"

Laag::Laag()
{
}


Laag::~Laag()
{
}

void Laag::init() {
}

std::vector<std::vector<Ruimte*>*>* Laag::getRuimtes()
{
	return &std::vector<std::vector<Ruimte*>*>();
}

void Laag::setRuimtes(std::vector<std::vector<Ruimte*>*> _ruimtes)
{
	ruimtes = _ruimtes;
}

std::string Laag::getMap() {
	std::string map = "";
	for (int i = 0; i < ruimtes.size(); i++) {
		for (int j = 0; j < ruimtes[i][0].size(); j++) {
			Ruimte* r = ruimtes[i][0][j];
			map += r->getMapTile() + "";
		}
		map += "\n";
		map += "\n";
	}
	map += "\n";
	return map;
}