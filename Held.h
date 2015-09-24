#pragma once

#include <string>
#include <vector>
#include "spul.h"

class Held
{
public:
	Held(std::string _naam);
	~Held();
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

