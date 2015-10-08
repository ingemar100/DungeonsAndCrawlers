#include "Engine.h"
#include "Held.h"
#include <iostream>


Engine::Engine()
{
	held = new Held();
	kerker = new Kerker();
}


Engine::~Engine()
{
	delete held;
	delete kerker;
}

void Engine::gameLoop() {

	// declare arrays 
	// declare variables
	
	bool running = true;


	// print introduction and instructions to console
	intro();
	// set location to first room

	// begin game loop
	while (true) {



		// if health <=0 print death message, break from game loop	
		if (!held->isAlive()) {
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
	held->setNaam(nieuweNaam);
	std::cout << "\nWelkom " + held->getNaam() + "\n";
}

void Engine::death() {
	std::cout << "Jammer, je bent dood";
}

void Engine::playGame() {
	std::cout << "\nJe hebt deze opties: Vecht, Bekijk, Vlucht \nOptie: ";
	std::string gekozenOptie;

	std::cin >> gekozenOptie;

	if (gekozenOptie == "vecht") {
		std::cout << "\n" + held->getNaam() + " valt rat aan\n";
	}
	//display options
	//receive input

	//if option

}