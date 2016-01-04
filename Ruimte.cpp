#include "Ruimte.h"
#include "RandomGenerator.h"
#include "GameObject.h"
#include <iostream>
#include <exception>
#include "Held.h";

Ruimte::Ruimte()
{
}

Ruimte::~Ruimte()
{
	if (_gameObject != nullptr) {
		delete _gameObject;
		_gameObject = nullptr;
	}
	if (_val != nullptr) {
		delete _val;
		_val = nullptr;
	}
	for (auto e : _enemies) {
		delete e;
		e = nullptr;
	}
	_enemies.clear();
}

std::string Ruimte::getBeschrijving(){
	//string = Je staat in een <formaat>e <temperatuur>e kamer
	std::string& beschrijving = std::string("Je staat in een ");
	beschrijving.append(formaat + " ");
	beschrijving.append(temperatuur + " kamer");


	//if meubels
	//string += met in het midden een <meubels>
	beschrijving.append(" met in het midden een " + meubels);

	beschrijving.append(". ");
	//de kamer wordt verlicht door een <verlichting>
	beschrijving.append("De kamer wordt verlicht door een " + verlichting);
	beschrijving.append(". ");

	//if opbergruimte
	//string += in de hoek staat een <opbergruimte>
	beschrijving.append("In de hoek staat een " + opbergruimte);
	beschrijving.append(". ");

	//if versiering
	//de kamer wordt versierd door een <versiering>
	beschrijving.append("De kamer wordt versierd door een " + versiering);
	beschrijving.append(". ");

	beschrijving.append("De kamer is " + ordelijkheid + ". \n\n");

	beschrijving.append("Uitgangen:");
	for (auto ent : adjacentRooms) {
		beschrijving.append(ent.first + ", ");
	}
	beschrijving.append("\n");

	if (trapOmhoog) {
		beschrijving.append("De kamer heeft een trap omhoog.\n");
	}
	if (trapOmlaag) {
		beschrijving.append("De kamer heeft een trap omlaag.\n");
	}

	if (hasEnemy()) {
		beschrijving.append("\nAanwezig: "); 
		for (auto enemy : _enemies) {
			beschrijving.append(enemy->getName() + ",");
		}
		beschrijving.append("\n");
	}
	return beschrijving;
}

std::string Ruimte::getMapTile() {
	std::string roomIcon;
	if (!visited) {
		roomIcon = ".";
	}
	else if (trapOmhoog) {
		roomIcon = "H";
	}
	else if (trapOmlaag) {
		roomIcon = "L";
	}
	else if (this == Held::getInstance().getRuimte()) {
		roomIcon = "X";
	}
	else if (eindbaas) {
		roomIcon = "E";
	}
	else {
		roomIcon = "N";
	}
	return roomIcon;
}

void Ruimte::addGameObject(GameObject * gameObject)
{
	_gameObject = gameObject;
}

void Ruimte::removeObject()
{
	_gameObject = nullptr;
}

GameObject * Ruimte::search()
{
	if (_gameObject != nullptr) {
		if (_gameObject->getType() == GameObject::WAPEN) {
			std::cout << "Er ligt een " << _gameObject->naam() << " op de grond.";
		}
		else if (_gameObject->getType() == GameObject::ETEN) {
			std::cout << "Je hebt " << _gameObject->naam() << " gevonden.";
		}
		else if (_gameObject->getType() == GameObject::KLEDING) {
			std::cout << "Er hangt een " << _gameObject->naam() << " in de kamer.";
		}
		std::cout << " Dit Item wordt toegevoegd aan je Inventory. ";
	}
	else{
		std::cout << "Je hebt niks kunnen vinden. ";
	}
	std::cout << "\n\n";

	if (_val != nullptr) {
		int r = rand() % 100;
		if (r < Held::getInstance().getOpmerkzaamheid()) {
			std::cout << "Je hebt een Val ontdekt en ontmanteld.\n";
			delete _val;
			_val = nullptr;
		}
		else {
			doVal();
		}
	}

	return _gameObject;
}

void Ruimte::addEnemy(Enemy * enemy)
{
	_enemies.push_back(enemy);
}

void Ruimte::destroyEnemy(Enemy* toRemove)
{
	std::vector<Enemy*>::iterator i = _enemies.begin();
	while (i != _enemies.end()) {
		if (*i == toRemove) {
			delete toRemove;
			i = _enemies.erase(i);
		}
		else {
			i++;
		}
	}
}

void Ruimte::addVal(Val* val)
{
	_val = val;
}

bool Ruimte::hasVal()
{
	if (_val != nullptr) {
		return true;
	}
	return false;
}

void Ruimte::doVal()
{
	if (_val != nullptr) {
		std::cout << "Oh nee.... " << _val->naam() << " is geactiveerd. Je verlies " << _val->getStrength() << " levenspunten.\n";
		int rv = _val->getStrength();
		Held::getInstance().setLevenspunten(Held::getInstance().getLevenspunten() - rv);
		delete _val;
		_val = nullptr;

	}
}

