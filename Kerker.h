#pragma once
#include <vector>
#include "Laag.h"
#include "RoomGenerator.h"
#include "EnemyGenerator.h"

class Kerker
{
public:
	Kerker();
	~Kerker();
	void init();
	void showMap();
	int getNiveau();
	std::vector<Laag*>& getLagen() { return lagen; }
	void setHuidigeLaag(Laag* nieuw) { huidigeLaag = nieuw; }
private:
	std::vector<Laag*> lagen;
	Laag* huidigeLaag = nullptr;
	int aantalLagen = 3;
	int laagAfmeting = 3;
	void slaOp();
	void laad();
	EnemyGenerator* eg = nullptr;

	friend class Engine;
};

