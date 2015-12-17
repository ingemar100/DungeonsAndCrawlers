#include "Ruimte.h"
#include "RandomGenerator.h"
#include <iostream>
#include <exception>

Ruimte::Ruimte()
{
}


Ruimte::~Ruimte()
{
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
	beschrijving.append("In  de hoek staat een " + opbergruimte);
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
	//check if contains eindvijand
	else {
		roomIcon = "N";
	}
	return roomIcon;
}