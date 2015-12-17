#include "Kerker.h"
#include "RandomGenerator.h"
#include <iostream>
#include <random>
#include "Held.h"


Kerker::Kerker()
{
}


Kerker::~Kerker()
{
	for (Laag* l : lagen) {
		delete l;
		l = nullptr;
	}
}

void Kerker::init() {
	int laagGrootte = 5;
	int ruimte;

	RoomGenerator* roomGenerator = new RoomGenerator();

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

		std::vector<std::vector<Ruimte*>*> ruimtes = std::vector<std::vector<Ruimte*>*>();
		for (int j = 0; j < laagGrootte; j++) {
			std::vector<Ruimte*>* binnenVector = new std::vector<Ruimte*>();

			for (int k = 0; k < laagGrootte; k++) {
				Ruimte* r = roomGenerator->createRoom();

				//std::cout << "J: " + j;
				//ruimtes[j][k].push_back(r);
				binnenVector->push_back(r);
			}
			ruimtes.push_back(binnenVector);
		}
		//setten in laag
		lagen[i]->setRuimtes(ruimtes);
	}

	Laag* laag = lagen[0];
	Ruimte* r = laag->getStartRoom();
	Held::getInstance().setRuimte(r);

	huidigeLaag = laag1;

	delete roomGenerator;
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