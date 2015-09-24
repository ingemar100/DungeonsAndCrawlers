#pragma once
#include <string>

class Spul
{
public:
	static enum spulSoort{ DRANK, ETEN, WAPEN, KLEDING };
	Spul(std::string _naam, spulSoort _soort, int _kracht);
	~Spul();
private:
	std::string naam;
	spulSoort soort;
	int kracht;
};

