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
	void moveTo(Ruimte* _ruimte);
	Ruimte* getRuimte();
	static void deleteInstance();

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
	Ruimte* ruimte;

	//Held instance;
};

