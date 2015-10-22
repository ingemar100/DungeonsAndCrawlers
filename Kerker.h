#pragma once
#include <vector>
#include "Laag.h"

class Kerker
{
public:
	Kerker();
	~Kerker();
	void init();
	void showMap();
private:
	std::vector<Laag*> lagen;
	Laag* huidigeLaag = nullptr;
	void slaOp();
	void laad();
};

