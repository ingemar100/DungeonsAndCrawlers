#pragma once
#include "Held.h"
#include "Kerker.h"

class Engine
{
public:
	Engine();
	~Engine();
	void gameLoop();

private:
	bool playing = true;
	Kerker* kerker;
	void intro();
	void death();
	void playGame();
	void setUp();
	void endGame();
	void vlucht();
	void showInventory();
	void neemTrap();
};

