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
	while (fighting && Held::getInstance().isAlive()) {
		playTurn();
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
		Enemy* enemy = ruimte->getEnemy();
		std::cout << "\n" + Held::getInstance().getNaam() + " valt " + enemy->getName() + " aan\n";
		if (!enemy->hit(Held::getInstance().getAanval())) {
			Held::getInstance().getRuimte()->destroyEnemy();
			fighting = false;
			return;	//einde gevecht
		}
	}
	else if (keuze == 2) {
		//vlucht
		Held::getInstance().vlucht();
		fighting = false;
		return;
	}
	else if (keuze == 3) {
		//toon inventory
		Held::getInstance().showInventory();
	}

	//enemy doet actie
	Enemy* enemy = ruimte->getEnemy();
	enemy->doeActie();
}
