#include "Held.h"
#include <string>
#include <vector>
#include <iostream>


Held::Held()
{
	naam = "Adventurer";
	level = 1;
	levenspunten = 10;
	ervaringspunten = 1;
	aanval = 1;
	verdediging = 1;
	opmerkzaamheid = 1;
}

bool Held::instanceFlag = false;
Held* Held::instance = nullptr;

Held& Held::getInstance() {
	if (!instanceFlag) {
		instance = new Held();
		instanceFlag = true;
	}
	return *instance;
}


bool Held::isAlive() {
	return levenspunten > 0;
}

std::string Held::getNaam() {
	return naam;
}

void Held::setNaam(std::string _naam) {
	naam = _naam;
}

void Held::moveTo(Ruimte* _ruimte) {
	_ruimte->visited = true;
	ruimte = _ruimte;
	std::cout << ruimte->getBeschrijving();
}

Ruimte* Held::getRuimte() {
	return ruimte;
}

void Held::deleteInstance()
{
	delete instance;
	instance = nullptr;
}
