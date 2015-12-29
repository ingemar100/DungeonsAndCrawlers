#include "Kerker.h"
#include "RandomGenerator.h"
#include <iostream>
#include <random>
#include "Held.h"


Kerker::Kerker()
{
	eg = new EnemyGenerator();
}


Kerker::~Kerker()
{
	for (Laag* l : lagen) {
		delete l;
		l = nullptr;
	}
	lagen.clear();

	delete eg;
	eg = nullptr;
}

void Kerker::init() {
	int laagGrootte = laagAfmeting;
	int ruimte;

	RoomGenerator* roomGenerator = new RoomGenerator();

	//generaar lagen
	for (int i = 0; i < aantalLagen; i++) {
		Laag* laag1 = new Laag();
		lagen.push_back(laag1);
	}

	//genereer random ruimtes voor iedere laag1
	for (int i = 0; i < lagen.size(); i++) {
		lagen[i]->init();

		std::vector<std::vector<Ruimte*>*> ruimtes = std::vector<std::vector<Ruimte*>*>();
		for (int j = 0; j < laagGrootte; j++) {
			std::vector<Ruimte*>* binnenVector = new std::vector<Ruimte*>();

			for (int k = 0; k < laagGrootte; k++) {
				Ruimte* r = roomGenerator->createRoom();
				//enemies toevoegen
				int kansBevatEnemies = rand() % 2;
				if (kansBevatEnemies == 1) {
					r->addEnemy(eg->createEnemy(i, i + 2));
				}

				r->xCoord = k;
				r->yCoord = j;
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

		int randX = rand() % laagGrootte;
		int randY = rand() % laagGrootte;
		Ruimte* begin = ruimtes[randX][0][randY];
		if (i == 0) {
			//startlocatie
			//lagen[i]->
			lagen[i]->setStartRoom(begin);
		}
		else {
			//trap omhoog
			begin->trapOmhoog = true;

			//trap omlaag
			lagen[i - 1]->getRuimtes()[0][randX][0][randY]->trapOmlaag = true;
		}

		randX = rand() % laagGrootte;
		randY = rand() % laagGrootte;
		Ruimte* eind = ruimtes[randX][0][randY];
		if (i == lagen.size()) {
			//eindvijand
			eind->eindbaas = true;
		}
	}

	Laag* laag = lagen[0];
	Ruimte* r = laag->getStartRoom();
	Held::getInstance().moveTo(r);

	huidigeLaag = laag;

	delete roomGenerator;
}

void Kerker::showMap() {
	std::cout << "Kerkerkaart:" << " niveau " << getNiveau() + 1 << "\n"; //niveau diepte
	std::cout << huidigeLaag->getMap();
	std::cout << "Legenda: \n";
	std::cout << "|- : Gangen \n";
	std::cout << "S  : Startlocatie \n";
	std::cout << "X  : Huidige locatie \n";
	std::cout << "E  : Eindvijand \n";
	std::cout << "N  : Normale ruimte \n";
	std::cout << "L  : Trap omlaag\n";
	std::cout << "H  : Trap omhoog \n";
	std::cout << ".  : Onbekend\n";
}

int Kerker::getNiveau()
{
	int pos = std::find(lagen.begin(), lagen.end(), huidigeLaag) - lagen.begin();
	return pos;
}
