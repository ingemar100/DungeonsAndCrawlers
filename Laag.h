#pragma once
#include <vector>
#include "Ruimte.h"

class Laag
{
public:
	Laag();
	~Laag();
	void init();
	std::vector<std::vector<Ruimte*>*>* getRuimtes();
	void setRuimtes(std::vector<std::vector<Ruimte*>*> ruimtes);
	std::string getMap();
	Ruimte* getStartRoom() {
		return startRoom;
	}
	void setStartRoom(Ruimte* start) {
		startRoom = start;
	}
private:
	std::vector<std::vector<Ruimte*>*> ruimtes;
	Ruimte* startRoom = nullptr;
};

