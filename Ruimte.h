#pragma once

#include <vector>
#include "Spul.h"
#include "Val.h"
#include <map>

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
	std::string getStringFromEnum(Formaat waarde);
	std::string getStringFromEnum(Ordelijkheid waarde);
	std::string getStringFromEnum(Meubels waarde);
	std::string getStringFromEnum(Verlichting waarde);
	std::string getStringFromEnum(Opbergruimte waarde);
	std::string getStringFromEnum(Versiering waarde);
	std::string getStringFromEnum(Temperatuur waarde);
};

