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
	setUp();
	bool running = true;


	// print introduction and instructions to console
	intro();
	// set location to first room

	// begin game loop
	while (true) {



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
	std::vector<std::string> names = {"Rood", "Blauw", "Adventurier", "Karel de Grote", "Gengis Khan", "Cristopher Columbus", "Harrison Ford", "Drakenslachter", "Jeroen", "Bart Gelens"};
	Dialogue dialoog("Wat is je naam?", { names });
	int keuze = dialoog.activate();

	std::string nieuweNaam = names[keuze - 1];
	Held::getInstance().setNaam(nieuweNaam);
	std::cout << "\nWelkom " + Held::getInstance().getNaam() + "\n";
}

void Engine::death() {
	std::cout << "Jammer, je bent dood";
	//reset
}

void Engine::playGame() {
	Dialogue dialoog(Held::getInstance().getRuimte()->getBeschrijving(), { "Vecht", "Bekijk", "Vlucht", "Toon kaart" });
	
	int gekozenOptie = dialoog.activate();

	if (gekozenOptie == 1) {
		std::cout << "\n" + Held::getInstance().getNaam() + " valt rat aan\n";
	}
	else if (gekozenOptie == 2) {
		GameObject* go = (Held::getInstance().getRuimte()->search());
		if (go != nullptr) {
			Held::getInstance().getRuimte()->removeObject();
		}
	}
	else if (gekozenOptie == 3) {
		std::cout << "\n" + Held::getInstance().getNaam() + " valt rat aan\n";
	}
	else if (gekozenOptie == 4) {
		kerker->showMap();
	}
	//display options
	//receive input

	//if option

}

void Engine::setUp() {
	kerker->init();
}