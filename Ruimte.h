#pragma once

#include <vector>
#include "Spul.h"
#include "Val.h"

class Ruimte
{
public:
	Ruimte();
	~Ruimte();
	enum formaat {KLEIN, MIDDEL, GROOT};
	enum ordelijkheid {SMERIG, SCHOON};
	enum meubels { TAFEL, BED, LEEG};
	enum verlichting { KAARS, FAKKEL, HAARDVUUR};
private:
	formaat grootte;
	ordelijkheid orde;
	meubels meubilair;
	verlichting licht;
	Val val;
	std::vector<Spul> spullen;
};

