#include "Engine.h"
#include "Held.h"
#include <iostream>


Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::gameLoop() {

	// declare arrays 
	// declare variables
	
	held = Held();
	bool running = true;


	// print introduction and instructions to console
	intro();
	// set location to first room

	// begin game loop
	while (true) {



		// if health <=0 print death message, break from game loop	
		if (!held.isAlive()) {
			death();
		}


		// print success message
		//std::cout << "hallo\n";

	}
	// end

}

void Engine::intro() {
	std::cout << "Wat is je naam?\nNaam: ";

	std::string nieuweNaam;
	std::getline(std::cin, nieuweNaam);
	held.setNaam(nieuweNaam);
	std::cout << "\nWelkom " + held.getNaam() + "\n";
}

void Engine::death() {

}