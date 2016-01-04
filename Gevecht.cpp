#include "Gevecht.h"



Gevecht::Gevecht(Ruimte* r)
{
	ruimte = r;
}


Gevecht::~Gevecht()
{
}

void Gevecht::start() {
	fighting = true;
	if (ruimte->hasEindbaas()) {
		//dialoog
		std::cout << "Je ziet een kapot enge eindbaas enzo";
	}
	while (fighting && Held::getInstance().isAlive()) {
		playTurn();
	}

	if (ruimte->hasEindbaas() && Held::getInstance().isAlive() && !ruimte->hasEnemy()) {
		//dialoog en spel gewonnen
		std::cout << "Gefeliciteerd, je hebt de eindbaas verslagen. Je hebt het spel gewonnen.";
	}
}

void Gevecht::playTurn()
{
	//aanvallen, vluchten, item gebruiken
	Dialogue dia("Kies een optie: ", { "Val aan", "Vlucht", "Gebruik item" });
	int keuze = dia.activate();

	if (keuze == 0) {
		//doe niks
	}
	else if (keuze == 1) {
		//welke vijand
		std::vector<Enemy*> aanwezig = ruimte->getEnemies();
		std::vector<std::string> opties;
		for (auto enemy : aanwezig) {
			opties.push_back(enemy->getName() + " (aanval: " + std::to_string(enemy->getAanval()) + ", verd.: " + std::to_string(enemy->getVerdediging()) + ", levensp.: " + std::to_string(enemy->getLevenspunten()) + ")"); 
		}
		Dialogue vijandKeuze("Welke vijand?", opties);
		int keuze = vijandKeuze.activate();
		if (keuze == 0) {
			return;
		}
		int vijand = keuze - 1;

		Enemy* enemy = aanwezig[vijand];
		std::cout << "\n" + Held::getInstance().getNaam() + " valt " + enemy->getName() + " aan...\n";
		if (!enemy->hit(Held::getInstance().getAanval())) {
			Held::getInstance().getRuimte()->destroyEnemy(enemy);
			fighting = ruimte->hasEnemy();
		}
	}
	else if (keuze == 2) {
		//vlucht
		if (Held::getInstance().vlucht()) {
			fighting = false;
		}
		return;
	}
	else if (keuze == 3) {
		//toon inventory
		Held::getInstance().showInventory();
	}

	//enemy doet actie
	for (Enemy* enemy : ruimte->getEnemies()) {
		enemy->doeActie();
	}
}
