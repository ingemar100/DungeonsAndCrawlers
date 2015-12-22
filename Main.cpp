#include "Engine.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <time.h>

int main(int argc, char* args[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	Engine* engine = new Engine();

	engine->gameLoop();

	delete engine;
	Held::deleteInstance();
	return 0;
}