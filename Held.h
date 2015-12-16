#pragma once
#include "Ruimte.h"
#include <string>
#include <vector>
#include "spul.h"

class Held
{
public:
	bool isAlive();
	std::string getNaam();
	void setNaam(std::string _naam);
	static Held& getInstance();
	void setRuimte(Ruimte* _ruimte);
	Ruimte* getRuimte();

private:
	static Held* instance;
	static bool instanceFlag;
	Held();
	~Held() {
		instanceFlag = false;
	};
	std::string naam;
	int level;
	int levenspunten;
	int ervaringspunten;
	int aanval;
	int verdediging;
	int opmerkzaamheid;
	std::vector<Spul> spullen;
	Ruimte* ruimte;

	//Held instance;
};

