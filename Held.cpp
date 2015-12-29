#include "Held.h"
#include "GameObject.h"
#include "Dialogue.h"
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

void Held::showStatus()
{
	std::cout << "==== Status van " << naam << " ====\n";
	std::cout << "Level: " << level << ", met " << ervaringspunten << " ervaringspunten\n";
	std::cout << "Aanval: " << aanval << "\n";
	std::cout << "Verdediging: " << verdediging << "\n";
	std::cout << "Opmerkzaamheid: " << opmerkzaamheid << "\n";
	std::cout << "Levenspunten: " << levenspunten << "\n";

	if (wapenInGebruik != nullptr) {
		std::cout << "Wapen: " << wapenInGebruik->naam() << " (" << wapenInGebruik->getStrength() << ")\n";
	}
	if (kledingInGebruik != nullptr) {
		std::cout << "Kleding: " << kledingInGebruik->naam() << " (" << kledingInGebruik->getStrength() << ")\n";
	}

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

int Held::getAanval()
{
	if (wapenInGebruik != nullptr) {
		return aanval + wapenInGebruik->getStrength();
	}
	return aanval;
}

int Held::getVerdediging()
{
	if (kledingInGebruik != nullptr) {
		return verdediging + kledingInGebruik->getStrength();
	}
	return verdediging;
}

bool Held::hit(int enemyAanval)
{
	levenspunten -= enemyAanval;
	int r = rand() % 100;
	if (r < getVerdediging()) {
		std::cout << "Je blokkeert de aanval!\n";
	}
	else {		
		std::cout << "Je tegenstander doet " << enemyAanval << " schade. Je hebt nog " << levenspunten << " levenspunten over. \n";
	}
	return isAlive();
}


void Held::vlucht()
{
	std::map<std::string, Ruimte*> adjacentRooms = Held::getInstance().getRuimte()->getAdjacentRooms();
	std::vector<std::string> richtingen = std::vector<std::string>();

	for (auto e : adjacentRooms) {
		richtingen.push_back(e.first);
	}

	Dialogue dialoog("Welke richting?", { richtingen });

	int gekozenOptie = dialoog.activate();

	Ruimte* doel = adjacentRooms[richtingen[gekozenOptie - 1]];
	Held::getInstance().moveTo(doel);
}

void Held::showInventory()
{
	std::vector<GameObject*> go = Held::getInstance().getInventory();
	std::vector<std::string> opties;
	if (go.size() == 0) {
		std::cout << " \nJe Inventory is leeg. Doorzoek kamers om spullen te vinden.\n";
	}
	else {
		for (GameObject* gobject : go) {
			std::string optieString = gobject->naam() + " (" + std::to_string(gobject->getStrength()) + ")";
			if (Held::getInstance().getWapenInGebruik() == gobject || Held::getInstance().getKledingInGebruik() == gobject) {
				optieString += " (in gebruik) ";
			}
			opties.push_back(optieString);
		}
		opties.push_back("Annuleren");
		Dialogue inventoryDialoog("De volgende spullen zijn in je inventory te vinden. Kies welk item je wilt gebruiken: ", { opties });
		int inventoryKeuze = inventoryDialoog.activate();
		if (inventoryKeuze != 0 && inventoryKeuze != opties.size()) { //annuleren
			go[inventoryKeuze - 1]->use();
		}
	}
}