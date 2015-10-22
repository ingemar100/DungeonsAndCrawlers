#include "Kerker.h"
#include "RandomGenerator.h"
#include <iostream>
#include <random>


Kerker::Kerker()
{
}


Kerker::~Kerker()
{
}

void Kerker::init() {
	int laagGrootte = 10;
	int ruimte;

	//generaar lagen
	Laag* laag1 = new Laag();
	Laag* laag2 = new Laag();
	Laag* laag3 = new Laag();
	lagen.push_back(laag1);
	lagen.push_back(laag2);
	lagen.push_back(laag3);

	//genereer random ruimtes voor iedere laag1
	for (int i = 0; i < lagen.size(); i++) {
		lagen[i]->init();

		//std::vector<Ruimte*> test(10);
		//std::vector<std::vector<Ruimte*>> test2(10, test);
		std::vector<std::vector<Ruimte*>> ruimtes = std::vector<std::vector<Ruimte*>> (10, std::vector<Ruimte*>());
		for (int j = 0; j < laagGrootte; j++) {
			for (int k = 0; k < laagGrootte; k++) {
				Ruimte* r = new Ruimte();
				r->fillRandomly();
				ruimtes[j].push_back(r);
			}
			std::cout << ruimtes[j].size();
		}
		//setten in laag
		lagen[i]->setRuimtes(ruimtes);
	}
	huidigeLaag = laag1;
}

void Kerker::showMap() {
	std::cout << "Kerkerkaart:\n";
	std::cout << huidigeLaag->getMap();
	std::cout << "Legenda: \n";
	std::cout << "|- : Gangen \n";
	std::cout << "S  : Startlocatie \n";
	std::cout << "E  : Eindvijand \n";
	std::cout << "N  : Normale ruimte \n";
	std::cout << "L  : Trap omlaag\n";
	std::cout << "H  : Trap omhoog \n";
	std::cout << ".  : Onbekend\n";
}