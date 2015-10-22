#pragma once

#include <vector>
#include "Spul.h"
#include "Val.h"

class Ruimte
{
public:
	Ruimte();
	~Ruimte();
	static enum Formaat {KLEIN, MIDDEL, GROOT};
	static enum Ordelijkheid { SMERIG, SCHOON, STOFFIG };
	static enum Meubels { TAFEL, BED, GEEN_MEUBELS};
	static enum Verlichting { KAARS, FAKKEL, HAARDVUUR, KROONLUCHTER};
	static enum Opbergruimte { KIST, BOEKENKAST, GEEN_OPBERGRUIMTE };
	static enum Versiering { SCHILDERIJ, TAPIJT, TROFEE, GEEN_VERSIERING};
	static enum Temperatuur { WARM, IJSKOUD, KOEL};
	std::string getBeschrijving();
	void fillRandomly();
	std::string getMapTile();
private:
	Formaat formaat;
	Ordelijkheid ordelijkheid;
	Meubels meubels;
	Verlichting verlichting;
	Opbergruimte opbergruimte;
	Versiering versiering;
	Temperatuur temperatuur;
	Val val;
	std::vector<Spul> spullen;
};

