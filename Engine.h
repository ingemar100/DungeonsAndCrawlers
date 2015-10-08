#pragma once
#include "Held.h"

class Engine
{
public:
	Engine();
	~Engine();
	void gameLoop();

private:
	Held held;
	void intro();
	void death();
};

