#include "Engine.h"
#include "Held.h"
#include <iostream>
#include "Dialogue.h"
#include "Gevecht.h"

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
	Dialogue dialoog( "Kies een optie: ", { "Vecht", "Verplaats", "Zoek", "Rust uit", "Bekijk spullen", "Toon kaart", "Status" });

	if (Held::getInstance().getRuimte()->heeftTrapOmlaag() || Held::getInstance().getRuimte()->heeftTrapOmhoog()) {
		dialoog.addChoice("Neem de trap");
	}

	int gekozenOptie = dialoog.activate();

	if (gekozenOptie == 1) {
		if (Held::getInstance().getRuimte()->hasEnemy()) {
			Gevecht* g = new Gevecht(Held::getInstance().getRuimte());
			g->start();

			delete g;
		}
		else {
			std::cout << "\nEr zijn geen vijanden aanwezig. \n";
		}
	}
	else if (gekozenOptie == 2) {
		Held::getInstance().vlucht();
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
		Held::getInstance().showInventory();
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

void Engine::neemTrap()
{
	int niveau = kerker->getNiveau();
	auto lagen = kerker->getLagen();
	Laag* nieuweLaag = lagen[niveau];
	if (Held::getInstance().getRuimte()->heeftTrapOmhoog() && Held::getInstance().getRuimte()->heeftTrapOmlaag()) {
		Dialogue trap("Welke trap?", { "Omhoog", "Omlaag" });
		int w = trap.activate();
		if (w == 1) {
			nieuweLaag = lagen[niveau - 1];
		}
		else if (w == 2) {
			nieuweLaag = lagen[niveau + 1];
		}
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
