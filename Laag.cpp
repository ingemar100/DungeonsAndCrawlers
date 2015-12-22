#include "Laag.h"
#include <iostream>
#include "RandomGenerator.h"

Laag::Laag()
{
}


Laag::~Laag()
{
	for (std::vector<Ruimte*>* vec : ruimtes) {
		for (Ruimte* r : vec[0]) {
			delete r;
		}
		delete vec;
	}
	ruimtes.clear();
}

void Laag::init() {
}

std::vector<std::vector<Ruimte*>*>* Laag::getRuimtes()
{
	return &ruimtes;
}

void Laag::setRuimtes(std::vector<std::vector<Ruimte*>*> _ruimtes)
{
	ruimtes = _ruimtes;
}

std::string Laag::getMap() {
	std::string map = "";
	for (int i = ruimtes.size() - 1; i >= 0; i--) {
		//iedere kamer neemt 2 regels in beslag, voor zuid- en noord uitgangen
		std::string boven = "";
		std::string onder = "";
		for (int j = 0; j < ruimtes[i][0].size(); j++) {
			Ruimte* r = ruimtes[i][0][j];

			std::string eastIcon;
			//als oost een kamer is
			if (!(r->getAdjacentRooms().find("oost") == r->getAdjacentRooms().end())) {
				eastIcon = "--";
			}
			else {
				eastIcon = "  ";
			}

			//als zuid een kamer is
			if (!(r->getAdjacentRooms().find("zuid") == r->getAdjacentRooms().end())) {
				onder += "|  ";
			}
			else {
				onder += "   ";
			}

			boven += r->getMapTile() + eastIcon;
		}
		map += boven + "\n";
		map += onder + "\n";
	}
	map += "\n";
	return map;
}