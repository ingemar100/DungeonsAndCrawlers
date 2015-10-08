#pragma once
#include <vector>
#include "Ruimte.h"

class Laag
{
public:
	Laag();
	~Laag();
private:
	std::vector<Ruimte> ruimtes;
};

