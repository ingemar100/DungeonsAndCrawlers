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
	Held* held;
	Kerker* kerker;
	void intro();
	void death();
	void playGame();
	void setUp();
};

