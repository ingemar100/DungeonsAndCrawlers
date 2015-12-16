#include "Engine.h"
#include "Held.h"
#include <iostream>


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
	std::cout << "Wat is je naam?\nNaam: ";

	std::string nieuweNaam;
	std::getline(std::cin, nieuweNaam);
	Held::getInstance().setNaam(nieuweNaam);
	std::cout << "\nWelkom " + Held::getInstance().getNaam() + "\n";
}

void Engine::death() {
	std::cout << "Jammer, je bent dood";
}

void Engine::playGame() {
	std::cout << Held::getInstance().getRuimte()->getBeschrijving() + "\n";
	std::cout << "\nJe hebt deze opties: Vecht, Bekijk, Vlucht, Toon kaart \nOptie: ";
	std::string gekozenOptie;

	std::cin >> gekozenOptie;

	if (gekozenOptie == "vecht") {
		std::cout << "\n" + Held::getInstance().getNaam() + " valt rat aan\n";
	}
	if (gekozenOptie == "toonkaart") {
		kerker->showMap();
	}
	//display options
	//receive input

	//if option

}

void Engine::setUp() {
	kerker->init();
}