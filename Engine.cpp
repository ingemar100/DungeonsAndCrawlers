#include "Engine.h"
#include "Held.h"
#include <iostream>
#include "Dialogue.h"

Engine::Engine()
{
	kerker = new Kerker();
}


Engine::~Engine()
{
	delete kerker;
}

void Engine::gameLoop() {

	// declare arrays 
	// declare variables
	// print introduction and instructions to console
	intro();
	setUp();

	// set location to first room

	// begin game loop
	while (playing) {

		// if health <=0 print death message, break from game loop	
		if (!Held::getInstance().isAlive()) {
			death();
		}
		playGame();
		// print success message
		//std::cout << "hallo\n";
	}
	// end

}

void Engine::intro() {
	std::vector<std::string> names = {"Harrison Ford", "Kunta Kinte", "Avonturier", "Karel de Grote", "Gengis Khan", "Cristopher Columbus", "Julius Caesar", "Drakenslachter", "Jeroen", "Bart Gelens"};
	Dialogue dialoog("Wat is je naam?", { names });
	int keuze = dialoog.activate();

	if (keuze == 0) {
		endGame();
		return;
	}
	else {
		std::string nieuweNaam = names[keuze - 1];
		Held::getInstance().setNaam(nieuweNaam);
		std::cout << "\nWelkom " + Held::getInstance().getNaam() + "\n\n";
	}

	std::cout << "Dungeons and crawlers heeft de mogelijkheid om de grootte van de kerker in te stellen. Hoeveel lagen wil je? Voer een getal in tussen 0 en 11 \n";
	int userInput = -1;
	while (true)
	{
		std::cin >> userInput;
		if (userInput > 0 && userInput <= 10)
		{
			kerker->aantalLagen = userInput;
			break;
		}
	}
	std::cout << "De kerker zal " << userInput << " lagen hebben. Hoe groot moeten de lagen zijn? Voor een getal is tussen 1 en 11 (dit is de breedte en lengte van de laag)\n";
	userInput = -1;
	while (true)
	{
		std::cin >> userInput;
		if (userInput > 1 && userInput <= 10)
		{
			kerker->laagAfmeting = userInput;
			break;
		}
	}
}

void Engine::death() {
	std::cout << "Jammer, je bent dood";
	//dialoog met opnieuw beginnen of spel beeindigen
}

void Engine::playGame() {
	Dialogue dialoog( "Kies een optie: ", { "Vecht", "Vlucht", "Zoek", "Rust uit", "Bekijk spullen", "Toon kaart", "Status" });

	if (Held::getInstance().getRuimte()->heeftTrapOmlaag() || Held::getInstance().getRuimte()->heeftTrapOmhoog()) {
		dialoog.addChoice("Neem de trap");
	}

	int gekozenOptie = dialoog.activate();

	if (gekozenOptie == 1) {
		Enemy* enemy = Held::getInstance().getRuimte()->getEnemy();		
		if (Held::getInstance().getRuimte()->hasEnemy()) {
			std::cout << "\n" + Held::getInstance().getNaam() + " valt " + enemy->getName() + " aan\n";
			if (!enemy->hit(Held::getInstance().getAanval())) {
				Held::getInstance().getRuimte()->destroyEnemy();
			}
			else {
				std::cout << "\n" + enemy->getName() + " valt " + Held::getInstance().getNaam() + " aan\n";
				Held::getInstance().hit(enemy->getAanval());
			}
		}
		else {
			std::cout << "\n Er zijn geen enemies meer aanwezig. \n";
		}
	}
	else if (gekozenOptie == 2) {
		vlucht();
	}
	else if (gekozenOptie == 3) {
		GameObject* go = (Held::getInstance().getRuimte()->search());
		if (go != nullptr) {
			Held::getInstance().getRuimte()->removeObject();
			Held::getInstance().addToInventory(go);
		}
	}
	else if (gekozenOptie == 4) {
	}
	else if (gekozenOptie == 5) {
		showInventory();
	}
	else if (gekozenOptie == 6) {
		kerker->showMap();
	}
	else if (gekozenOptie == 7) {
		Held::getInstance().showStatus();
	}
	else if (gekozenOptie == 8) { //neem trap
		neemTrap();
	}
	else if (gekozenOptie == 0) {
		endGame();
	}
}

void Engine::setUp() {
	kerker->init();
}

void Engine::endGame()
{
	Dialogue confirmation ("Wil je het spel beeindigen?", { "Ja", "Nee" });
	int actie = confirmation.activate();
	if (actie == 1) {
		playing = false;
	}
}

void Engine::vlucht()
{
	std::map<std::string, Ruimte*> adjacentRooms = Held::getInstance().getRuimte()->getAdjacentRooms();
	std::vector<std::string> richtingen = std::vector<std::string>();
	
	for (auto e : adjacentRooms) {
		richtingen.push_back(e.first);
	}

	Dialogue dialoog("Welke richting?", { richtingen });

	int gekozenOptie = dialoog.activate();

	Ruimte* doel = adjacentRooms[richtingen[gekozenOptie - 1]];
	Held::getInstance().moveTo(doel);
}

void Engine::showInventory()
{
	std::vector<GameObject*> go = Held::getInstance().getInventory();
	std::vector<std::string> opties;
	if (go.size() == 0) {
		std::cout << " \nJe Inventory is leeg. Doorzoek kamers om spullen te vinden.\n";
	}
	else {
		for (GameObject* gobject : go) {
			if (Held::getInstance().getWapenInGebruik() == gobject || Held::getInstance().getKledingInGebruik() == gobject) {
				opties.push_back(gobject->naam() + " (in gebruik) ");
			}
			else {
				opties.push_back(gobject->naam());
			}
		}
		opties.push_back("Annuleren");
		Dialogue inventoryDialoog("De volgende spullen zijn in je inventory te vinden. Kies welk item je wilt gebruiken: ", { opties });
		int inventoryKeuze = inventoryDialoog.activate();
		if (inventoryKeuze != 0 && inventoryKeuze != opties.size()) { //annuleren
			go[inventoryKeuze - 1]->use();
		}
	}
}

void Engine::neemTrap()
{
	int niveau = kerker->getNiveau();
	auto lagen = kerker->getLagen();
	Laag* nieuweLaag = lagen[niveau];
	if (Held::getInstance().getRuimte()->heeftTrapOmhoog() && Held::getInstance().getRuimte()->heeftTrapOmlaag()) {
		//welke
	}
	else if (Held::getInstance().getRuimte()->heeftTrapOmhoog()) {
		nieuweLaag = lagen[niveau - 1];
	}
	else {
		nieuweLaag = lagen[niveau + 1];
	}

	Ruimte* nieuw = nieuweLaag->getRuimtes()[0][Held::getInstance().getRuimte()->yCoord][0][Held::getInstance().getRuimte()->xCoord];
	Held::getInstance().moveTo(nieuw);
	kerker->setHuidigeLaag(nieuweLaag);
}
