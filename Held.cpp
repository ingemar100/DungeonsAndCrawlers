#include "Held.h"
#include <string>
#include <vector>


Held::Held(std::string _naam)
{
	naam = _naam;
	level = 1;
	levenspunten = 1;
	ervaringspunten = 1;
	aanval = 1;
	verdediging = 1;
	opmerkzaamheid = 1;
	spullen = {};
}


Held::~Held()
{
}
