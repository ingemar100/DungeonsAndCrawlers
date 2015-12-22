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

				binnenVector->push_back(r);
			}
			ruimtes.push_back(binnenVector);
		}
		//setten in laag
		lagen[i]->setRuimtes(ruimtes);

		//adjacencies setten
		for (int j = 0; j < laagGrootte; j++) {
			for (int k = 0; k < laagGrootte; k++) {
				Ruimte* r = ruimtes[j][0][k];
				std::map<std::string, Ruimte*> adjacencies;
				//als dit niet aan de onderkant van map is
				if (j != 0) {
					Ruimte* adj = ruimtes[j - 1][0][k];
					std::string w = "zuid";
					adjacencies.emplace(w, adj);
				}
				if (j != laagGrootte - 1) {
					Ruimte* adj = ruimtes[j + 1][0][k];
					std::string w = "noord";
					adjacencies.emplace(w, adj);
				}
				if (k != 0) {
					Ruimte* adj = ruimtes[j][0][k - 1];
					std::string w = "west";
					adjacencies.emplace(w, adj);
				}
				if (k != laagGrootte - 1) {
					Ruimte* adj = ruimtes[j][0][k + 1];
					std::string w = "oost";
					adjacencies.emplace(w, adj);
				}
				r->adjacentRooms = adjacencies;
			}
		}
	}

	Laag* laag = lagen[0];
	Ruimte* r = laag->getStartRoom();
	Held::getInstance().moveTo(r);

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