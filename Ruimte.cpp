#include "Ruimte.h"
#include "RandomGenerator.h"
#include "GameObject.h"
#include <iostream>
#include <exception>

Ruimte::Ruimte()
{
}


Ruimte::~Ruimte()
{
	if (_gameObject != nullptr) {
		delete _gameObject;
		_gameObject = nullptr;
	}
}

std::string Ruimte::getBeschrijving(){
	//string = Je staat in een <formaat>e <temperatuur>e kamer
	std::string* beschrijving = new std::string("Je staat in een ");
	beschrijving->append(formaat + " ");
	beschrijving->append(temperatuur + " kamer");


	//if meubels
	//string += met in het midden een <meubels>
	beschrijving->append(" met in het midden een " + meubels);

	beschrijving->append(". ");
	//de kamer wordt verlicht door een <verlichting>
	beschrijving->append("De kamer wordt verlicht door een " + verlichting);
	beschrijving->append(". ");

	//if opbergruimte
	//string += in de hoek staat een <opbergruimte>
	beschrijving->append("In  de hoek staat een " + opbergruimte);
	beschrijving->append(". ");

	//if versiering
	//de kamer wordt versierd door een <versiering>
	beschrijving->append("De kamer wordt versierd door een " + versiering);
	beschrijving->append(". ");

	beschrijving->append("De kamer is " + ordelijkheid + ". ");
	return *beschrijving;
}

std::string Ruimte::getMapTile() {
	return "N--";
}

void Ruimte::addGameObject(GameObject * gameObject)
{
	_gameObject = gameObject;
}

void Ruimte::removeObject()
{
	delete _gameObject;
	_gameObject = nullptr;
}

GameObject * Ruimte::search()
{
	if (_gameObject != nullptr) {
		if (_gameObject->getType() == GameObject::WAPEN) {
			std::cout << "Er ligt een " << _gameObject->naam() << " op de grond. Dit Item wordt Toegevoegd aan je Inventory. ";
		}
		else if (_gameObject->getType() == GameObject::ETEN) {
			std::cout << "Er ligt " << _gameObject->naam() << " Dit Item wordt Toegevoegd aan je Inventory. ";
		}
		else if (_gameObject->getType() == GameObject::KLEDING) {
			std::cout << "Er ligt een " << _gameObject->naam() << " op de grond. Dit Item wordt Toegevoegd aan je Inventory. ";
		}
	}
	else{
		std::cout << "Je hebt niks kunnen vinden. ";
	}
	std::cout << "\n\n";

	return _gameObject;
}
