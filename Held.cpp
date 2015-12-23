#include "Held.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>


Held::Held()
{
	naam = "Adventurer";
	level = 1;
	levenspunten = 100;
	ervaringspunten = 1;
	aanval = 1;
	verdediging = 1;
	opmerkzaamheid = 1;
}

Held::~Held() {
	instanceFlag = false;
	for (GameObject* go : inventory) {
		delete go;
	}
	inventory.clear();
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

void Held::addToInventory(GameObject* _gameObject)
{
	inventory.push_back(_gameObject);
}

std::vector<GameObject*> Held::getInventory()
{
	return inventory;
}

void Held::showStatus()
{
	std::cout << "==== Status van " << naam << " ====\n";
	std::cout << "Level: " << level << ", met " << ervaringspunten << " ervaringspunten\n";
	std::cout << "Aanval: " << aanval << "\n";
	std::cout << "Verdediging: " << verdediging << "\n";
	std::cout << "Opmerkzaamheid: " << opmerkzaamheid << "\n";
	std::cout << "Levenspunten: " << levenspunten << "\n";

}


