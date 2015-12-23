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

void Held::removeFromInventory(GameObject * toRemove)
{
	std::vector<GameObject*>::iterator i = inventory.begin();
	while (i != inventory.end()) {
		if (*i == toRemove) {
			i = inventory.erase(i);
		}
		else {
			i++;
		}
	}
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

void Held::setWapenInGebruik(GameObject * wapen)
{
	wapenInGebruik = wapen;
}

void Held::setKledingInGebruik(GameObject * kleding)
{
	kledingInGebruik = kleding;
}

void Held::consumeer(GameObject * eten)
{
	removeFromInventory(eten);
	levenspunten += eten->getStrength();
	if (levenspunten > 100) {
		levenspunten = 100;
	}
	std::cout << "\nJe hebt " << eten->naam() << " gegeten en krijgt er " << eten->getStrength() << " Levenspunten bij. Je huidge Levenspunten zijn nu " << levenspunten << "\n\n";

	delete eten;
}



