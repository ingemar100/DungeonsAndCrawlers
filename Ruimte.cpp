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

std::string Ruimte::getStringFromEnum(Formaat waarde)
{
	switch (waarde)
	{
	case KLEIN: return "kleine";
	case MIDDEL: return "middelgrote";
	case GROOT: return "grote";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Ordelijkheid waarde)
{
	switch (waarde)
	{
	case SMERIG: return "smerig";
	case SCHOON: return "schoon";
	case STOFFIG: return "stoffig";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Meubels waarde)
{
	switch (waarde)
	{
	case TAFEL: return "tafel met vier stoelen";
	case BED: return "bed";
	case GEEN_MEUBELS: return "geen meubels";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Verlichting waarde)
{
	switch (waarde)
	{
	case KAARS: return "kaars";
	case FAKKEL: return "fakkel";
	case HAARDVUUR: return "haardvuur";
	case KROONLUCHTER: return "kroonluchter";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Opbergruimte waarde)
{
	switch (waarde)
	{
	case KIST: return "kist";
	case BOEKENKAST: return "boekenkast";
	case GEEN_OPBERGRUIMTE: return "geen opbergruimte";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Versiering waarde)
{
	switch (waarde)
	{
	case SCHILDERIJ: return "schilderij";
	case TAPIJT: return "tapijt";
	case TROFEE: return "trofee";
	case GEEN_VERSIERING: return "geen versiering";
	default: throw std::exception("Bad MyEnum");
	}
}
std::string Ruimte::getStringFromEnum(Temperatuur waarde)
{
	switch (waarde)
	{
	case WARM: return "warme";
	case IJSKOUD: return "ijskoude";
	case KOEL: return "koele";
	default: throw std::exception("Bad MyEnum");
	}
}

std::string Ruimte::getBeschrijving(){
	//string = Je staat in een <formaat>e <temperatuur>e kamer
	std::string* beschrijving = new std::string("Je staat in een ");
	beschrijving->append(getStringFromEnum(formaat) + " ");
	beschrijving->append(getStringFromEnum(temperatuur) + " kamer");


	//if meubels
	//string += met in het midden een <meubels>
	if (meubels != GEEN_MEUBELS) {
		beschrijving->append(" met in het midden een " + getStringFromEnum(meubels));
	}
	beschrijving->append(". ");
	//de kamer wordt verlicht door een <verlichting>
	beschrijving->append("De kamer wordt verlicht door een " + getStringFromEnum(verlichting));
	beschrijving->append(". ");

	//if opbergruimte
	//string += in de hoek staat een <opbergruimte>
	if (opbergruimte != GEEN_OPBERGRUIMTE) {
		beschrijving->append("In  de hoek staat een " + getStringFromEnum(opbergruimte));
		beschrijving->append(". ");
	}

	//if versiering
	//de kamer wordt versierd door een <versiering>
	if (versiering != GEEN_VERSIERING) {
		beschrijving->append("De kamer wordt versierd door een " + getStringFromEnum(versiering));
		beschrijving->append(". ");
	}

	beschrijving->append("De kamer is " + getStringFromEnum(ordelijkheid) + ". ");
	return *beschrijving;
}

void Ruimte::fillRandomly() {
	int eger = RandomGenerator::getInstance()->getRandom(0, GROOT);
	formaat = static_cast<Formaat>(eger);

	ordelijkheid = static_cast<Ordelijkheid>(RandomGenerator::getInstance()->getRandom(0, STOFFIG));

	meubels = static_cast<Meubels>(RandomGenerator::getInstance()->getRandom(0, GEEN_MEUBELS));

	verlichting = static_cast<Verlichting>(RandomGenerator::getInstance()->getRandom(0, KROONLUCHTER));

	opbergruimte = static_cast<Opbergruimte>(RandomGenerator::getInstance()->getRandom(0, GEEN_OPBERGRUIMTE));

	versiering = static_cast<Versiering>(RandomGenerator::getInstance()->getRandom(0, GEEN_VERSIERING));

	temperatuur = static_cast<Temperatuur>(RandomGenerator::getInstance()->getRandom(0, KOEL));

}

std::string Ruimte::getMapTile() {
	return "N--";
}