#pragma once

#include <string>
#include <vector>
#include "spul.h"

class Held
{
public:
	Held();
	~Held();
	bool isAlive();
	std::string getNaam();
	void setNaam(std::string _naam);

private:
	std::string naam;
	int level;
	int levenspunten;
	int ervaringspunten;
	int aanval;
	int verdediging;
	int opmerkzaamheid;
	std::vector<Spul> spullen;
	//Held instance;
};

